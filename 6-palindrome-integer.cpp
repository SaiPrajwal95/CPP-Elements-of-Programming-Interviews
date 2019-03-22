// Check if a given integer is a Palindrome
// Author: Sai Prajwal Kotamraju

#include <iostream>
#include <cmath>

/** @brief isPalindrome Function that returns a boolean value indicating
 *                      whether or not a given integer is a palindrome
 *  @param num integer which is to be checked whether it is a palindrome
 */ 
bool isPalindrome (int num) {
    if (num < 0) {
        // return false for a negative integer
        return false;
    } else if (num == 0) {
        return true;
    }
    int len = static_cast<int>(log10(num) + 1);
    if (len == 1) {
        return true;
    }
    // Check if the MSD is equal to LSD
    int pwr = static_cast<int>(pow(10,len-1));
    if (num%10 == num/pwr) {
        num %= pwr; // Strip off the MSD
        num /= 10; // Strip off the LSD
        // Pass the resultant num to the function again
        return isPalindrome (num); 
    } else {
        // return false if MSD isn't equal to LSD
        return false; 
    }
}

int main() {
    int num;
    std::cout << "Enter the integer value: ";
    std::cin >> num;
    if (isPalindrome (num)) {
        std::cout << num << " is a palindrome";
    } else {
        std::cout << num << " is not a palindrome";
    }
    return 0;
}
