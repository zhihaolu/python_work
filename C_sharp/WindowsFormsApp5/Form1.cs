using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace WindowsFormsApp5
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void radioButton1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void comboBox1_SelectedIndexChanged(object sender, EventArgs e)
        {
            zhuanye.Items.Clear();
            if (xueyuan.Text == "信息院")
                zhuanye.Items.AddRange(new string[] { "计算机", "软件工程", "物联网", "大数据" });
            else if (xueyuan.Text == "外语院")
                zhuanye.Items.AddRange(new string[] { "英语", "法语", "日语" });
        }

        private void checkBox3_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void radioButton4_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void trackBar1_Scroll(object sender, EventArgs e)
        {
            lbl.Text = trackBar1.Value + "%";
        }

        private void timer1_Tick(object sender, EventArgs e)
        {
            label14.Left -= 10;
            if (label14.Right < 0) label14.Left = panelbl.Right;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            label14.Left = panelbl.Right;
            timer1.Enabled = true;
        }

        private void button1_Click(object sender, EventArgs e)
        {
            Form frm = new Form();
            frm.ShowDialog();
        }

        private void button2_Click(object sender, EventArgs e)
        {
            Form frm = new Form();
            frm.Show();
        }
    }
}
