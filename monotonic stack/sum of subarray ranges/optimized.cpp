#include <iostream>
#include <vector>
using namespace std;
long long subArrayRanges(vector<int>& arr) {
    long long sum = 0;
    int n = arr.size();
    for (int i=0; i<n; i++) {
        int largest = arr[i], smallest = arr[i];
        for(int j=i+1; j<n; j++) {
            largest = max(largest, arr[j]);
            smallest = min(smallest, arr[j]);
            sum = sum + (largest - smallest);
        }
    }
    return sum;
}
int main()
{
    vector<int> arr = {1,2,3};
    cout << subArrayRanges(arr);

    return 0;
}

// T.C - O(n^2)
// S.C - O(1)