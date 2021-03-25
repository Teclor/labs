using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Linq;
using System.Reflection;
using System.Text.RegularExpressions;

namespace lec60
{
    public static class StringExtensionMethods
    {
        public static string ReplaceFirst(this string text, string search, string replace)
        {
            int pos = text.IndexOf(search);
            if (pos < 0)
            {
                return text;
            }
            return text.Substring(0, pos) + replace + text.Substring(pos + search.Length);
        }

        public static string ReplacePos(this string text, int pos, string replace)
        {
            return pos == 0 ? replace + text.Substring(pos + 1) : text.Substring(0, pos) + replace + text.Substring(pos + 1);
        }
    }
    class Interpreter
    {
        const int a = 1;
        const int b = 3;
        const int c = 5;
        const int d = 7;
        const int e = 11;
        private static Dictionary<int, Tuple<string, string>> Grammar = new Dictionary<int, Tuple<string, string>>{
            {0, new Tuple<string, string>("AXIOM", "E")},
            {1, new Tuple<string, string>("E", "FXY") },
            {2, new Tuple<string, string> ("E", "X" ) },
            {3, new Tuple<string, string>("X", "+<A1>F<A2>XY") },
            {4, new Tuple<string, string>("X", "-<A1>F<A2>XY") },
            {5, new Tuple<string, string>("Y", "*<A1>F<A2>XY") },
            {6, new Tuple<string, string>("Y", "/<A1>F<A2>XY") },
            {7, new Tuple<string, string>("X", "") },
            {8, new Tuple<string, string>("Y", "") },
            {9, new Tuple<string, string>("F", "(EB") },
            {10, new Tuple<string, string>("F","V<A3>") },
            {11, new Tuple<string, string>("V","a") },
            {12, new Tuple<string, string>("V","b") },
            {13, new Tuple<string, string>("V","c") },
            {14, new Tuple<string, string>("V","d") },
            {15, new Tuple<string, string>("V","e") },
            {16, new Tuple<string, string>("B",")") },
        };
        private string[] terminals = { "E", "F", "X", "Y", "V", "B" };
        //private static Dictionary<int, Tuple<string, string>> Grammar = new Dictionary<int, Tuple<string, string>>{
        //    {0, new Tuple<string, string>("AXIOM", "E")},
        //    {1, new Tuple<string, string>("E", "FXY") },
        //    {2, new Tuple<string, string> ("E", "X" ) },
        //    {3, new Tuple<string, string>("X", "+E") },
        //    {4, new Tuple<string, string>("X", "-E") },
        //    {5, new Tuple<string, string>("Y", "*E") },
        //    {6, new Tuple<string, string>("Y", "/E") },
        //    {7, new Tuple<string, string>("X", "") },
        //    {8, new Tuple<string, string>("Y", "") },
        //    {9, new Tuple<string, string>("F", "(EB") },
        //    {10, new Tuple<string, string>("F","V") },
        //    {11, new Tuple<string, string>("V","a") },
        //    {12, new Tuple<string, string>("V","b") },
        //    {13, new Tuple<string, string>("V","c") },
        //    {14, new Tuple<string, string>("V","d") },
        //    {15, new Tuple<string, string>("V","e") },
        //    {16, new Tuple<string, string>("B",")") },
        //};
        //Regex check = new Regex(@"[a-e\(\)\-\+\*\/]");
        bool debug;
        string exp;
        string buffer;
        string output;
        int index;
        Stack<char> st;
        public Interpreter(string inputString, bool debugMode = false)
        {
            debug = debugMode;
            output = "";
            st = new Stack<char>();
            int[] movingTransformations = new int[] { 3, 4, 5, 6, 9, 11, 11, 12, 13, 14, 15, 16 };
            exp = inputString;
            bool end = false;
            bool error = false;
            string errorText = "";
            int tokenIndex = -1;
            buffer = "E";
            index = 0;
            while (!end && !error)
            {
                if (index == exp.Length)
                {
                    tokenIndex = 7;
                    end = true;
                    int xIndex = buffer.IndexOf(Grammar[tokenIndex].Item1[0]);
                    while (xIndex > -1) 
                    {
                        buffer = buffer.ReplaceFirst(Grammar[tokenIndex].Item1, Grammar[tokenIndex].Item2);
                        xIndex = buffer.IndexOf(Grammar[tokenIndex].Item1[0]);
                        DebugPrint();
                    }
                    tokenIndex = 8;
                    xIndex = buffer.IndexOf(Grammar[tokenIndex].Item1[0]);
                    while (xIndex > -1)
                    {
                        buffer = buffer.ReplaceFirst(Grammar[tokenIndex].Item1, Grammar[tokenIndex].Item2);
                        xIndex = buffer.IndexOf(Grammar[tokenIndex].Item1[0]);
                        DebugPrint();
                    }
                    break;
                }
                else
                {
                    tokenIndex = GetTokenIndex();
                }
                if (tokenIndex < 0)
                {
                    error = true;
                    errorText = "Syntax error: unexpected token \"" + inputString[index].ToString() + "\"" + " at " + index.ToString();
                } 
                else
                {
                    buffer = buffer.ReplacePos(getFirstTerminalIndex(), Grammar[tokenIndex].Item2);
                    DebugPrint();
                    if (movingTransformations.Contains(tokenIndex))
                    {
                        index++;
                    }
                }

            }
            if (error)
            {
                Console.WriteLine(errorText);
            }
            else
            {
                DoActions();
                DebugPrint(output);
            }
        }

        private int GetTokenIndex(int indexFound = -1)
        {
            char searchVal = indexFound > 0 ? Grammar[indexFound].Item1[0] : exp[index];
            bool found = false;
            foreach (KeyValuePair<int, Tuple<string, string>> pair in Grammar)
            {
                if (pair.Key == 7 || pair.Key == 8) continue;
                if (pair.Value.Item2[0] == searchVal)
                {
                    indexFound = pair.Key;
                    found = true;
                    break;
                }
            }
            if (indexFound < 0 || !found)
            {
                int firstTerminalIndex = getFirstTerminalIndex();
                char firstTerminal = buffer[firstTerminalIndex];
                if (Grammar[7].Item1[0] == firstTerminal)
                {
                    indexFound = 7;
                }
                if (Grammar[8].Item1[0] == firstTerminal)
                {
                    indexFound = 8;
                }
                return indexFound;
            }
            if (buffer[getFirstTerminalIndex()] != Grammar[indexFound].Item1[0])
            {
                indexFound = GetTokenIndex(indexFound);
            }
            return indexFound;
        }

        private int getFirstTerminalIndex()
        {
            int terminalIndex = 32768;
            foreach (string terminal in terminals)
            {
                int tmpIndex = buffer.IndexOf(terminal);
                if (tmpIndex > -1)
                {
                    terminalIndex = tmpIndex < terminalIndex ? tmpIndex : terminalIndex;
                }
            }
            return terminalIndex > buffer.Length ? -1 : terminalIndex;
        }

        private void DebugPrint(string var = "")
        {
            if (debug)
            {
                if (var.Length > 0)
                {
                    Console.WriteLine("Debug: " + var);
                }
                else
                {
                    Console.WriteLine("Выражение: " + buffer /* + "\nПредпросмотр: " + exp[index] + "\nТокен: " +Grammar[tokenIndex].Item1*/);
                }
            }
        }

        private void DoActions()
        {
            string[] methodNames = {"A1", "A2", "A3"};
            Dictionary<string, MethodInfo> methods = new Dictionary<string, MethodInfo>();
            foreach (string method in methodNames)
            {
                Type type = typeof(Interpreter);
                methods.Add(method, type.GetMethod(method));
            }

            int currentActionIndex = 0;
            string bufferPart = buffer.Substring(currentActionIndex);
            currentActionIndex = bufferPart.IndexOf('<');
            while (currentActionIndex > -1)
            {
                string methodName = bufferPart.Substring(currentActionIndex + 1, 2);
                methods[methodName].Invoke(this, new object[] { currentActionIndex + (buffer.Length - bufferPart.Length)});
                bufferPart = bufferPart.Substring(currentActionIndex+1);
                currentActionIndex = bufferPart.IndexOf('<');
            }
        }

        public void A1(int ind)
        {
            //push to stack
            st.Push(buffer[ind - 1]);
        }
        public void A2(int ind)
        {
            //pop from stack and print
            output += st.Pop();
        }

        public void A3(int ind)
        {
            //print
            output += buffer[ind - 1];
        }


        public static Dictionary<int, Tuple<string, string>> GetGrammar()
        {
            return Grammar;
        }

        public static void PrintGrammar()
        {
            foreach (KeyValuePair<int, Tuple<string, string>> pair in Grammar)
            {
                Console.WriteLine(pair.Value.Item1 + " => " + pair.Value.Item2);
            }
        }

    }
    class Program
    {
        static void Main(string[] args)
        {
            string expression = "(-a+b)*(c+d)";
            Console.WriteLine("На входе получено: " + expression);
            Interpreter interpreter = new Interpreter(expression, true);
        }
    }
}
