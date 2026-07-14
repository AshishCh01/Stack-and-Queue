#include <iostream>
#include <vector>
using namespace std;
string removeKdigits(string num, int k) {
    vector<char> st;

    // Build a monotonic increasing stack
    for (char digit : num) {
        while (!st.empty() && k > 0 && st.back() > digit) {
            st.pop_back();
            k--;
        }
        st.push_back(digit);
    }

    // If removals are still left, remove from the end
    while (k > 0) {
        st.pop_back();
        k--;
    }

    // Build the answer
    string ans = "";
    for (char digit : st) {
        ans += digit;
    }

    // Remove leading zeros
    int i = 0;
    while (i < ans.size() && ans[i] == '0') {
        i++;
    }

    ans = ans.substr(i);

    // If the string is empty, return "0"
    return ans.empty() ? "0" : ans;
}
int main()
{
    string num = "541892";
    int k = 2;
    
    string ans = removeKdigits(num, k);
    
    cout << "The smallest possible integer after removing k digits is: " << ans;
    return 0;

    return 0;
}