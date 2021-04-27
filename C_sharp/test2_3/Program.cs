using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test2_3
{
    class Program
    {
        static void Main(string[] args)
        {         
            int a = 10;
            Console.WriteLine("a={0}", a);
            int b = new int();
            Console.WriteLine("1:b={0}", b);
            b = 10;
            Console.WriteLine("2:b={0}", b);
            Int32 c = 10;
            Console.WriteLine("c={0}", c);
            Int32 d = new Int32();
            Console.WriteLine("1:d={0}", d);
            d = 10;
            Console.WriteLine("2:d={0}", d);
            Console.WriteLine("int:{0}~~{1}", int.MinValue, int.MaxValue);
            Console.Read();
        }
    }
}
