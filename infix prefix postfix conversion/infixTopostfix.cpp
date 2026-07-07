#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char ch)
{
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/' || ch == '%')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;

    return -1;
}

// Function to check whether character is operand
bool isOperand(char ch)
{
    return (isalnum(ch));
}

// Function to convert Infix to Postfix
string infixToPostfix(string s)
{
    stack<char> st;
    string ans = "";

    for (char ch : s)
    {
        // Operand
        if (isOperand(ch))
        {
            ans += ch;
        }

        // Opening bracket
        else if (ch == '(')
        {
            st.push(ch);
        }

        // Closing bracket
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop(); // Remove '('
        }

        // Operator
        else
        {
            while (!st.empty() &&
                   st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) && ch != '^')))
            {
                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    // Pop remaining operators
    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    return ans;
}

int main()
{
    string infix = "(A+B)*C-D";

    cout << "Infix   : " << infix << endl;
    cout << "Postfix : " << infixToPostfix(infix) << endl;

    return 0;
}

// OR
// void infixToPostfix(string s) {
//     stack<char> st; // Stack to hold operators and parentheses
//     string result;  // String to hold the resulting postfix expression

//     for (int i = 0; i < s.length(); i++) {
//         char c = s[i];

//         // If the scanned character is an operand, add it to the result string
//         if ((c >= 'a' && ch <= 'z') || (c >= 'A' && ch <= 'Z') || (c >= '0' && c <= '9'))
//             result += c;

//         // If the scanned character is an ‘(‘, push it to the stack
//         else if (c == '(')
//             st.push('(');

//         // If the scanned character is a ‘)’, pop from stack until an ‘(‘ is encountered
//         else if (c == ')') {
//             while (st.top() != '(') {
//                 result += st.top();
//                 st.pop();
//             }
//             st.pop();  // Pop the ‘(‘ from the stack
//         }

//         // If an operator is scanned
//         else {
//             while (!st.empty() && precedence(s[i]) <= precedence(st.top())) {
//                 result += st.top();
//                 st.pop();
//             }
//             st.push(c);  // Push the current operator to the stack
//         }
//     }

//     // Pop all the remaining elements from the stack
//     while (!st.empty()) {
//         result += st.top();
//         st.pop();
//     }

//     cout << "Postfix expression: " << result << endl;  // Output the result
// }