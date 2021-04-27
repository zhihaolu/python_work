using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test2_4
{
    class Program
    {
        static void Main(string[] args)
        {
            char c1 = 'a';
            char c2 = '\x0062';
            char c3 = '\u0063';
            Console.WriteLine("c1:{0}\nc2:{1}\nc3:{2}\n", c1, c2, c3);
            Console.Read();
        }
    }
}
