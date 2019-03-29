// Increment an array encoded integer by 1
// Given an array <8,9> for example, make it <9,0>
// Sai Prajwal Kotamraju

#include <iostream>
#include <vector>
#include <cmath>

/** @brief incrementArrayEncodedInteger Increments the array encoded integer
 *  @param input Reference to the input array encoded integer
 */ 
void incrementArrayEncodedInteger (std::vector<int>& input) {
    ++input.back(); // Increment the last digit
    // Continue to previous digit only when input[i] becomes 10
    // Else, nothing has to be changed
    for (int i = input.size()-1; i>0 && input[i]==10; i--) {
        input[i] = 0;
        ++input[i-1];
    }
    if (input[0] == 10) {
        // Overflow condition
        // You can handle this situation as you wish
        // One way is to just add another 1 at the end of array
        // Handle the edge case further by checking if A[0] is 0 and interpret
        // the array in reverse order to get the solution. (See printArr function)
        input[0] = 0;
        input.push_back(1);
    }
}

/** @brief printArr Prints the array encoded integer by checking the overflow
 *  @param input Input array encoded integer
 */
void printArr (const std::vector<int>& input) {
    // Check if overflow and print 10^(size-1)
    if (input[0] == 0) {
        std::cout << pow(10, input.size()-1) << "\n";
    } else {
        for (const int& elem : input) {
            std::cout << elem;
        }
        std::cout << "\n";
    }
}

int main()
{
    std::vector<int> input1 = {9,9,8};
    incrementArrayEncodedInteger (input1);
    printArr(input1);
    
    // Overflow Case
    incrementArrayEncodedInteger (input1);
    printArr(input1);
    
    return 0;
}
