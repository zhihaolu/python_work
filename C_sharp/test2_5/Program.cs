using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test2_5
{
    class Program
    {
        enum WeekDay { sun,mon,tue,wed,thu,fri,sat}
        static void Main(string[] args)
        {
            WeekDay a = WeekDay.sun;
            Console.WriteLine(a);
            WeekDay b = (WeekDay)4;
            Console.WriteLine(b);
            Console.Read();
        }
    }
}
