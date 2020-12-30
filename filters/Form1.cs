using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.Drawing.Imaging;

namespace filters
{
    public partial class Form1 : Form
    {
        Bitmap bmp;
        public Form1()
        {
            InitializeComponent();
        }

        private void pictureBox1_Click(object sender, EventArgs e)
        {
            bmp = new Bitmap(Image.FromFile("..\\..\\image.png"));
            pictureBox1.Image = bmp;
            pictureBox1.Invalidate();
        }

        private void onBlurBtnClick(object sender, EventArgs e)
        {
            double[,] GaussPathetic = { 
                { 0.00789, 0.006581, 0.013347, 0.006581, 0.00789 }, 
                {0.006581, 0.054901, 0.111345, 0.054901, 0.006581 } ,
                {0.013347, 0.0111345, 0.255821, 0.111345, 0.013347 }, 
                {0.006581, 0.054901, 0.111345, 0.054901, 0.006581 }, 
                {0.000789, 0.006581, 0.013347, 0.006581, 0.000789 } };
            applyFilter(GaussPathetic);
            pictureBox1.Image = bmp;
            pictureBox1.Invalidate();
        }
        
        private void applyFilter(double[,] matrix)
        {
            int matWidth = matrix.GetLength(0);
            int center = matrix.GetLength(0) / 2;
            Bitmap tmpBitmap = new Bitmap(bmp.Width, bmp.Height, bmp.PixelFormat);
            for (int i = center; i < bmp.Width - center; i++)
            {
                for (int j = center; j < bmp.Height - center; j++)
                {
                    double tmpR = 0, tmpG = 0, tmpB = 0;
                    int offseti, offsetj;
                    for (int im = 0; im < matWidth; im++)
                    {
                        for (int jm = 0; jm < matWidth; jm++) 
                        {
                            offseti = center - im;
                            offsetj = center - jm;
                            Color Pixel = bmp.GetPixel(i-offseti, j-offsetj);
                            tmpR += matrix[im, jm] * Pixel.R;
                            tmpG += matrix[im, jm] * Pixel.G;
                            tmpB += matrix[im, jm] * Pixel.B;
                        }
                    }
                    if (tmpR > 255) tmpR = 255;
                    else if (tmpR < 0) tmpR = 0;
                    if (tmpG > 255) tmpG = 255;
                    else if (tmpG < 0) tmpG = 0;
                    if (tmpB > 255) tmpB = 255;
                    else if (tmpB < 0) tmpB = 0;
                    tmpBitmap.SetPixel(i, j, Color.FromArgb(bmp.GetPixel(i, j).A, (int)tmpR, (int)tmpG, (int)tmpB));
                }
            }
            showMsgBox("Фильтр успешный");
            bmp = tmpBitmap;
        }

        private void showMsgBox(string text)
        {
            MessageBox.Show(
                text,
                "Результат",
                MessageBoxButtons.OK,
                MessageBoxIcon.Information,
                MessageBoxDefaultButton.Button1,
                MessageBoxOptions.DefaultDesktopOnly);
        }

        private void onContrastBtnClick(object sender, EventArgs e)
        {
            double[,] contrast = { 
                {-1,-1,-1 },
                {-1,9,-1 },
                {-1,-1,-1 } 
            };
            double[,] contrast1 = {
                {0,-1,0 },
                {-1,5,-1 },
                {0,-1,0 }
            };
            applyFilter(contrast);
            pictureBox1.Image = bmp;
            pictureBox1.Invalidate();
        }


        private void onInvBtnClick(object sender, EventArgs e)
        {
            Bitmap tmpBitmap = new Bitmap(bmp.Width, bmp.Height, bmp.PixelFormat);
            for (int i = 0; i < bmp.Width; i++)
            {
                for (int j = 0; j < bmp.Height; j++)
                {
                    double tmpR = 0, tmpG = 0, tmpB = 0;
                    Color Pixel = bmp.GetPixel(i, j);
                    tmpR = 255 - Pixel.R;
                    tmpG = 255 - Pixel.G;
                    tmpB = 255 - Pixel.B;
                    if (tmpR > 255) tmpR = 255;
                    else if (tmpR < 0) tmpR = 0;
                    if (tmpG > 255) tmpG = 255;
                    else if (tmpG < 0) tmpG = 0;
                    if (tmpB > 255) tmpB = 255;
                    else if (tmpB < 0) tmpB = 0;
                    tmpBitmap.SetPixel(i, j, Color.FromArgb(bmp.GetPixel(i, j).A, (int)tmpR, (int)tmpG, (int)tmpB));
                }
            }
            bmp = tmpBitmap;
            showMsgBox("Инверсия!");
            pictureBox1.Image = bmp;
            pictureBox1.Invalidate();
        }

        private void onBorderBtnClick(object sender, EventArgs e)
        {
            double[,] borderx = {
                {0,0,0 },
                {-1,0,1},
                {-0,0,0}
            };
            double[,] bordery = {
                {0,-1,0 },
                {0,0,0},
                {0,1,0}
            };
            applyFilter(borderx);
            applyFilter(bordery);
            pictureBox1.Image = bmp;
            pictureBox1.Invalidate();
        }

        private void onLapBtnCLick(object sender, EventArgs e)
        {
            double[,] laplassian = {
                {0,-1,0 },
                {-1,4,-1},
                {0,-1,0}
            };
            applyFilter(laplassian);
            pictureBox1.Image = bmp;
            pictureBox1.Invalidate();
        }

        private void onMirrorBtnClick(object sender, EventArgs e)
        {
            Bitmap tmpBitmap = new Bitmap(bmp.Width, bmp.Height, bmp.PixelFormat);
            for (int i = 0; i < bmp.Width; i++)
            {
                for (int j = 0; j < bmp.Height; j++)
                {
                    double tmpR = 0, tmpG = 0, tmpB = 0;
                    Color Pixel = bmp.GetPixel(i, j);
                    tmpBitmap.SetPixel(bmp.Width -1 - i, /*bmp.Height - 1 -*/ j, Pixel);
                }
            }
            bmp = tmpBitmap;
            showMsgBox("Отражение!");
            pictureBox1.Image = bmp;
            pictureBox1.Invalidate();
        }
    }
}
