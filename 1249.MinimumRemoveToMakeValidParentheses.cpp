#include <iostream>
#include <stack>

using namespace std;

class Solution {
    public:
        string minRemoveToMakeValid(string s) {
            stack<int> st;

            for (int i = 0; i < s.size(); i++) {
                int c = s[i];
                
                if (c == '(') {
                    st.push(i);
                } else if (c == ')') {
                    if (!st.empty()) {
                        st.pop();
                    } else {
                        s[i] = '*';
                    }
                }
            }

            string res = "";    

            while(!st.empty()) {
                s[st.top()] = '*';
                st.pop();
            }

            for (int i = 0; i < s.size(); i++) {
                if (s[i] != '*') {
                    res += s[i];
                }
            }

            return res;
        }
};

main() {
    Solution s;

    string case1 = "lee(t(c)o)de)";
    string case2 = "a)b(c)d";

    cout << s.minRemoveToMakeValid(case1) << endl;
    cout << s.minRemoveToMakeValid(case2) << endl;

}