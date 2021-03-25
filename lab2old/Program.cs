using System;
using System.Collections.Generic;

namespace lab2
{
    class Program
    {
        static void Main(string[] args)
        {
            System.Collections.Generic.Dictionary<string, int> priority = new Dictionary<string, int>(); //ассоциативный массив
            priority.Add("*", 3);
            priority.Add("/", 3);
            priority.Add("+", 2);
            priority.Add("-", 2);
            priority.Add("(", 1);
            priority.Add(")", 1);

            Stack<string> stackOfSymbol = new Stack<string>();
            string opz;
            string tmpStr;
            Console.WriteLine("Enter example: ");
            tmpStr = Console.ReadLine();
            string[] exp = new string[tmpStr.Length];
            opz = "";

            int k = 0; int j = 0, countLex = 0;

            string separators = "+-*/";

            //разбивание строки на подстроки
            while (true)
            {
                if (k >= tmpStr.Length)
                {
                    break;
                }

                if (((tmpStr[k] <= '9') && (tmpStr[k] >= '0')) || tmpStr[k] == ',')
                {
                    exp[j] += tmpStr[k];
                    k++;
                }
                else if (separators.IndexOf(tmpStr[k]) >= 0)
                {
                    j++;
                    exp[j] += tmpStr[k];
                    j++;
                    k++;
                }
                else if (tmpStr[k] == '(')
                {
                    exp[j] += tmpStr[k];
                    j++;
                    k++;
                }
                else
                {
                    j++;
                    exp[j] += tmpStr[k];
                    k++;
                }
            }

            separators = "+-*/()";
            int CountElem = 0;

            for (int i = 0; i <= j; i++)
            {
                if (separators.IndexOf(exp[i]) < 0)
                {
                    opz += exp[i] + " ";
                    CountElem++;
                }
                else if (exp[i] != ")")
                {
                    if (stackOfSymbol.Count == 0 || (priority[exp[i]] > priority[stackOfSymbol.Peek()]) || exp[i] == "(")
                    {
                        stackOfSymbol.Push(exp[i]);
                    }
                    else if (priority[exp[i]] <= priority[stackOfSymbol.Peek()])
                    {
                        opz += stackOfSymbol.Pop() + " ";
                        CountElem++;
                        i--;
                        continue;
                    }
                }
                else
                {
                    while (stackOfSymbol.Peek() != "(")
                    {
                        opz += stackOfSymbol.Pop() + " ";
                        CountElem++;
                    }
                    stackOfSymbol.Pop();
                }
            }
            while (stackOfSymbol.Count != 0)
            {
                opz += stackOfSymbol.Pop() + " ";
                CountElem++;
            }

            Console.WriteLine($"reverse polish notation = {opz}");


            string[] lexems = opz.Split(" ", StringSplitOptions.None);


            Stack<double> stackOfNum = new Stack<double>();
            double a, b;
            for (int i = 0; i < CountElem; i++)
            {
                if (separators.IndexOf(lexems[i]) < 0)
                {
                    stackOfNum.Push(Convert.ToDouble(lexems[i]));
                }
                else
                {
                    b = stackOfNum.Pop();
                    a = stackOfNum.Pop();
                    switch (lexems[i])
                    {
                        case "+":
                            stackOfNum.Push((a + b));
                            break;
                        case "-":
                            stackOfNum.Push((a - b));
                            break;
                        case "*":
                            stackOfNum.Push((a * b));
                            break;
                        case "/":
                            stackOfNum.Push((a / b));
                            break;
                    }
                }
            }
            Console.WriteLine($"Answer = {stackOfNum.Pop()}");
        }
    }
}
