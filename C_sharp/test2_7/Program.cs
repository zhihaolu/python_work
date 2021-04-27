using System;

namespace shiyan2_7
{
    class Program
    {
        enum Month { Jan, Feb, Mar, Apr, May, Jun, Jul, Aug, Sept, Oct, Nov, Dec }
        static void Main(string[] args)
        {

            Month a = Month.May;
            Console.WriteLine(a);
            Month b = (Month)2;
            Console.WriteLine(b);
            Console.Read();
        }
    }
}
