#include <iostream>
#include <stack>
using namespace std;

class Solution
{
public:
    string postToPre(string post_exp)
    {
        int n = post_exp.size();
        int i = 0;
        stack<string> st;
        while (i < n)
        {
            if ((post_exp[i] >= 'A' && post_exp[i] <= 'Z') || (post_exp[i] >= 'a' && post_exp[i] <= 'z') || (post_exp[i] >= '0' && post_exp[i] <= '9'))
            {
                st.push(string(1, post_exp[i]));
            }
            else
            {
                string t1 = st.top();
                st.pop();
                string t2 = st.top();
                st.pop();
                string converted_string = post_exp[i] + t2 + t1;
                st.push(converted_string);
            }
            i++;
        }
        return st.top();
    }
};