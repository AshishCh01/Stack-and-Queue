#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check if character is an operand
bool isOperand(char ch)
{
    return isalnum(ch);
}

// Convert Prefix to Postfix
string prefixToPostfix(string prefix)
{
    stack<string> st;

    // Traverse from right to left
    for (int i = prefix.length() - 1; i >= 0; i--)
    {
        char ch = prefix[i];

        // Operand
        if (isOperand(ch))
        {
            st.push(string(1, ch));
        }
        // Operator
        else
        {
            string op1 = st.top();
            st.pop();

            string op2 = st.top();
            st.pop();

            string temp = op1 + op2 + ch;

            st.push(temp);
        }
    }

    return st.top();
}

int main()
{
    string prefix = "*+ABC";

    cout << "Prefix  : " << prefix << endl;
    cout << "Postfix : " << prefixToPostfix(prefix) << endl;

    return 0;
}