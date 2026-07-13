#include <bits/stdc++.h>
using namespace std;
vector<int> asteroidsCollision(vector<int>& asteroids) {
    int n = asteroids.size();   
    vector<int> st;
    for (int i=0; i<n; i++) {
        if(asteroids[i] > 0) {
            st.push_back(asteroids[i]);
        }
        else {
            while(!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                st.pop_back();
            }
            if(!st.empty() && st.back() == abs(asteroids[i])) {
                st.pop_back();
            }
            else if (st.empty() || st.back() < 0) {
                st.push_back(asteroids[i]);
            }
        }
    }
    return st;
}
int main()
{
    vector<int> asteroids = {3,5,-6,2,-1,4};
    vector<int> result = asteroidsCollision(asteroids);
    for (int x : result) {
        cout << x << " ";
    }

    return 0;
}