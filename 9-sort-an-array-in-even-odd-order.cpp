// Program that sorts an integer array in such a way that
// even elements of the array come first
// Author: Sai Prajwal Kotamraju

#include <iostream>
#include <vector>

/** @brief swapNums Swaps two integer argument values
 *  @param num1 Reference to the first integer argument
 *  @param num2 Reference to the second integer argument
 */ 
void swapNums (int& num1, int& num2) {
    int temp;
    temp = num1; 
    num1 = num2;
    num2 = temp;
}

/** @brief sortEvenOdd Sorts the array such that even elements appear first
 *  @param Arr Reference to the input array
 */ 
void sortEvenOdd (std::vector<int>& Arr) {
    int lowerSortedIndex = 0;
    int higherSortedIndex = Arr.size()-1;
    // Check if the value at lowerSortedIndex is even
    // If even, increment lowerSortedIndex
    // If odd, swap it with the value at higherSortedIndex
    // The above step puts an odd value at the higherSortedIndex
    // After this, decrement the higherSortedIndex because value at this
    // location is sorted
    while (lowerSortedIndex < higherSortedIndex) {
        if (Arr[lowerSortedIndex]%2 == 0) {
            ++lowerSortedIndex;
        } else {
            swapNums (Arr[lowerSortedIndex], Arr[higherSortedIndex--]);
        }
    }
}

int main()
{
    std::vector<int> inputArray;
    std::cout << "Enter the values of the array\n";
    std::cout << "Enter -1 to indicate the end of the array\n";
    std::cout << "Start entering\n";
    while (true) {
        int tempNum;
        std::cin >> tempNum;
        if (tempNum != -1) { 
            inputArray.push_back(tempNum);
        } else {
            break;
        }
    }
    std::cout << "Sorting the array with even elements first.\n";
    sortEvenOdd(inputArray);
    std::cout << "Sorted array is as follows:\n";
    for ( const int& elem : inputArray) {
        std::cout << elem << " ";
    }
    return 0;
}
