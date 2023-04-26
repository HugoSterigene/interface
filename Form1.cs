using System;
using System.Diagnostics;
using System.Windows.Forms;
using System.Runtime.InteropServices;
using System.Collections.Generic;
using System.Linq;

namespace Oskeyboard
{
	public partial class Form1 : Form
	{
		public const int WM_NCLBUTTONDOWN = 0xA1;
		public const int HT_CAPTION = 0x2;
		

		[DllImportAttribute("user32.dll")]
		public static extern int SendMessage(IntPtr hWnd,
						 int Msg, int wParam, int lParam);
		[DllImportAttribute("user32.dll")]
		public static extern bool ReleaseCapture();
		protected override CreateParams CreateParams
		{
			get
			{
				CreateParams param = base.CreateParams;
				param.ExStyle |= 0x08000000;
				return param;
			}
		}

		public Form1()
		{
			InitializeComponent();
			this.Visible=true;
        }
		private void checkBox1_CheckedChanged_1(object sender, EventArgs e)
		{
			TextBox tb = (TextBox)this.Controls[textBoxName];
			tb.AppendText("\t");
		}


		private void button67_Click(object sender, EventArgs e)
		{
			SendKeys.Send("{ENTER}");
			TextBox select = (TextBox)this.Controls[textBoxName];
			if(select.Name == "username")
			{
				this.username = select.Text;
				System.Console.WriteLine(this.username);
			}
			else if(select.Name == "password")
			{
				this.password = select.Text;
				System.Console.WriteLine(this.password);
			}
			select.DeselectAll();
			panel1.Visible = false;
		}


		private void capslock_CheckedChanged(object sender, EventArgs e)
		{
			if (capslock.Checked == true)
			{
				capslock.BackColor = System.Drawing.ColorTranslator.FromHtml("#0076D7");
			}
			else
				capslock.BackColor = System.Drawing.ColorTranslator.FromHtml("#333333");
		}
		
		private void button91_Click(object sender, EventArgs e)
		{
			SendKeys.Send("+({F10})");
		}

		private void Form1_Load(object sender, EventArgs e)
		{
			passBox.Focus();
		}
		
		private void lshift_CheckedChanged(object sender, EventArgs e)
		{
			rshift.Checked = lshift.Checked;
			if (lshift.Checked == true)
			{
				lshift.BackColor = System.Drawing.ColorTranslator.FromHtml("#0076D7");
				rshift.BackColor = System.Drawing.ColorTranslator.FromHtml("#0076D7");

			}
			else
			{
				lshift.BackColor = System.Drawing.ColorTranslator.FromHtml("#333333");
				rshift.BackColor = System.Drawing.ColorTranslator.FromHtml("#333333");
			}

		}

		private void rshift_CheckedChanged(object sender, EventArgs e)
		{
			lshift.Checked = rshift.Checked;
			if (rshift.Checked == true)
			{
				lshift.BackColor = System.Drawing.ColorTranslator.FromHtml("#0076D7");
				lshift.ForeColor = System.Drawing.ColorTranslator.FromHtml("#FFFFFF");

				rshift.BackColor = System.Drawing.ColorTranslator.FromHtml("#0076D7");
				rshift.ForeColor = System.Drawing.ColorTranslator.FromHtml("#FFFFFF");
			}
		}

		private void button92_Click(object sender, EventArgs e)
		{
			Close();
		}

		private void button94_Click(object sender, EventArgs e)
		{
			WindowState = FormWindowState.Minimized;
		}

		private void Form1_MouseDown(object sender, MouseEventArgs e)
		{
			if (e.Button == MouseButtons.Left)
			{
				ReleaseCapture();
				SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
			}
		}

		private void openToolStripMenuItem_Click(object sender, EventArgs e)
		{
			WindowState = FormWindowState.Maximized;
		}

		private void exitToolStripMenuItem_Click(object sender, EventArgs e)
		{
			Close();
		}
		private void setupCustomKeysToolStripMenuItem_Click(object sender, EventArgs e)
		{
			CustomKeyBuilder myKeys = new CustomKeyBuilder();
			myKeys.ShowDialog();
		}

		

		private void button93_Click(object sender, EventArgs e)
		{
			SendKeys.Send("{BACKSPACE}");
			TextBox tb = (TextBox)this.Controls[textBoxName];
			tb.Text = tb.Text.Substring(0,tb.Text.Length - 1);
		}

        private void groupBox1_Enter(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }

        private void passBox_TextChanged(object sender, EventArgs e)
        {
			
        }

        private void TextBox1_TextChanged(object sender, EventArgs e)
        {
			
        }


		private void TextBox_Selected(object sender, EventArgs e)
		{
            panel1.Visible = true;
            string tb = ((TextBox)sender).Name;

			if(textBoxName != tb)
			{
				textBoxName = tb;
			}
			TextBox select = (TextBox) this.Controls[textBoxName];
			select.Clear();
			select.Select();

		}

        private void KeyboardButton_Click(object sender, EventArgs e)
        {
            // Récupération de la lettre ou du caractère correspondant au bouton cliqué sur votre clavier virtuel
            Button button = (Button)sender;
			string character;
			TextBox outTB = (TextBox)this.Controls[textBoxName];
			char res;
            if (lshift.Checked || rshift.Checked || (capslock.Checked == true))
            {
				character = button.Text;
				res = character[0];
				
                lshift.Checked = false;
                rshift.Checked = false;
            }
            else
            {
                character = button.Text;
				if (character.Length == 1)
				{
					// In case we are treating with letters, putting them by default in lower case.
					res = char.ToLower(character[0]);
				}
				else
				{
					res = character[character.Length - 1];
				}
            }

            // Ajout de la lettre ou du caractère au champ de texte
            outTB.Text += res;
        }

        private void passBox_TextChanged_1(object sender, EventArgs e)
        {

        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {

        }
    }
}

