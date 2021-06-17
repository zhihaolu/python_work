using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SnipTool1
{
    public partial class Form1 : Form
    {
        int x, y;
        Graphics gForm;

        public Form1()
        {
            InitializeComponent();
        }

        private void snipToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // 开始新的截图
            this.WindowState = FormWindowState.Maximized;

        }

        private void exitToolStripMenuItem_Click(object sender, EventArgs e)
        {
            // 退出小工具
            Application.Exit();
        }

        private void Form1_MouseClick(object sender, MouseEventArgs e)
        {

        }

        private void notifyIcon1_MouseClick(object sender, MouseEventArgs e)
        {
            contextMenuStrip1.Show(Cursor.Position);
        }

        private void Form1_MouseDown(object sender, MouseEventArgs e)
        {
            x = e.X;
            y = e.Y;
        }

        private void Form1_MouseMove(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                int startX = x, startY = y, endX = e.X, endY = e.Y, temp;
                if(startX > endX)
                {
                    temp = startX;
                    startX = endX;
                    endX = temp;
                }
                if(startY > endY)
                {
                    temp = startY;
                    startY = endY;
                    endY = temp;
                }
                Graphics g = this.CreateGraphics();
                g.Clear(this.BackColor);
                if (startX != endX && startY != endY)
                {
                    // 实时显示截取的屏幕图像让用户预览截图内容
                    gForm.CopyFromScreen(startX, startY, startX, startY, new Size(endX - startX, endY - startY));
                    // 画红框，让用户看清截图区域
                    g.DrawRectangle(Pens.Red, startX, startY, endX - startX, endY - startY);
                }
            }

        }

        private void Form1_MouseUp(object sender, MouseEventArgs e)
        {
            if(e.Button == MouseButtons.Left)
            {
                int startX = x, startY = y, endX = e.X, endY = e.Y, temp;
                if(startX == endX || startY == endY)
                {
                    this.WindowState = FormWindowState.Minimized;
                    return;
                }
                if (startX > endX)
                {
                    temp = startX;
                    startX = endX;
                    endX = temp;
                }
                if (startY > endY)
                {
                    temp = startY;
                    startY = endY;
                    endY = temp;
                }
                Size s = new Size(endX - startX, endY - startY);
                this.WindowState = FormWindowState.Minimized;
                using(Bitmap bmp = new Bitmap(s.Width, s.Height))
                {
                    Graphics g = Graphics.FromImage(bmp);
                    g.CopyFromScreen(startX, startY, 0, 0, s);
                    if (autoSaveToolStripMenuItem.Checked)
                    {
                        string filename = string.Format(@"d:\截图{0}.png", DateTime.Now.ToString("yyyyMMddHHmmss"));
                        bmp.Save(filename, System.Drawing.Imaging.ImageFormat.Png);
                        System.Diagnostics.Process.Start(filename);
                    }
                    Clipboard.SetImage(bmp);
                    
                }
            }
            else
            {
                this.WindowState = FormWindowState.Minimized;
            }
        }

        private void autoSaveToolStripMenuItem_Click(object sender, EventArgs e)
        {
            autoSaveToolStripMenuItem.Checked = !autoSaveToolStripMenuItem.Checked;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            // 窗体初始化
            this.Text = "";
            this.ControlBox = false;
            this.FormBorderStyle = FormBorderStyle.None;
            this.Opacity = 0.5;
            this.WindowState = FormWindowState.Maximized;
            gForm = this.CreateGraphics();
        }
    }
}
