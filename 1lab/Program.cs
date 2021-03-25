using System;
using System.IO;
using System.Linq;

namespace _1lab
{
    class Program
    {
        static void Main(string[] args)
        {
            using (FileStream fstream = File.OpenRead("..\\..\\..\\text.txt"))
            {
                byte[] array = new byte[fstream.Length];
                fstream.Read(array, 0, array.Length);
                string textFromFile = System.Text.Encoding.Default.GetString(array);
                Console.WriteLine($"Текст из файла:\n{textFromFile}\n---------------------\n");
                string[] result = new string[100];
                string reg = "(ab*)+(abc)+";
                string found = "";
                string foundTmp = "";
                bool inRegular = false;
                int regIndex = 0;
                int counter = 0;
                bool foundFirstPart = false;
                for (int i = 0; i < textFromFile.Length; i++)
                {
                    char c = textFromFile[i];
                    if (c == 'a' && regIndex == 0)
                    {
                        if (inRegular)
                        {
                            foundFirstPart = true;
                        }
                        foundTmp += c;
                        inRegular = true;
                    }
                    else if (c == 'b' && regIndex == 0 && inRegular)
                    {
                        if (foundTmp.Length > 1) { foundFirstPart = true; }
                        regIndex++;
                        foundTmp += c;
                    } else if (c == 'b' && regIndex == 1)
                    {
                        foundTmp += c;
                    } else if (c == 'a' && regIndex == 1)
                    {
                        foundFirstPart = true;
                        regIndex = 0;
                        foundTmp += c;
                    }else if (c == 'a' && regIndex == 4 && foundFirstPart)
                    {
                        regIndex = 2;
                        foundTmp += c;
                    }else if (c == 'b' && regIndex == 2)
                    {
                        regIndex++;
                        foundTmp += c;
                    } else if (c == 'c' && (regIndex == 3 || regIndex == 1) && foundFirstPart && (foundTmp[foundTmp.Length-2] != 'b'))
                    {
                        regIndex = 4;
                        foundTmp += c;
                        found = foundTmp;
                    } else
                    {
                        if (foundTmp.Length > 0 && found != "")
                        {
                            i -= foundTmp.Length-found.Length+1;
                        }
                        regIndex = 0;
                        inRegular = false;
                        foundTmp = "";
                        foundFirstPart = false;
                        if (found != "")
                        {
                            result[counter] = found;
                            counter++;
                        }
                        found = "";
                    }
                    //Console.WriteLine(foundTmp + " " + regIndex + " " + i);
                }
                if (found != "")
                {
                    result[counter] = found;
                    counter++;
                }




                /*
                string[] result = new string[10];
                int counter = 0;
                string found = "";
                string foundTmp = found;
                string reg = "(ab*)+(abc)+";
                //reg = "(Hello* world)";
                int regIndex = 0;
                bool inRegular = false;
                int regLeftBracket = -1;
                int regSecondIndex = -1;
                int lastCharIndex = -1;
                foreach (char c in textFromFile)
                {
                    bool isChecked = false;
                    while (!isChecked)
                    {
                        if (foundTmp != "") Console.WriteLine("found " + foundTmp + " currentReg " + reg[regIndex] + " c " + c + " regIndex " + regIndex);

                        if (reg[regIndex] == '(')
                        {
                            regLeftBracket = regIndex;
                            regIndex++;
                        }
                        if (regLeftBracket != -1 && reg[regIndex] == ')')
                        {
                            if (reg[regIndex + 1] == '+')
                            {
                                if ((regIndex + 2) < reg.Length) 
                                {
                                    regSecondIndex = reg[regIndex + 2] == '(' ? regIndex + 3 : regIndex + 2;
                                }
                                regIndex = regLeftBracket + 1;
                            }
                            else
                            {
                                regIndex = regIndex + 1 < reg.Length ? regIndex : regIndex + 1;
                            }
                            if (regIndex == reg.Length)
                            {
                                break;
                            }
                        }
                        if (c == reg[regIndex])
                        {
                            inRegular = true;
                            foundTmp += c;
                            lastCharIndex = regIndex;
                            if (reg[regIndex + 1] != '*' && reg[regIndex + 1] != '+')
                            {
                                regIndex++;
                            }
                            isChecked = true;
                        }
                        else if ((reg[regIndex + 1] == '*') && inRegular)
                        {
                            regIndex += 2;
                        }
                        else if (regSecondIndex != -1 && inRegular)
                        {
                            int diff = lastCharIndex - regLeftBracket;
                            for (int i = diff; i > 0; i--)
                            {
                                if (foundTmp[foundTmp.Length - i] == reg[regSecondIndex + diff - i])
                                {
                                    continue;
                                }
                                else
                                {
                                    inRegular = false;
                                    regLeftBracket = -1;
                                    regSecondIndex = -1;
                                    found = "";
                                    foundTmp = "";
                                    regIndex = 0;
                                    isChecked = true;
                                    break;
                                }
                            }
                            if (inRegular)
                            {
                                regIndex = regSecondIndex + diff;
                                regLeftBracket = reg[regSecondIndex - 1] == '(' ? regSecondIndex - 1 : -1;
                                regSecondIndex = -1;
                            }
                        }
                        else if (inRegular && found != "") 
                        {
                            result[counter] = found;
                            inRegular = false;
                            regLeftBracket = -1;
                            regSecondIndex = -1;
                            found = "";
                            foundTmp = "";
                            regIndex = 0;
                            counter++;
                        }
                        else
                        {
                            inRegular = false;
                            regLeftBracket = -1;
                            regSecondIndex = -1;
                            found = "";
                            foundTmp = "";
                            regIndex = 0;
                            isChecked = true;
                        }
                    }

                    if (regIndex + 1 == reg.Length || (reg[regIndex + 1] == '+' && regIndex + 2 == reg.Length))
                    {
                        found = foundTmp;
                        if (inRegular)
                        {
                            regIndex = regLeftBracket + 1;
                        }
                        else
                        {
                            result[counter] = found;
                            inRegular = false;
                            regLeftBracket = -1;
                            regSecondIndex = -1;
                            found = "";
                            foundTmp = "";
                            regIndex = 0;
                            counter++;
                        }
                    }
                }*/
                Console.WriteLine($"Результаты поиска по шаблону {reg}\n");
                foreach (string res in result)
                {
                    if (res != null)
                    {
                        Console.WriteLine(res);
                    }
                }
            }
        }
    }
}
