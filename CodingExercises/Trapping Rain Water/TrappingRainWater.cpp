#include <iostream>
#include <vector>
using namespace std;

int trap(vector<int>& height) {
    if (height.size() < 3) return 0;
    
    register int i = 0, j = height.size() - 1;
    register int leftMax = 0, rightMax = 0, water = 0;
    
    while (i <= j) {
     
        if (height[i] > leftMax) leftMax = height[i];
        if (height[j] > rightMax) rightMax = height[j];
     
        if (leftMax <= rightMax) {
            water += leftMax - height[i];
            ++i;
        } else {
            water += rightMax - height[j];
            --j;
        }        
    }
    
    return water;
}