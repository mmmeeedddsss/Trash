using System;
using System.Collections.Generic;
using System.Text;
using System.IO;

namespace Arge_Logger
{
    static class Writer
    {
        public static void write(object o, StreamWriter output, string from, bool showFrom = true)
        {
            if (output == null || o == null)
                return;
            if (showFrom)
                output.Write("{0}: {1}", from, o);
            else
                output.Write("{1}", o);
        }

        public static void write(object o, TextWriter output, string from)
        {
            if (output == null)
                return;
            output.Write("{0}: {1}", from, o);
        }
    }
}
