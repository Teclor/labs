using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Text.RegularExpressions;

namespace lab2
{
    static class StringExtensions
    {
        public static string[] SplitKeepSeparators(this string s, params string[] separators)
        {
            if (s == null) throw new ArgumentNullException("s");
            if (s.Length == 0) return new string[] { s };

            var hash = new HashSet<string>(separators);
            var list = new List<string>();

            int i = 0;
            for (int j = 0; j < s.Length; j++)
            {
                if (hash.Contains(s[j].ToString()))
                {
                    if (j > i) list.Add(s.Substring(i, j - i));
                    list.Add(Convert.ToString(s[j]));
                    i = j + 1;
                }
            }
            if (i == 0) return new string[] { s };
            if (i != s.Length) list.Add(s.Substring(i));
            return list.ToArray();
        }
    }

    class Program
    {
        static string replaceVariables(string str, char[] delimeters, Dictionary<char, string> vars)
        {
            string tmpStr = "";
            bool found = true;
            tmpStr = str;
            while(found)
            {
                found = false;
                foreach (char delim in delimeters)
                {
                    int delimPos = tmpStr.IndexOf(delim);
                    if (delimPos > -1)
                    {
                        found = true;
                        tmpStr = tmpStr.Substring(0, delimPos) + vars[delim] + ((delimPos < tmpStr.Length -1) ? tmpStr.Substring(delimPos + 1) : "");
                    }
                }
            }
            return tmpStr;
        }
        static void Main(string[] args)
        {
            Stack<string> st = new Stack<string>();
            Dictionary<string, ushort> priorities = new Dictionary<string, ushort>
            {
                ["/"] = 2,
                ["*"] = 2,
                ["+"] = 1,
                ["-"] = 1,
                ["("] = 0

            }; // приоритет операций
            Dictionary<char, string> variables = new Dictionary<char, string>
            {
                ['a'] = "",
                ['b'] = "",
                ['c'] = "",
                ['d'] = "",
                ['e'] = ""

            }; // переменные
            for (char i = 'a'; i < 'f'; i++)
            {
                Console.Write($"{i}: ");
                variables[i] = Console.ReadLine();
            }
            string opsPatt = @"[\+\-\*\/\(\)]?"; // для проверки операторов
            Regex operators = new Regex(opsPatt);
            Console.WriteLine("Enter your expression:");
            string inStr = Console.ReadLine();
            char[] keys = {'a', 'b','c','d','e'};
            inStr = replaceVariables(inStr, keys, variables);
            string[] inArr = inStr.SplitKeepSeparators("/", "*", "+", "-", "(", ")");
            double num;
            string outStr = ""; //выходная строка 
            string op=""; // оператор
            for (int i = 0; i < inArr.Length; i++)
            {
                if (double.TryParse(inArr[i], out num))
                    outStr += inArr[i] + " ";
                else
                {
                    if (operators.IsMatch(inArr[i]))
                    {
                        op = operators.Match(inArr[i]).Value;
                        if (op == ")")
                        {
                            while (st.Peek() != "(")
                                outStr += st.Pop() + " ";
                            st.Pop();
                        }
                        else
                        {
                            ushort opPriority = priorities[op];
                            switch (opPriority)
                            {
                                case 2:
                                    st.Push(op);
                                    break; // стек пуст или находящиеся в нем символы меньше приоритетом
                                case 1:
                                    if (!st.Any())
                                        st.Push(op); // стек пуст - добавляем
                                    else
                                        if (priorities[st.Peek()] < opPriority) // если приоритет последнего  символа в стеке меньше - добавляем в стек
                                        st.Push(op);
                                    else
                                    {
                                        while (st.Any() && priorities[st.Peek()] >= opPriority) //пока приоритет последнего символа в стеке больше или равен и пока стек не пуст
                                            outStr += st.Pop() + " ";
                                        st.Push(op);
                                    }
                                    break;
                                case 0:
                                    st.Push(op);
                                    break;
                                default: 
                                    Console.WriteLine("An error occured."); 
                                    return;
                            }
                        }
                    }
                    else {
                            Console.WriteLine("An error occured."); 
                            return; 
                         }
                }
            }
            while(st.Any()) outStr += st.Pop() + " ";
            outStr = outStr.Trim();
            Console.WriteLine(outStr);

            Stack<double> stOut = new Stack<double>();
            string[] outArr = outStr.Split(" ");
            for (int i =0; i<outArr.Length; i++)
            {
                if (double.TryParse(outArr[i], out num))
                    stOut.Push(num);
                else
                {
                    double op2;
                    switch (outArr[i])
                    {
                        case "+":
                            stOut.Push(stOut.Pop() + stOut.Pop());
                            break;
                        case "*":
                            stOut.Push(stOut.Pop() * stOut.Pop());
                            break;
                        case "-":
                            op2 = stOut.Pop();
                            stOut.Push(stOut.Pop() - op2);
                            break;
                        case "/":
                            op2 = stOut.Pop();
                            if (op2 != 0.0)
                                stOut.Push(stOut.Pop() / op2);
                            else
                                Console.WriteLine("Ошибка. Деление на ноль");
                            break;
                        default:
                            Console.WriteLine("Ошибка. Неизвестная команда - " + outArr[i]);
                            break;
                    }
                }
            }
            Console.WriteLine("Результат: " + stOut.Pop());
        }
        
    }
    
}

