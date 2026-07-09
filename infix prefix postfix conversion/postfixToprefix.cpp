#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Check if character is an operand
bool isOperand(char ch)
{
    return isalnum(ch);
}

// Convert Postfix to Prefix
string postfixToPrefix(string postfix)
{
    stack<string> st;

    for (char ch : postfix)
    {
        // Operand
        if (isOperand(ch))
        {
            st.push(string(1, ch));
        }
        // Operator
        else
        {
            string op2 = st.top();
            st.pop();

            string op1 = st.top();
            st.pop();

            string temp = ch + op1 + op2;

            st.push(temp);
        }
    }

    return st.top();
}

int main()
{
    string postfix = "AB+C*";

    cout << "Postfix : " << postfix << endl;
    cout << "Prefix  : " << postfixToPrefix(postfix) << endl;

    return 0;
}