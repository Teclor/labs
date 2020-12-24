using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace _6lab
{
    public partial class Form1 : Form
    {
        Graphics g;
        Point a, b, c;
        Point midAB, midBC, midCA;
        Pen pen = new Pen(Brushes.Blue, 0.5f);
        List<Tuple<Point, Point, Point>> triangles;
        List<Tuple<Point, Point, Point>> tmpTriangles;
        int width;
        int padding;
        public Form1()
        {
            InitializeComponent();
            padding = 10;
            triangles = new List<Tuple<Point, Point, Point>>(32767);
            g = pictureBox1.CreateGraphics();
            createTriangle();
        }
        
        //Создаём стартовый треугольник
        private void createTriangle()
        {
            width = pictureBox1.Height - padding;
            int height = (int)Math.Round(Math.Sqrt(Math.Pow(width, 2) - Math.Pow(width / 2, 2)));
            a = new Point(pictureBox1.Width / 2 - width / 2, height + padding);
            b = new Point(pictureBox1.Width / 2, padding);
            c = new Point(pictureBox1.Width / 2 + width / 2, height + padding);
            triangles.Add(new Tuple<Point, Point, Point>(a, b, c));
        }

        private void onMouseClick(object sender, MouseEventArgs e)
        {
            if (e.Button == MouseButtons.Left)
            {
                drawTriangles();
            }
            else
            {
                g.Clear(pictureBox1.BackColor);
                g = pictureBox1.CreateGraphics();
                triangles.Clear();
                createTriangle();
            }
        }
        private void drawTriangles()
        {
            //делаем из каждого треугольника три, добавляем их в список, а тот, в котором они были нарисованы уже не входит в этот список
            tmpTriangles = new List<Tuple<Point, Point, Point>>(32767);
            foreach (Tuple<Point,Point,Point> triangle in triangles)
            {
                a = triangle.Item1;
                b = triangle.Item2;
                c = triangle.Item3;
                g.DrawLine(pen, a, b);
                g.DrawLine(pen, b, c);
                g.DrawLine(pen, c, a);
                //середину вычисляем как координата точки + (конечные координаты - начальные) / 2
                midAB = new Point(a.X + (b.X - a.X) / 2, a.Y + (b.Y - a.Y) / 2);
                midBC = new Point(b.X + (c.X - b.X) / 2, b.Y + (c.Y - b.Y) / 2);
                midCA = new Point(c.X + (a.X - c.X) / 2, c.Y + (a.Y - c.Y) / 2);
                tmpTriangles.Add(new Tuple<Point, Point, Point>(a, midAB, midCA));
                tmpTriangles.Add(new Tuple<Point, Point, Point>(midAB, b, midBC));
                tmpTriangles.Add(new Tuple<Point, Point, Point>(midCA, midBC, c));
            }
            triangles = new List<Tuple<Point, Point, Point>>(tmpTriangles);
            tmpTriangles.Clear();
        }
    }
}
