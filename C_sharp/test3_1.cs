using System;

public class TestDowhile{
    public static void Main(){
        int x;
        int y = 0;
        do{
            x = y++;
            Console.WriteLine(x);
        }
        while(y < 5);
    }
}