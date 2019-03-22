// Intersection between two rectangles
// Author: Sai Prajwal Kotamraju
#include <iostream>
#include <cmath>

struct Rect {
    float x,y,w,h;
};

float maxVal (float x, float y) {
    float res = (x >= y) ? x : y;
    return res;
}

float minVal (float x, float y) {
    float res = (x <= y) ? x : y;
    return res;
}

Rect intersectionRect (Rect A, Rect B) {
    float Ax2 = A.x + A.w;
    float Ay2 = A.y + A.h;
    float Bx2 = B.x + B.w;
    float By2 = B.y + B.h;
    if ((Ax2 < B.x) || (Ay2 < B.y)) {
        return {0, 0, -1, -1};
    }
    return {maxVal(A.x, B.x), maxVal(A.y, B.y),
            minVal(Ax2, Bx2) - maxVal(A.x, B.x), 
            minVal(Ay2, By2) - maxVal(A.y, B.y)};
}

int main() {
    Rect A, B, C;
    A = {0,0,4,5};
    B = {-2,-1,2,1};
    C = intersectionRect(A,B);
    std::cout << "{" << C.x << ", " <<
                        C.y << ", " <<
                        C.w << ", " <<
                        C.h << "}"; 
    return 0;
}
