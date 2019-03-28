// Dutch National Flag Problem
// Given an array and an pivot index (which has a pivot value), 
// arrange the values of array such that values less than pivot value comes
// first, followed by pivot values, followed by values larger than pivot value.
// Author: Sai Prajwal Kotamraju

#include <iostream>
#include <vector>

/** @brief swap Swaps two integer argument values
 *  @param num1 Reference to the first integer argument
 *  @param num2 Reference to the second integer argument
 */ 
void swap (int& num1, int& num2) {
    int temp;
    temp = num1; 
    num1 = num2;
    num2 = temp;
}

/** @brief dutchNationalFlagSort Sorts the Array as described in the comments
 *                               at the top of the file
 *  @param Arr Reference to the input array that has to be dutch sorted
 *  @param pivotIndex Index for the pivot element
 */ 
void dutchNationalFlagSort (std::vector<int>& Arr, const int& pivotIndex) {
    int lower = 0, higher = Arr.size()-1;
    int pivotVal = Arr[pivotIndex];
    int repeatTracker = 0; // Keeps track of number of sorted pivot values.
    int iterationNum = 0;
    while (lower < higher - repeatTracker) {
        if (Arr[lower] < pivotVal) {
            ++lower;
        } else if (Arr[lower] == pivotVal) {
            ++repeatTracker;
            swap(Arr[lower], Arr[higher - repeatTracker]);
        } else {
            swap(Arr[lower], Arr[higher]);
            swap(Arr[higher - 1], Arr[higher - repeatTracker - 1]);
            --higher;
        }
        if (Arr[higher] < pivotVal) {
            swap (Arr[lower], Arr[higher]);
        }
        
        // This section prints the state of array for each step
        std::cout<<"Step "<< ++iterationNum << " :";
        for ( const int& elem : Arr) {
            std::cout << elem << " ";
        }
        std::cout<<"\n";
    }
}

int main()
{
    std::vector<int> inputArray = {4,6,9,3,2,1,4,0,0,6,4,3,2};
    int pivotIndex;
    std::cout << "Enter the pivot index: ";
    std::cin >> pivotIndex;
    std::cout << "Sorting the array in Dutch flag format...\n";
    dutchNationalFlagSort(inputArray, pivotIndex);
    std::cout << "\nResultant array is as follows:\n";
    for ( const int& elem : inputArray) {
        std::cout << elem << " ";
    }
    return 0;
}
