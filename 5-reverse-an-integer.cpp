// Reverse an integer
// Author: Sai Prajwal Kotamraju

#include <iostream>

/** @brief reverseNum Function to reverse a given integer
 *  @param num Integer which has to be reversed
 */
int reverseNum (int num) {
    // Variable to store the reverse of the input
    int res = 0; 
    // If the number is negative, set the check flag
    bool check = (num < 0);
    // Make the num value positive    
    if (check) { num = -num; }
    while (num) {
        res = res*10 + num%10;
        num /= 10;
    }
    if (check) {return -res;} else {return res;}
}

int main()
{
    int num;
    std::cout << "Enter the number to be reversed: ";
    std::cin >> num;
    std::cout << "Reverse of "<<num<<" is: "<<reverseNum(num);
    return 0;
}
