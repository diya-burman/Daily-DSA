#include <iostream>
#include <stack>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int priority(char op)
    {
        if (op == '^')
            return 3;
        if (op == '*' || op == '/')
            return 2;
        if (op == '+' || op == '-')
            return 1;
        return -1;
    }

    string preToInfix(string pre_exp)
    {
        int n = pre_exp.size();
        int i = 0;
        stack<char> st;
        string ans = "";

        reverse(pre_exp.begin(), pre_exp.end());

        while (i < n)
        {
            if ((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') ||
                (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') ||
                (pre_exp[i] >= '0' && pre_exp[i] <= '9'))
            {
                ans += pre_exp[i];
            }
            else if (pre_exp[i] == '(')
            {
                st.push(pre_exp[i]);
            }
            else if (pre_exp[i] == ')')
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
                       priority(pre_exp[i]) <= priority(st.top()))
                {
                    ans += st.top();
                    st.pop();
                }
                st.push(pre_exp[i]);
            }
            ++i;
        }

        while (!st.empty())
        {
            ans += st.top();
            st.pop();
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};
