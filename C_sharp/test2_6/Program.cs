using System;

namespace shiyan2_6
{
    class Program
    {
        struct stubase
        {
            public int sno;
            public string name;
            public char sex;
            public int age;
            public int year;
            public int month;
            public string home;
        }

        public static void Main(string[] args)
        {
            stubase linkong;
            linkong.name = "lu";
            linkong.sno = 4114;
            linkong.sex = 'G';
            linkong.age = 0;
            linkong.home = "huizhou";
            Console.WriteLine("please input birth year");
            linkong.year = Convert.ToInt32(Console.ReadLine());
            Console.WriteLine("please input month");
            // Console.Read();
            linkong.month = Convert.ToInt32(Console.ReadLine());
            text(linkong);
        }
        static void text(stubase linkong)
        {
            int nyear = DateTime.Now.Year;
            int nmonth = DateTime.Now.Month;
            int age1 = linkong.month > nmonth ? nyear - linkong.year - 1 : nyear - linkong.year;
            Console.WriteLine($"{linkong.name} age is {age1}");
            Console.Read();
        }
    }
}

