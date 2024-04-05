#include <iostream>
#include <stack>
using namespace std;

class Solution {
    public:
        string makeGood(string s) {
            stack<char> st;
            for(char c : s) {
                if (!st.empty() && abs(c - st.top()) == 32) 
                    st.pop();
                else 
                    st.push(c);
            }
            string res = "";

            while(!st.empty()) {
                res = st.top() + res;
                st.pop();
            }

            return res;
        }

};

main() {
    Solution s;
    string case1 = "leEeetcode";
    string case2 = "abBAcC";

    cout << s.makeGood(case1) << endl;
    cout << s.makeGood(case2) << endl;
}