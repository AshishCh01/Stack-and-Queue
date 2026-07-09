#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

// Function to return precedence
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

// Check operand
bool isOperand(char ch)
{
    return isalnum(ch);
}

// Convert Infix to Prefix
string infixToPrefix(string s)
{
    // Step 1: Reverse the infix expression
    reverse(s.begin(), s.end());

    // Step 2: Swap '(' and ')'
    for (char &ch : s)
    {
        if (ch == '(')
            ch = ')';
        else if (ch == ')')
            ch = '(';
    }

    stack<char> st;
    string ans = "";

    // Step 3: Convert to Postfix
    for (char ch : s)
    {
        if (isOperand(ch))
        {
            ans += ch;
        }
        else if (ch == '(')
        {
            st.push(ch);
        }
        else if (ch == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                ans += st.top();
                st.pop();
            }

            if (!st.empty())
                st.pop();
        }
        else
        {
            while (!st.empty() &&
                   st.top() != '(' &&
                   (precedence(st.top()) > precedence(ch) ||
                   (precedence(st.top()) == precedence(ch) && ch == '^')))
            {
                ans += st.top();
                st.pop();
            }

            st.push(ch);
        }
    }

    while (!st.empty())
    {
        ans += st.top();
        st.pop();
    }

    // Step 4: Reverse postfix to get prefix
    reverse(ans.begin(), ans.end());

    return ans;
}

int main()
{
    string infix = "(A+B)*C-D";

    cout << "Infix  : " << infix << endl;
    cout << "Prefix : " << infixToPrefix(infix) << endl;

    return 0;
}

// OR 
// Function to check if a character is an operator
// bool isOperator(char c) {
//     return (!isalpha(c) && !isdigit(c));  // If the character is neither alphabetic nor numeric, it's an operator
// }

// // Function to return the precedence of operators
// int getPriority(char C) {
//     if (C == '-' || C == '+')  // Addition and subtraction have lowest precedence
//         return 1;
//     else if (C == '*' || C == '/')  // Multiplication and division have higher precedence
//         return 2;
//     else if (C == '^')  // Exponent operator has highest precedence
//         return 3;
//     return 0;
// }

// // Function to convert infix expression to postfix expression
// string infixToPostfix(string infix) {
//     infix = '(' + infix + ')';  // Add parentheses to handle edge cases
//     int l = infix.size();
//     stack<char> char_stack;  // Stack to store operators
//     string ans;  // String to store the resulting postfix expression

//     for (int i = 0; i < l; i++) {

//         // If the scanned character is an operand, add it to ans
//         if (isalpha(infix[i]) || isdigit(infix[i]))
//             ans += infix[i];

//         // If the scanned character is ‘(’, push it to the stack
//         else if (infix[i] == '(')
//             char_stack.push('(');

//         // If the scanned character is ‘)’, pop and ans from the stack until an ‘(‘ is encountered
//         else if (infix[i] == ')') {
//             while (char_stack.top() != '(') {
//                 ans += char_stack.top();
//                 char_stack.pop();
//             }
//             char_stack.pop();  // Remove '(' from the stack
//         }

//         // If an operator is found
//         else {
//             if (isOperator(char_stack.top())) {
//                 if (infix[i] == '^') {
//                     while (getPriority(infix[i]) <= getPriority(char_stack.top())) {
//                         ans += char_stack.top();
//                         char_stack.pop();
//                     }
//                 } else {
//                     while (getPriority(infix[i]) < getPriority(char_stack.top())) {
//                         ans += char_stack.top();
//                         char_stack.pop();
//                     }
//                 }
//                 // Push current operator on stack
//                 char_stack.push(infix[i]);
//             }
//         }
//     }
    
//     // Pop all remaining elements from the stack
//     while (!char_stack.empty()) {
//         ans += char_stack.top();
//         char_stack.pop();
//     }
//     return ans;  // Return the postfix expression
// }

// // Function to convert infix expression to prefix expression
// string infixToPrefix(string infix) {
//     int l = infix.size();

//     // Reverse the infix expression
//     reverse(infix.begin(), infix.end());

//     // Replace '(' with ')' and vice versa
//     for (int i = 0; i < l; i++) {
//         if (infix[i] == '(') {
//             infix[i] = ')';
//             i++;
//         } else if (infix[i] == ')') {
//             infix[i] = '(';
//             i++;
//         }
//     }

//     string prefix = infixToPostfix(infix);  // Convert the modified infix to postfix

//     // Reverse the postfix expression to get the prefix
//     reverse(prefix.begin(), prefix.end());

//     return prefix;  // Return the prefix expression
// }