#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int trap(vector<int>& height) {
    int total = 0;
    int n = height.size();
    // Iterate over each bar in the elevation map
    for(int i=0; i<n; i++) {
         // Initialize max heights to the left and right of current bar
        int leftMax = height[i]; // or 0;
        int rightMax = height[i]; // or 0
        
         // Find maximum height to the left of current bar
        for (int j = 0; j <= i; j++) {
            if (height[j] > leftMax) {
                leftMax = height[j];
            }
        }
        
        // Find maximum height to the right of current bar
        for (int j = i; j < n; j++) {
            if (height[j] > rightMax) {
                rightMax = height[j];
            }
        }
            
        // Water trapped on current bar is min of maxLeft and maxRight minus current height
        total += min(leftMax, rightMax) - height[i];
    }
    return total;
}
int main()
{
    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    cout << trap(height);
    return 0;
}