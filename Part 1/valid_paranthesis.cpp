#include <iostream>
#include <stack>
using namespace std;
bool isValid(string s) {
    stack<char> st;
    int n = s.size();
    for (int i=0; i<n; i++) {
        if(s[i] == '(' || s[i] == '{' || s[i] == '[') {
            st.push(s[i]);
        }
        else {
            if(st.empty()) return false;
            char ch = st.top();
            st.pop();
            
            // Check for matching pair
            if ((s[i] == ')' && ch == '(') ||
                (s[i] == ']' && ch == '[') ||
                (s[i] == '}' && ch == '{'))
                continue;
            else
                return false;
                
            // or
            // if ((s[i] == ')' && top != '(') ||
            //     (s[i] == ']' && top != '[') ||
            //     (s[i] == '}' && top != '{'))
            // {
            //     return false;
            // }
        }
        
    }
    return st.empty();
}
int main()
{
    string s = "()[]{}";
    cout << isValid(s);

    return 0;
}