//Valid Parentheses
/* Given a string s containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Every close bracket has a corresponding open bracket of the same type.*/


//use a stack and when encountering '(' '{' or ']' push to the top of stack, when I encounter ')' '}' or ']' check if the top of the stack was the oopening for it.
//if it is pop it from the stack, otherwise return false


#include<string>
#include<stack>

using namespace std;
class Solution 
{
    public:
        bool isValid(string s) 
        {
            stack<char>st;

            for (int i = 0; i < s.size(); i++)
            {
                if(s[i] == '(' || s[i] == '{' || s[i] == '[')
                {
                    st.push(s[i]);
                }
                
                else
                {
                    if (st.empty())
                    {
                        return false;
                    }

                    char top = st.top();
                    if (s[i] == ')' && top == '(' || s[i] == '}' && top == '{' || s[i] == ']' && top == '[')
                    {
                        st.pop();
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            return st.empty();
        }
};