// Reverse bits in a number
// Author: Sai Prajwal Kotamraju
#include <iostream>
#include <cmath> // For pow() function

/** @brief swapBitsInNum Swaps the ith and jth bits of a given number
 *  @param num Number whose ith and jth bits are to be swapped
 *  @param i Bit position which is to be swapped jth bit
 *  @param j Bit position which is to be swapped ith bit
 */
unsigned long swapBitsInNum (unsigned long num, int i, int j) {
    // Creates a bit mask with high bits at ith and jth position
    unsigned long bitMask = (1L<<i) | (1L<<j);
    // Reverses the ith and jth bits of a number  
    num ^= bitMask;
    return num;
}

/** @brief reverseBitsInNum Reverses bit order for a given number
 *  @param Num Number whose bits are to be reversed
 */
unsigned long reverseBitsInNum (unsigned long Num) {
    for (int i=0; i<32; ++i) {
        // If ith and (64-i-1)th bit are not same, swap them
        if (((Num>>i)&1)!=((Num>>(64-i-1))&1)) {
            Num = swapBitsInNum(Num, i, 64-i-1);
        }
    }
    return Num;
}

int main()
 {
    std::cout<<reverseBitsInNum(pow(2,62)+pow(2,63));
    return 0;
}
