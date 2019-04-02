// Identify the duplicate elements from a sorted array and return the number of unique elements
// Author: Sai Prajwal Kotamraju

#include <iostream>
#include <vector>

/** @brief nonRepetitiveFirst Function that places all the unique elements of the array at the
 *                            begining and pushes the repetitions to the end. Also, it returns
 *                            the number of unique elements in the supplied input
 * @param inputArr Input array in which duplicate elements are to be pushed to the end.
 */ 
int nonRepetitiveFirst (std::vector<int>& inputArr) {
    int writeIndex =1;
    for (unsigned int i=1; i<inputArr.size(); ++i) {
        if (inputArr[writeIndex - 1] != inputArr[i]) {
            inputArr[writeIndex++] = inputArr[i];
        }
        
        // To see the changes happening for each iteration
        std::cout << "Step " << i << ": ";
        for (unsigned int k=0; k<inputArr.size(); ++k) {
            std::cout << inputArr[k] << " ";
        }
        std::cout << "\n";
    }
    return writeIndex;
}

int main()
{
    std::vector<int> input = {1,2,2,3,4,5,8,8,8,10,12,12};
    int uniqueElements = nonRepetitiveFirst (input);
    
    // Final output
    std::cout << "Array after keeping non-repetiitive elements first: \n";
    for (unsigned int k=0; k<input.size(); ++k) {
        std::cout << input[k] << " ";
    }
    std::cout << "\n";
    
    // Unique elements printing
    std::cout << "Unique elements of the input array are:\n";
    for (int k=0; k<uniqueElements; ++k) {
        std::cout << input[k] << ", ";
    }
    return 0;
}

