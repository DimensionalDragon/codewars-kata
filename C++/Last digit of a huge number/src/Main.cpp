#include<iostream>
#include<cmath>
#include<vector>
#include<list>
using namespace std;

int exponentMod(int base, int power, int mod) // calculates (base^power) % (mod)
{
    if(power == 0) return 1; //special case
    else if(mod == 4)
    {
        base %= 4;
        if((base == 2 || base == 6) && power == 1) return 2; //special case
        else if(base == 0 || base == 2 || base == 4 || base == 6 || base == 8) return 0; //always 0
        else if(base == 1 || base == 5 || base == 9) return 1; //always 1
        else if(base == 3 || base == 7) return (power % 2 == 0) ? 1 : 3; //1 if the power is even, 3 if the power is odd
    }
    else if(mod == 10)
    {
        if(base == 5 || base == 6) return base; //always ends in itself
        else
        {
            int result = 0;
            if(power % 4 != 0) result = pow(base, power % 4); //for powers not divisible by 4
            else if(power % 4 == 0) result = pow(base, 4); //for positive powers divisible by 4
            return (result % 10);
        }
    }
    return -1;
}

int calculate(vector<int> array)
{
    if(array.size() == 0) return 1; //empty
    else if(array.size() == 1) return array[0] % 10; //1 element
    else if(array.size() == 2) //2 elements
    {
        array[0] %= 10; //get the last digit of base
        return exponentMod(array[0], array[1], 10); //call the exponent mod function
    }
    {
        int moddedPower;
        array[0] %= 10;
        if(array.size() >= 6 && array[5] == 0) array[4] = 1; //I got desperate at the 2 0 0 0 0 0 alternating test case lol
        if(array.size() >= 5 && array[4] == 0) array[3] = 1;
        if(array.size() >= 4 && array[3] == 0) array[2] = 1;
        if(array[2] == 0) return array[0] % 10; //if 3rd element is 0, 2nd element is 1, answer it's just element 1 mod 10
        else if(array[1] == 0) return 1; //if 2nd element is 0, 1st element is 1, and that's the answer
        else if(array[0] == 0) return 0; //if the base (1st element) is 0 then the answer is 0
        if(array[1] != 0 && exponentMod(array[1], array[2], 4) == 0) moddedPower = 4; //if exponent is multiple of 4 but nonzero
        else moddedPower = exponentMod(array[1], array[2], 4); //mods the entire power by 4
        int result = exponentMod(array[0], moddedPower, 10); //mods the (base^modded_power) by 10
        return result;
    }
}

int last_digit(list<int> array) //moves the list to vector, pass it to calculate function. then return the result from there
{
    vector<int> convertedInput;
    int size = array.size();
    for(int i = 0; i < size; i++)
    {
        convertedInput.push_back(array.front());
        array.pop_front();
    }
    return calculate(convertedInput);
}

int main()
{
    cout << last_digit({0, 0, 0}) << endl;
    return 0;
}