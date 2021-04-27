using System;

namespace test4_2
{
    
    class Program
    {
        
        static void Main()
        {
            Rect rect1 = new Rect(12.00, 15.00);
            Circle circle = new Circle();
        }
    }
    public class Rect
    {
        double rectlong;
        double hight;

        public double Rectlong
        {
            set => rectlong = value;
        }
        public double Hight
        {
            set => hight = value;
        }
        public Rect(double reactlong, double hight)
        {
            this.rectlong = reactlong;
            this.hight = hight;
            var square = reactlong * hight;
            Console.WriteLine($"矩形的面积{square}"); // $式输出
        }
    }
    public class Circle
    {
        double radius;
        public double Radius
        {
            set => radius = value;
        }
        public Circle()
        {
            radius = 10;
            double pi = 3.14;
            var square = radius * pi;
            Console.WriteLine("圆的面积{0}",square);  // 常规输出
        }
    }
}
   
   
