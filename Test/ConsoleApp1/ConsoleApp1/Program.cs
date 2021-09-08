using System;
using System.Runtime.InteropServices;

namespace ConsoleApp1
{
    class Program
    {
        [DllImport("taurustrade.dll", EntryPoint = "Test", CallingConvention = CallingConvention.Cdecl)]
        public static extern void Test();

        static void Main(string[] args)
        {

            Test();
            Console.WriteLine("Hello World!");
        }
    }
}
