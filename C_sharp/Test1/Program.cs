using System;

namespace Test1
{
    class Program
    {
        public static void Main()
        {
            Console.Write("请输入一个字符：");
            char c = (char)Console.Read();
            if (Char.IsLetter(c))
                if (Char.IsLower(c))
                    Console.WriteLine("字符是小写的。");
                else
                    Console.WriteLine("字符是大写的。");
            else
                Console.WriteLine("字符不是字母。");
        }
    }
}
