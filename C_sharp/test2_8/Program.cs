using System;

namespace shiyan2_8
{
    class Program
    {
        static void Main(string[] args)
        {
            int a = 123;
            object obj = a;
            Console.WriteLine(obj);
            int b = (int)obj;
            Console.WriteLine(b);
            Console.Read();
        }
    }
}
