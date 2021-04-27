using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace test5_1
{
    public class BankAccount
    {
        static int totalAccountNumber = 0;
        string BankAccountId;
        double initialDepositAmount = 0.00;
        public BankAccount(string myId)
        {
            this.BankAccountId = myId;
            this.initialDepositAmount = 0.00;
            totalAccountNumber++;
        }
        public void displayid()
        {
            Console.WriteLine("mabaid={0},initialDepositAmount={1}", this.BankAccountId, this.initialDepositAmount);
        }
        public static void display()
        {
            Console.WriteLine("totalAccontNumber={0}", totalAccountNumber);
        }
    }
    class Program
    {
        static void Main()
        {
            BankAccount mba = new BankAccount("37000001");
            BankAccount mba2 = new BankAccount("37000002");
            BankAccount mba3 = new BankAccount("");
            BankAccount mba4 = new BankAccount("37000004");
            //Console.WriteLine("mba2ID={0}", mba2.BankAccountId);
            mba2.displayid();
            BankAccount.display();
            Console.ReadLine();
        }
    }
}
