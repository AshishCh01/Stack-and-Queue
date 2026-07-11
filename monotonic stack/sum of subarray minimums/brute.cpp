
#include <iostream>
#include <vector>
using namespace std;
int sumSubarrayMins(vector<int>& arr) {
    int n = arr.size();
    int sum = 0;
    int mod = 1e9 + 7; // Mod value
    for (int i=0; i<n; i++) {
        int mini = arr[i];
        for (int j=i; j<n; j++) {
            mini = min(mini, arr[j]);
            sum = (sum+mini) % mod;
        }
    }
    return sum;
}
int main()
{
    vector<int> arr = {3,1,2,4};
    cout << sumSubarrayMins(arr);
    return 0;
}