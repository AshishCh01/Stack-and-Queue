#include <bits/stdc++.h>
using namespace std;

int trap(vector<int>& height) {
    int n = height.size();

    // If there are less than 3 bars, no water can be trapped
    if (n < 3)
        return 0;

    vector<int> leftMax(n), rightMax(n);

    // Fill leftMax array
    leftMax[0] = height[0];
    for (int i = 1; i < n; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }

    // Fill rightMax array
    rightMax[n - 1] = height[n - 1];
    for (int i = n - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    // Calculate trapped water
    int water = 0;
    for (int i = 0; i < n; i++) {
        water += min(leftMax[i], rightMax[i]) - height[i];
    }

    return water;
}

int main() {
    vector<int> height = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};

    cout << "Total Trapped Water: " << trap(height) << endl;

    return 0;
}