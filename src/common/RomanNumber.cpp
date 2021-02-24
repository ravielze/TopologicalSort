#include "RomanNumber.hpp"

int num[] = {1, 4, 5, 9, 10, 40, 50, 90, 100, 400, 500, 900, 1000};
string sym[] = {"I", "IV", "V", "IX", "X", "XL", "L", "XC", "C", "CD", "D", "CM", "M"};
int MAX_INDEX = 12;

string getRoman(int number)
{
    int i = MAX_INDEX;
    string result = "";
    while (number > 0)
    {
        int head = number / num[i];
        number = number % num[i];
        ;
        while (head--)
        {
            result = result + sym[i];
        }
        i--;
    }
    return result;
}