#include <iostream>
#include <stack>
#include <algorithm>

class Solution {
    public:
        std::string removeKdigits(std::string num, int k) {
            std::stack<char> st;


            for(char c : num) {
                while (!st.empty() && k > 0 && st.top() > c) {
                    st.pop();
                    k--;
                }

                if (st.size() || c != '0') st.push(c);
            }

            while(!st.empty() && k > 0) {
                st.pop();
                k--;
            }

            std::string res = "";
            while(!st.empty()) {
                res += st.top();
                st.pop();
            }
            
            std::reverse(res.begin(), res.end());

            return res.size() == 0 ? "0" : res;
        }
};

main() {
    Solution s;
    std::string num;
    int k;
    // Case 1:
    num = "1432219";
    k = 3;
    std::cout << s.removeKdigits(num, k) << std::endl;

    // Case 2
    num = "10200";
    k = 1;
    std::cout << s.removeKdigits(num, k) << std::endl;
}