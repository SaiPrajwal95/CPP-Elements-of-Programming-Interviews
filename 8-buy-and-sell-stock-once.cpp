// Program to find maximum profit that can be obtained by
// buying and selling stocks given a vector of stock prices
// at the start of the day.
// Author: Sai Prajwal Kotamraju

#include <iostream>
#include <limits>
#include <vector>

/** @brief findMaxProfit Function that takes in vector of stock prices
 *                       at the start of the day and returns the max profit
 *  @param S vector having stock prices as double values
 */ 
double findMaxProfit (const std::vector<double>& S) {
    
    double maxProfit = 0; // When all the stock values decrease monotonically
                          // there's no profit.
    double minStockPrice = std::numeric_limits<double>::max(); // Gives max possible
                                                               // double value
    
    // for-each implementation
    for (const double& stockVal : S) {
        // If difference between currentStockVal and minStockVal till now
        // is greater than the maxProfit observed till this iteration, replace
        // the observed maxProfit to the difference value
        if (stockVal - minStockPrice > maxProfit) {
            maxProfit = stockVal - minStockPrice;
        }
        // If the stockVal is less than minStockVal till this iteration,
        // replace the minStockVal with the currentStockVal
        if (stockVal < minStockPrice) {
            minStockPrice = stockVal;
        }
    }
    return maxProfit;
}

int main()
{
    std::vector<double> sellPrices;
    std::cout << "Enter the stock prices at the start of the day\n";
    std::cout << "Enter -1 to end the input process\n";
    std::cout << "Start\n";
    while (true) {
        double priceVal;
        std::cin >> priceVal; 
        if (priceVal != -1) {
            sellPrices.push_back(priceVal);
        } else {
            break;
        }
    }
    std::cout << "Maximum profit obtained by buying and selling a stock" <<
                 " at the start of the day = " << findMaxProfit (sellPrices) << 
                 std::endl;
    return 0;
}
