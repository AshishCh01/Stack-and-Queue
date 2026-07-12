#include <iostream>
#include <vector>
#include <climits>
using namespace std;

long long subArrayRanges(vector<int>& nums) {
    int n = nums.size();
    long long ans = 0;

    for (int i = 0; i < n; i++) {

        for (int j = i; j < n; j++) {

            int mini = INT_MAX;
            int maxi = INT_MIN;

            // Find min and max in current subarray
            for (int k = i; k <= j; k++) {
                mini = min(mini, nums[k]);
                maxi = max(maxi, nums[k]);
            }

            ans += (long long)(maxi - mini);
        }
    }

    return ans;
}

int main()
{
    vector<int> arr = {1,2,3};
    cout << subArrayRanges(arr);

    return 0;
}

// T.C - O(n^3)