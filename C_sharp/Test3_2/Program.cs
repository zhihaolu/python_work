using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace Test3_2
{
    class Program
    {
        static void Main(string[] args)
        {
            int[,] a = new int[5, 5];
            a[0, 0] = 1;
            for (int i = 1; i < 5; i++)
            {
                a[i, 0] = 1;
                a[i, i] = 1;
                for (int j = 1; i < 5; j++)
                    a[i, j] = a[i - 1, j - 1] + a[i - 1, j];
            } 
            for (int i = 0; i < 5; i++)
            {
                for (int j = 0; j <= i; j++)
                    Console.WriteLine("{0}\t", a[i, j]);
                Console.WriteLine();
            }
            Console.Read();
        }
    }
}
