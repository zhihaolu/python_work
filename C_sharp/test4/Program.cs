using System;

namespace test4
{
    class Program
    {
        static void Main(string[] args)
        {
            Book a = new Book();
            Book b = new Book("hi", "lu", 20);
            a.output();
            b.output();
        }
        public class Book
        {
            private string name;
            private string author;
            private decimal price;
/*          // 常规用法
            public string Name
            {
                get
                {
                    return name;
                }
                set
                {
                    name = value;
                }
            }

            public string Author
            {
                get
                {
                    return author;
                }
                set
                {
                    author = value;
                }
            }
            public decimal Price
            {
                get
                {
                    return price;
                }
                set
                {
                    price = value;
                }
            }

*/        // 简单用法    
                                public string Name
                                {
                                    get => name;
                                    set => name = value;
                                }
                                public string Author
                                {
                                    get => author;
                                    set => author = value;
                                }
                                public decimal Price
                                {
                                    get => price;
                                    set => price = value;
                                }


            public Book(string name, string author, decimal price)
            {
                this.name = name;
                this.author = author;
                this.price = price;
                Console.WriteLine("有参数函数调用成功");

            }
            public Book()
            {
                name = "helloworld";
                author = "lin";
                price = 10;
                Console.WriteLine("无参函数调用成功");
            }
            public void output()
            {
                Console.WriteLine($"这本书是 {name},作者为：{author},价格： {price}");
            }

        }
    }
}


