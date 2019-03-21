// x raised to the power of y
// Author: Sai Prajwal Kotamraju

#include <iostream>
#include <string>

/** @brief xpy Recursive function to calculate x^y with 
 *             minimal computational complexity
 *  @param x Input value that is to be powered up
 *  @param y Exponent value to which x has to be powered to
 */ 
double xpy(double x, int y) {
    // If exponent is less than 0, process can be replicated
    // by inverting x and making y value positive
    if (y<0) {
        x = 1/x; y = -y;
    } else {
        if (y == 0) {
            return 1;
        } else if (y&1) {
            // For odd y, x^y = x*(x^((y/2)*2))
            return x*xpy(x*x, y/2);
        } else {
            // For even y, x^y = x^((y/2)*2)
            return xpy(x*x,y/2);
        }
    }
    return xpy(x,y);
}

int main()
{
    double x; int y;
    std::cout<<"Enter x val: ";
    std::cin>>x;
    std::cout<<"Enter y val: ";
    std::cin>>y;
    std::cout<<x<<" raised to the power of "<<y<<" = "<< xpy(x,y)<<"\n";
}
