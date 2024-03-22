#include<string>
#include <iostream>
#include <stack>

using namespace std;

bool solution(string s)
{
    bool answer = true;
    stack<char> st;

    for (int i = 0; i < s.length(); i++) {
        if (st.empty()) {
            if (s[i] == ')') {
                answer = false;
                break;
            }
            st.push(s[i]);
        }
        else {
            if (s[i] == '(') {
                st.push(s[i]);
            }
            else {
                if (st.top() != '(') {
                    answer = false;
                    break;
                }
                st.pop();
            }
        }
    }

    if (!st.empty())
        answer = false;

    return answer;
}