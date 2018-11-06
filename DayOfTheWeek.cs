using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace LeetCodeProblems
{
    public class Solution
    {
		//Write a program that finds the day of the week from givem date in a string.
		//Support as many date format as possible
        //
        // Summary:
        //     Specifies the day,month or year 
        public enum eTypeDate
        {
            Day = 0,
            Month = 1,
            DayOrMonth = 2,
            Year = 3,
        }
        string[] letters = {"a", "b", "c", "d", "e", "f", "g", "j", "n", "o", "m", "r", "p", "s", "t", "l", "u", "v", "y" };
        string[] days_of_the_week = { "Sunday", "Monday", "Tuesday", "Wednsday", "Thursday", "Friday", "Saturday", "Sunday" };
        public string GetNameDayOfTheWeek(int p)
        {
            return days_of_the_week[p];
        }
        private eTypeDate GetDateType(string p, ref int d)
        {
            foreach (string l in letters)
            {
                if (p.Contains(l))
                {
                    d = GetMonth(p);
                    return eTypeDate.Month;
                }
            }
            var num = Convert.ToInt32(p);
            d = num;
            if (num > 999)
            {
                return eTypeDate.Year;
            }
            else if ((num > 12) && (num <= 31))
                {
                    return eTypeDate.Day;
                }

            return eTypeDate.DayOrMonth;
        }
        private int GetMonth(string p)
        {
            if (p.Contains("jan"))
            {
                return 1;
            }
            if (p.Contains("feb"))
            {
                return 2;
            }
            if (p.Contains("mar"))
            {
                return 3;
            }
            if (p.Contains("apr"))
            {
                return 4;
            }
            if (p.Contains("may"))
            {
                return 5;
            }
            if (p.Contains("jun"))
            {
                return 6;
            }
            if (p.Contains("jul"))
            {
                return 7;
            }
            if (p.Contains("aug"))
            {
                return 8;
            }
            if (p.Contains("sep"))
            {
                return 9;
            }
            if (p.Contains("oct"))
            {
                return 10;
            }
            if (p.Contains("nov"))
            {
                return 11;
            }
            if (p.Contains("dec"))
            {
                return 12;
            }

            return -1;
        }
        public int GetDayOfWeek(string input, ref DayOfWeek dow, ref DayOfWeek dow1)
        {
            string[] elements = input.Split('-', ' ', ',');
            int year = -1;
            int month = -1;
            int day = -1;
            int dayormonth0 = -1;
            int dayormonth1 = -1;
            int temp = -1;

            foreach(string el in elements)
            {
                eTypeDate dtype = GetDateType(el, ref temp);
                switch (dtype)
                {
                    case eTypeDate.Month:
                        {
                            if (temp == -1)
                            {
                                Console.WriteLine("Incorrect input of the month!");
                                return 0;
                            }
                            else
                            {
                                month = temp;
                            }
                            break;
                        }
                    case eTypeDate.Year:
                        {
                            year = temp;
                            break;
                        }
                    case eTypeDate.DayOrMonth:
                        {
                            if (dayormonth0 == -1)
                            {
                                dayormonth0 = temp;
                            }
                            else
                            {
                                dayormonth1 = temp;
                            }
                            break;
                        }
                    case eTypeDate.Day:
                        {
                            day = temp;
                            break;
                        }
                    default:
                        break;
                }
            }
			// TODO: Check if 29,30,31 February have been inputted
			// TODO: not all month have 31 days.
            if ((month != -1) || (day != -1)) 
            {/* we have clear date */
                if (month == -1)
                {
                    month = dayormonth0;
                }
                if (day == -1)
                {
                    dayormonth0 = day;
                }
                DateTime dateValue = new DateTime(year, month, dayormonth0);
                dow = dateValue.DayOfWeek;
                return 1;
            }
            else
            {/* we have possible two dates */
                DateTime dateValue = new DateTime(year, dayormonth0, dayormonth1);
                dow = dateValue.DayOfWeek;
                DateTime dateValue1 = new DateTime(year, dayormonth1, dayormonth0);
                dow1 = dateValue.DayOfWeek;
                return 2;
            }
        }
    }

    class Program
    {

        static void Main(string[] args)
        {
            Solution objSolution = new Solution();

            Console.Write("Please input the date (supports dates starts from 1-Jan-1000): ");
            var input = Console.ReadLine().ToLower();
            DayOfWeek d0 = DayOfWeek.Friday;
            DayOfWeek d1 = DayOfWeek.Friday;

            int result = objSolution.GetDayOfWeek(input, ref d0, ref d1);
            if (result > 0)
            {
                if (result == 1)
                {
                    int p = (int)d0;
                    string op = objSolution.GetNameDayOfTheWeek(p);

                    Console.WriteLine("Day of the week is " + op);
                }
                else
                {
                    int p = (int)d0;
                    int p1 = (int)d1;
                    string op = objSolution.GetNameDayOfTheWeek(p);
                    string op1 = objSolution.GetNameDayOfTheWeek(p1);

                    Console.WriteLine("Day of the week is " + op + " or " + " op1.");
                }

            }
            else
            {
                Console.WriteLine("Incorrect or unknown date format!");
            }

            Console.Read();
        }
    }
}
