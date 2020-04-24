using System;
using System.Threading;

namespace hanoitower
{
    class Hanoi
    {
        private int[,] towers;
        private int lvl;
        private int pauseTime;
        private int[] tops = new int[3];
        public Hanoi()
        {
            lvl = 0;
            pauseTime = 100;
        }
        public Hanoi(int n, int pT = 500)
        {
            if (n <= 0 || n > 10)
            {
                Console.WriteLine("Можно вводить только числа от 1 до 10");
                n = 1;
            }
            lvl = n;
            pauseTime = pT;
            towers = new int[3, lvl+1];
            for (int i = 0; i < 3; i++)
            {
                // высота первой башни
                towers[0, 0] = lvl;
                // текущая высота второй и третьей
                towers[1, 0] = 0;
                towers[2, 0] = 0;
                for (int j = lvl; j > 0; j--)
                {
                    // длина диска в башне i на уровне j
                    if (i == 0) towers[i, j] = lvl-j+1;
                    else towers[i, j] = 0;
                }
            }
        }
        void ShowTowerPart(int diskLength = 0)
        {
            int spaces = lvl - diskLength + 1;

            for (int j = spaces; j > 0; j--)
                Console.Write(" ");

            for (int j = 0; j < diskLength; j++)
                Console.Write("_");
            Console.Write("||");
            for (int j = 0; j < diskLength; j++)
                Console.Write("_");

            for (int j = spaces; j > 0; j--)
                Console.Write(" ");
            Console.WriteLine();
        }
        public void ShowTowers()
        {
            for (int t = 0; t < 3; t++)
            {
                int towerLvl = towers[t,0];
                for (int j = 0; j < lvl - towerLvl; j++)
                    ShowTowerPart();
                for (int j = towerLvl; j >=1; j--)
                    ShowTowerPart(towers[t, j]);

                Console.WriteLine($"-----------------Tower--number--{t+1}------------------");
            }
            Thread.Sleep(pauseTime);
            //Console.WriteLine("---------------------------------------------------");
            //Console.WriteLine("-----------------NEXT---ITERATION------------------");
            //Console.WriteLine("---------------------------------------------------");
        }
        void Transfer(int num, int start, int end, int temp)
        {
            if (num == 0) return;
            Transfer(num - 1, start, temp, end);
            towers[end, 0]++;
            towers[end, towers[end, 0]] = towers[start, towers[start, 0]];
            towers[start, towers[start, 0]] = 0;
            towers[start,0]--;
            Console.Clear();
            ShowTowers();
            Transfer(num - 1, temp, end, start);
        }
        public void TransferCall()
        {
            ShowTowers();
            Transfer(lvl, 0, 1, 2);
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("Введите количество дисков на начальном колышке (от 1 до 10): ");
            int n;
            int.TryParse(Console.ReadLine(), out n);
            Console.WriteLine("Введите желаемую задержку в милисекундах между операциями: ");
            int pauseTime;
            int.TryParse(Console.ReadLine(), out pauseTime);
            Hanoi Tower = new Hanoi(n, pauseTime);
            Tower.TransferCall();
        }
    }
}
