#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string preToPost(string pre_exp)
    {
        int n = pre_exp.size();
        int i = n - 1;
        stack<string> st;

        while (i >= 0)
        {
            if ((pre_exp[i] >= 'A' && pre_exp[i] <= 'Z') || (pre_exp[i] >= 'a' && pre_exp[i] <= 'z') || (pre_exp[i] >= '0' && pre_exp[i] <= '9'))
            {
                st.push(string(1, pre_exp[i]));
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string converted_string = t1 + t2 + pre_exp[i];
                st.push(converted_string);
            }
            i--;
        }
        return st.top();
    }
};