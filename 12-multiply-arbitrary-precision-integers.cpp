// Multiply two arbitrary precision integers (Array-encoded-integers)
// Author: Sai Prajwal Kotamraju

#include <iostream>
#include <vector>

using namespace std;

/** @brief multiplyArr Function to multiply two arbitrary precision integers
 *  @param input1 Array encoded integer 1
 *  @param input2 Array encoded integer 2
 */ 
vector<int> multiplyArr (const vector<int>& input1, 
                         const vector<int>& input2) {
    // Declare the result array and fill it with zeros initially
    // Size of result array is equal to the sum of individual input sizes.
    vector<int> result;
    for (unsigned int i=0; i < input1.size() + input2.size(); ++i) {
        result.push_back(0);
    }
    
    cout << "Displaying result vector step by step\n";
    for (int i = input2.size()-1; i >= 0; --i) {
        int carryIn = 0;
        for (int j = input1.size()-1; j >= 0; --j) {
            int temp = result[i+j+1] + carryIn + input2[i]*input1[j];
            carryIn = static_cast<int>(temp/10);
            result[i+j+1] = temp%10;
        }
        
        // If any carry in, add it to the ith element of result array
        if (carryIn != 0) {
            result[i] += carryIn;
        }
        cout << "Step " << input2.size()-i << ": ";
        for (unsigned int p=0; p<result.size(); ++p) {
            cout << result[p];
        }
        cout << "\n";
    }
    return result;
}

int main()
{
    vector<int>in1 = {9,9,9};
    vector<int>in2 = {9,9,9};
    vector<int> res = multiplyArr(in2, in1);
    cout<< "Final result: ";
    for (unsigned int p=0; p<res.size(); ++p) {
        cout << res[p];
    }
}
