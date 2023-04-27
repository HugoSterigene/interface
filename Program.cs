using System;
using System.Collections.Generic;
using System.Linq;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Threading;

namespace Oskeyboard
{
    static class Program
    {
        public static void Application_main()
        {
            Application.Run(new Form1());
        }
        [STAThread]
        static void Main()
        {
            ThreadStart mainApp = new ThreadStart(Application_main);
            Application.EnableVisualStyles();
            Application.SetCompatibleTextRenderingDefault(false);
            Thread app = new Thread(mainApp);
            app.Start();
        }
    }
}
