using System;
using System.Threading;

namespace Tarea9._1
{
    class Program
    {
        static int count = 0;

        static void Handler() {
            int tnum = ++count;
            Random random = new Random();
            for(int i = 5; i >= 0; i--) {
                int randomNumber = random.Next(1000, 3000);
                Thread.Sleep(randomNumber);
                Console.WriteLine("\tThread " + tnum + " countdown " + i);
            }
            Console.WriteLine("* Ending thread " + tnum);
        }

        static void Main(string[] args)
        {
            Console.WriteLine("<< MAIN METHOD STARTS      >>");
            Random random = new Random();

            for(int i = 1; i <= 5; i++) {
                Console.WriteLine("-> Initializing thread " + i);
                int randomNumber = random.Next(1000, 3000);
                Thread.Sleep(randomNumber);
                Thread t = new Thread(new ThreadStart(Handler));
                t.Start();
            }

            Console.WriteLine("<< ALL THREADS INITIALIZED >>");
            Console.WriteLine("<< MAIN METHOD ENDS        >>");
        }
    }
}
