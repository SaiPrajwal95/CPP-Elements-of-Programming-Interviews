// Enumerate primes till N
// Author: Sai Prajwal Kotamraju
#include <iostream>
#include <vector>

/**
 * @brief Returns an array of prime numbers between 1 and N
 * @param N Target number till which primes are to be found
 */ 
std::vector<int> primesTillN(unsigned int N) {
    std::vector<int> outArr; 
    if (N <= 1) {
        return outArr;
    } else {
        outArr.emplace_back(2);
        for (unsigned int i = 3; i <= N; ++i) {
            bool flag = 1;
            for (const int& pr: outArr) {
                if (i % pr == 0) {
                    flag = 0;
                    break;
                }
            }
            if (flag) {
                outArr.emplace_back(i);
            }
        }
        return outArr;
    }
}       

int main()
{
    unsigned int N = 30;
    std::vector<int> p = primesTillN(N);
    // Printing the output
    std::cout << "Primes till " << N << " are as follows: \n";
    for (unsigned int k = 0; k < p.size(); ++k) {
        std::cout << p[k] << ", ";
    }
    return 0;
}
