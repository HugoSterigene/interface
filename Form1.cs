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

		/*
		 * Initialise the different component of the window and set the window to visible 
		 */
		public Form1()
		{
			InitializeComponent();
			this.Visible=true;
        }

		/*
		 * Function to handle the key tab on the virtual keyboard
		 */
		private void checkBox1_CheckedChanged_1(object sender, EventArgs e)
		{
			// tb is the textbox selected previously by the user
			TextBox tb = (TextBox)this.Controls[textBoxName];
			tb.AppendText("\t");
		}

		/*
		 * Function to handle the enter key on the virtual keyboard
		 */
		private void button67_Click(object sender, EventArgs e)
		{
			SendKeys.Send("{ENTER}");
			// select is the textbox selected by the user
			TextBox select = (TextBox)this.Controls[textBoxName];
			// We check if the text box is the username one
			if(select.Name == "username")
			{
				// we save the username in a variable to test it later
				this.username = select.Text;
			}
			// We check if the text box is the password one
			else if(select.Name == "password")
			{
				// we save the password to test it later
				this.password = select.Text;
			}
			// we deselect the text box to ensure we will not write in it without wanting to
			select.DeselectAll();
			// we set the visibility of the keyboard to false cause we don't need it anymore
			panel1.Visible = false;
		}

		/*
		 * Function to handle the capslock key
		 */
		private void capslock_CheckedChanged(object sender, EventArgs e)
		{
			// if capslock is enable we change it appearance
			if (capslock.Checked == true)
			{
				capslock.BackColor = System.Drawing.ColorTranslator.FromHtml("#0076D7");
			}
			else
				capslock.BackColor = System.Drawing.ColorTranslator.FromHtml("#333333");
		}


		/*
		 * Function to handle the left shift key
		 */
		private void lshift_CheckedChanged(object sender, EventArgs e)
		{
			// the right and left shift are synchronised
			rshift.Checked = lshift.Checked;
			// We modify the appearrance of the left and right shift depending of their status
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

		/*
		 * Function to handle the right shift key
		 */
		private void rshift_CheckedChanged(object sender, EventArgs e)
		{
			// the right and left shift are synchronised
			lshift.Checked = rshift.Checked;
			// We modify the appearrance of the left and right shift depending of their status
			if (rshift.Checked == true)
			{
				lshift.BackColor = System.Drawing.ColorTranslator.FromHtml("#0076D7");
				lshift.ForeColor = System.Drawing.ColorTranslator.FromHtml("#FFFFFF");

				rshift.BackColor = System.Drawing.ColorTranslator.FromHtml("#0076D7");
				rshift.ForeColor = System.Drawing.ColorTranslator.FromHtml("#FFFFFF");
			}
		}

		/*
		 * Function to handle the cross to close the window
		 */
		private void button92_Click(object sender, EventArgs e)
		{
			Close();
		}

		private void Form1_MouseDown(object sender, MouseEventArgs e)
		{
			if (e.Button == MouseButtons.Left)
			{
				ReleaseCapture();
				SendMessage(Handle, WM_NCLBUTTONDOWN, HT_CAPTION, 0);
			}
		}

		private void setupCustomKeysToolStripMenuItem_Click(object sender, EventArgs e)
		{
			CustomKeyBuilder myKeys = new CustomKeyBuilder();
			myKeys.ShowDialog();
		}

		
		/*
		 * Function to handle the backspace key 
		 */
		private void button93_Click(object sender, EventArgs e)
		{
			SendKeys.Send("{BACKSPACE}");
			// getting the selected textbox
			TextBox tb = (TextBox)this.Controls[textBoxName];
			// Writing the text in the textbox minus the last character
			tb.Text = tb.Text.Substring(0,tb.Text.Length - 1);
		}

        private void panel1_Paint(object sender, PaintEventArgs e)
        {

        }


		/*
		 * Function to set as selected the textbox the user last clicked on
		 */
		private void TextBox_Selected(object sender, EventArgs e)
		{
			// When the user click on a textbox the keyboard appear
            panel1.Visible = true;
			// We get the name of the textbox selected
            string tb = ((TextBox)sender).Name;

			// We change the global variable that indicate the name of the textbox selected
			textBoxName = tb;
			// We get the selected textbox
			TextBox select = (TextBox) this.Controls[textBoxName];
			// Clearing the textbox to be sure their will be no char left before the user type what he want
			select.Clear();
			// Setting the textbox status to selected
			select.Select();

		}

		/*
		 * Function to handle general keyboard key pressed
		 */
        private void KeyboardButton_Click(object sender, EventArgs e)
        {
            // Getting the button that has been pressed
            Button button = (Button)sender;
			string character;
			// getting the textbox where we will write in
			TextBox outTB = (TextBox)this.Controls[textBoxName];
			char res;
			// We verify if caps or shift are enabled
            if (lshift.Checked || rshift.Checked || (capslock.Checked == true))
            {
				// The keyboard is natively in upper case so we can write directly the key pressed
				character = button.Text;
				res = character[0];
				// Setting left and right shifts to false after one use
                lshift.Checked = false;
                rshift.Checked = false;
            }
            else
            {
				// We get the text of the key
                character = button.Text;
				// We verify if there is one or more possible action for the key
				if (character.Length == 1)
				{
					// In case we are treating with letters, putting them by default in lower case.
					res = char.ToLower(character[0]);
				}
				else
				{
					// the key last char is the second option so we get it
					res = character[character.Length - 1];
				}
            }

            // appending the char to the textbox
            outTB.Text += res;

        }

    }
}

