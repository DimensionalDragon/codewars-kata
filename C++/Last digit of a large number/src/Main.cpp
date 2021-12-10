#include<iostream>
#include<string>
#include<vector>
using namespace std;

int last_digit(string str1, string str2)
{
    if(str1 == "0" && str2 == "0") return 1; //special case
    else if(str2 == "0") return 1;
    else
    {
        /*Calculate last digit of the base*/
        char baseLastChar[2];
        baseLastChar[0] = str1.back();
        baseLastChar[1] = '\0';
        int baseLastDigit = stoi(baseLastChar);

        /*Calculate last 2 digits of the exponent*/
        char exponentLastTwoChar[3];
        int exponentLastTwoDigit;
        if(str2.size() >= 2)
        {
            exponentLastTwoChar[0] = str2.at(str2.size() - 2);
            exponentLastTwoChar[1] = str2.back();
            exponentLastTwoChar[2] = '\0';
            exponentLastTwoDigit = stoi(exponentLastTwoChar);
        }
        else if(str2.size() == 1)
        {
            exponentLastTwoChar[0] = str2.back();
            exponentLastTwoChar[1] = '\0';
            exponentLastTwoDigit = stoi(exponentLastTwoChar);
        }

        /*modulo 10 calculation*/
        int result = 1;
        if(baseLastDigit == 0) return 0;
        else
        {
            int exponentModulo = exponentLastTwoDigit % 4;
            if(exponentModulo == 0) exponentModulo = 4;
            for(int i = 1; i <= exponentModulo; i++)
            {
                result *= baseLastDigit;
                result %= 10;
            }
        }
        return result;
    }
}

int main()
{
    cout << last_digit("6", "10000000");
    return 0;
}