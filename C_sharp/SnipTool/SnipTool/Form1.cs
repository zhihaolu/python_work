using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace SnipTool
{
    public partial class Form1 : Form
    {
        int x, y;
        Graphics gFrom;
        public Form1()
        {
            InitializeComponent();
        }

        private void 截图ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            this.WindowState = FormWindowState.Maximized;
        }

        private void 退出ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            Application.Exit();
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
            if(e.Button == MouseButtons.Left)
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
                /*
                Graphics g = this.CreateGraphics();
                g.Clear(this.BackColor);
                if(startX != endX && startY != endY)
                {
                    g.DrawRectangle(Pens.Red, startX, startY, endX - startX, endY - startY);
                }
                */
                
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
                    if (保存ToolStripMenuItem.Checked)
                    {
                        string filename = string.Format(@"d:\截图{0}.png", DateTime.Now.ToString("yyyyMMddHHmmss"));
                        bmp.Save(filename, System.Drawing.Imaging.ImageFormat.Png);
                        System.Diagnostics.Process.Start(filename);
                    }
                  
                    Clipboard.SetImage(bmp);   // 复制到剪贴板
                }
            }
            else
            {
                this.WindowState = FormWindowState.Minimized;
            }
        }

        private void Form1_KeyUp(object sender, KeyEventArgs e)
        {
            if ( e.KeyCode == Keys.Escape)
            {
                this.WindowState = FormWindowState.Minimized;
            }
        }

        private void 保存ToolStripMenuItem_Click(object sender, EventArgs e)
        {
            保存ToolStripMenuItem.Checked = !保存ToolStripMenuItem.Checked;
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.Text = "";
            this.ControlBox = false;
            this.FormBorderStyle = FormBorderStyle.None;
            this.Opacity = 0.5;
            this.WindowState = FormWindowState.Maximized;
            gFrom = this.CreateGraphics();
        }
    }
}
