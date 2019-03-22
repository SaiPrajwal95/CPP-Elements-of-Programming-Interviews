// Intersection between two rectangles
// Author: Sai Prajwal Kotamraju

#include <iostream>

// Rect structure holds the x, y, 
// width, and height float variables
struct Rect {
    float x,y,w,h;
};

/** @brief maxVal Simple function to return max 
 *                value between two float values
 *  @param x first input float value
 *  @param y second input float value
 */ 
float maxVal (float x, float y) {
    float res = (x >= y) ? x : y;
    return res;
}

/** @brief minVal Simple function to return min 
 *                value between two float values
 *  @param x First input float value
 *  @param y Second input float value
 */ 
float minVal (float x, float y) {
    float res = (x <= y) ? x : y;
    return res;
}

/** @brief intersectionRect Function that returns intersection rectangle 
 *                          between two Rect objects passed as input
 *  @param A First input Rect object
 *  @param B Second input Rect object
 */ 
Rect intersectionRect (Rect A, Rect B) {
    float Ax2 = A.x + A.w;
    float Ay2 = A.y + A.h;
    float Bx2 = B.x + B.w;
    float By2 = B.y + B.h;
    
    // If the x2 value of A Rect object is less than x value
    // of B Rect object, the rectangles won't intersect. Same
    // with the case of y values.
    if ((Ax2 < B.x) || (Ay2 < B.y)) {
        return {0, 0, -1, -1}; // Rect obj indicating no intersection
    }
    return {maxVal(A.x, B.x), maxVal(A.y, B.y),
            minVal(Ax2, Bx2) - maxVal(A.x, B.x), 
            minVal(Ay2, By2) - maxVal(A.y, B.y)};
}

/** @brief IoUVal Function that calculates and returns the IoU score
 *                between the two Rect object inputs
 *  @param A First Rect object
 *  @param B Second Rect object
 */ 
float IoUVal (Rect A, Rect B) {
    float areaA = A.w * A.h;
    float areaB = B.w * B.h;
    Rect intrRes = intersectionRect (A, B);
    if ((intrRes.x == 0) &&
        (intrRes.y == 0) &&
        (intrRes.w == -1) &&
        (intrRes.h == -1)) {
        return 0;
    } else {
        float areaIntersection = intrRes.w * intrRes.h;
        return (areaIntersection/(areaA + areaB - areaIntersection));
    }
}

int main() {
    Rect A, B, C;
    // First input Rect object
    A = {0,0,4,5};
    // Second input Rect object
    B = {-2,-1,4,7};
    // Rect object formed due to intersection of A and B
    C = intersectionRect(A,B);
    std::cout << "Intersection between A and B is: ";
    std::cout << "{" << C.x << ", " <<
                        C.y << ", " <<
                        C.w << ", " <<
                        C.h << "}\n"; 
    std::cout << "IoU score between A and B is :" << IoUVal(A, B);
    return 0;
}
