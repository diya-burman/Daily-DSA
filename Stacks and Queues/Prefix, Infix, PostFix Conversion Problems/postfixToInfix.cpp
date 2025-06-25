#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string postToInfix(string exp)
    {
        int n = exp.size();
        int i = 0;
        stack<string> st;

        while (i < n)
        {
            if ((exp[i] >= 'A' && exp[i] <= 'Z') || (exp[i] >= 'a' && exp[i] <= 'z') || (exp[i] >= '0' && exp[i] <= '9'))
            {
                st.push(string(1, exp[i])); // Convert char to string
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string converted_string = '(' + t2 + exp[i] + t1 + ')';
                st.push(converted_string);
            }
            i++;
        }
        return st.top();
    }
};