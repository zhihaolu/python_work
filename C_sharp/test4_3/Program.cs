using System;

namespace test4_3
{
    class Program
    {
        static void Main(string[] args)
        {
            // 数据初始化（不想搞手动输入）
            Student stu1 = new Student("lin", "001", 60, 75, 58);
            Student stu2 = new Student("lu", "002", 80, 83, 91);
            Student stu3 = new Student("guo", "003", 41, 32, 55);
            Student stu4 = new Student("chen", "004",92, 95, 78);
            Student stu5 = new Student("li", "005", 72, 67, 88);
            Studentlist class1 = new Studentlist();
            class1.stu = new[] { stu1, stu2, stu3, stu4, stu5 };

            double result = class1.QueryGrade("002");      //查询学生总分
            Console.WriteLine("------QueryGrade------");   // 为了美观（以下皆是）
            Console.WriteLine($"The query grade result:{result}");
            class1.MaxGrade();      // 查询班级最高分
            class1.FailGrade();     // 查询班级不及格名单
            class1.AvgGrade();      // 查询班级平均分
        }
    }
    // 定义一个学生类
    public class Student
    {
        public string name;
        public string sno;
        public double chinese;
        public double math;
        public double english;
        public double grade;
        public Student(string name, string sno, double chinese, double math, double english)
        {
            this.name = name;
            this.sno = sno;
            this.chinese = chinese;
            this.math = math;
            this.english = english;
            grade = chinese + math + english;
        }
    }

   

    public class Studentlist
    {
        public Student[] stu;
        // 查询学生总成绩
        public double QueryGrade(string sno)
        {
            for (int i = 0; i < stu.Length; i++)
            {
                if (stu[i].sno == sno)
                {
                    return stu[i].grade;
                }
            }
            return 0;
        }
        // 查询最高分
        public void MaxGrade()
        {
            double ChineseMax = 0;
            double MathMax = 0;
            double EnglishMax = 0;
            string NameChinese = "";
            string NameMath = "";
            string NameEnglish = "";

            for (int i = 0; i < stu.Length; i++)    // stu.Length 获取数组总共有多少个元素
            {
                // 擂台法
                if(stu[i].chinese > ChineseMax)
                {
                    ChineseMax = stu[i].chinese;
                    NameChinese = stu[i].name;
                }
                if(stu[i].math > MathMax)
                {
                    MathMax = stu[i].math;
                    NameMath = stu[i].name;
                }
                if(stu[i].english > EnglishMax)
                {
                    EnglishMax = stu[i].english;
                    NameEnglish = stu[i].name;
                }
            }
            Console.WriteLine("\n------MaxGrade------");
            Console.WriteLine($"Chinese:{NameChinese} {ChineseMax}");
            Console.WriteLine($"Math:{NameMath} {MathMax}");
            Console.WriteLine($"English:{NameEnglish} {EnglishMax}");
        }
        // 查询不及格
        public void FailGrade()
        {
            Console.WriteLine("\n------FailGrade------");
            for (int i = 0; i < stu.Length; i++){
                if(stu[i].chinese < 60)
                {
                    Console.WriteLine($"Chinese:{stu[i].name} {stu[i].chinese}");
                }
                if(stu[i].math < 60)
                {
                    Console.WriteLine($"Math:{stu[i].name} {stu[i].math}");
                }
                if(stu[i].english < 60)
                {
                    Console.WriteLine($"English:{stu[i].name} {stu[i].english}");
                }
            }
        }
        //查询平均分
        public void AvgGrade()
        {            
            double ChineseAvg = 0;
            double MathAvg = 0;
            double EnglishAvg = 0;
            for(int i = 0; i < stu.Length; i++)
            {
                // 累加
                ChineseAvg += stu[i].chinese;
                MathAvg += stu[i].math;
                EnglishAvg += stu[i].english;
            }
            // 累加结果除以数组总长及平均
            ChineseAvg /= stu.Length;
            MathAvg /= stu.Length;
            EnglishAvg /= stu.Length;
            Console.WriteLine("\n------ClassAvgGrade------");
            Console.WriteLine($"Chinese:{ChineseAvg}");
            Console.WriteLine($"Math:{MathAvg}");
            Console.WriteLine($"English:{EnglishAvg}");
        }    
}
}
