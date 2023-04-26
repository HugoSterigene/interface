using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace Oskeyboard
{
	public partial class CustomKeyBuilder : Form
	{
		public CustomKeyBuilder()
		{
			InitializeComponent();
		}

		private void button1_Click(object sender, EventArgs e)
		{
			Close();
		}

		private void checkBox1_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox1, textCustom1);
		}
		private void ManageCustomKey(CheckBox CB, TextBox TxtBx)
		{
			if (CB.Checked == true)
			{
				TxtBx.Enabled = true;
			}else
			{
				TxtBx.Enabled = false;
			}
		}

		private void checkBox2_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox2, textCustom2);
		}

		private void checkBox3_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox3, textCustom3);
		}

		private void checkBox4_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox4, textCustom4);
		}

		private void checkBox5_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox5, textCustom5);
		}

		private void checkBox10_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox10, textCustom10);
		}

		private void checkBox9_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox9, textCustom9);
		}

		private void checkBox8_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox8, textCustom8);
		}

		private void checkBox7_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox7, textCustom7);
		}

		private void checkBox6_CheckedChanged(object sender, EventArgs e)
		{
			ManageCustomKey(checkBox6, textCustom6);
		}

		private void button67_Click(object sender, EventArgs e)
		{
			SaveButtons();
		}
		private void SaveButtons()
		{
			if (!String.IsNullOrEmpty(textCustom1.Text) && checkBox1.Checked == true)
			{
				Properties.Settings.Default.customkey1 = textCustom1.Text;
			}
			else
				Properties.Settings.Default.customkey1 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom2.Text) && checkBox2.Checked == true)
			{
				Properties.Settings.Default.customkey2 = textCustom2.Text;
			}
			else
				Properties.Settings.Default.customkey2 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom3.Text) && checkBox3.Checked == true)
			{
				Properties.Settings.Default.customkey3 = textCustom3.Text;
			}
			else
				Properties.Settings.Default.customkey3 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom4.Text) && checkBox4.Checked == true)
			{
				Properties.Settings.Default.customkey4 = textCustom4.Text;
			}
			else
				Properties.Settings.Default.customkey4 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom5.Text) && checkBox5.Checked == true)
			{
				Properties.Settings.Default.customkey5 = textCustom5.Text;
			}
			else
				Properties.Settings.Default.customkey5 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom6.Text) && checkBox6.Checked == true)
			{
				Properties.Settings.Default.customkey6 = textCustom6.Text;
			}
			else
				Properties.Settings.Default.customkey6 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom7.Text) && checkBox7.Checked == true)
			{
				Properties.Settings.Default.customkey7 = textCustom7.Text;
			}
			else
				Properties.Settings.Default.customkey7 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom8.Text) && checkBox8.Checked == true)
			{
				Properties.Settings.Default.customkey8 = textCustom8.Text;
			}
			else
				Properties.Settings.Default.customkey8 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom9.Text) && checkBox9.Checked == true)
			{
				Properties.Settings.Default.customkey9 = textCustom9.Text;
			}
			else
				Properties.Settings.Default.customkey9 = string.Empty;

			if (!String.IsNullOrEmpty(textCustom10.Text) && checkBox10.Checked == true)
			{
				Properties.Settings.Default.customkey10= textCustom10.Text;
			}
			else
				Properties.Settings.Default.customkey10 = string.Empty;

			Properties.Settings.Default.Save();
		}
		 private void LoadKeys()
		{
			checkBox1.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey1);
			textCustom1.Text = Properties.Settings.Default.customkey1;

			checkBox2.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey2);
			textCustom2.Text = Properties.Settings.Default.customkey2;

			checkBox3.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey3);
			textCustom3.Text = Properties.Settings.Default.customkey3;

			checkBox4.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey4);
			textCustom4.Text = Properties.Settings.Default.customkey4;

			checkBox5.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey5);
			textCustom5.Text = Properties.Settings.Default.customkey5;

			checkBox6.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey6);
			textCustom6.Text = Properties.Settings.Default.customkey6;

			checkBox7.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey7);
			textCustom7.Text = Properties.Settings.Default.customkey7;

			checkBox8.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey8);
			textCustom8.Text = Properties.Settings.Default.customkey8;

			checkBox9.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey9);
			textCustom9.Text = Properties.Settings.Default.customkey9;

			checkBox10.Checked = !String.IsNullOrEmpty(Properties.Settings.Default.customkey10);
			textCustom10.Text = Properties.Settings.Default.customkey10;


		}
		private void CustomKeyBuilder_Load(object sender, EventArgs e)
		{
			LoadKeys();
		}
	}
}
