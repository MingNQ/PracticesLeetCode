#include <iostream>

using namespace std;

class Solution {
    public:
        bool checkValidString(string s) {
            int open = 0;
            int close = 0;
            int len = s.length() - 1;
            for(int i = 0; i < len; i++) {
                if (s[i] == '(' || s[i] == '*') {
                    open++;
                } else {
                    open--;
                }

                if (s[len - i] == ')' || s[len - i] == '*') {
                    close++;
                } else {
                    close--;
                }

                if (open < 0 || close < 0) return false;
            }
            return true;
        }

};

main() {
    Solution s;

    string case1 = "(*)";
    string case2 = "(*))";

    cout << s.checkValidString(case1) << endl;
    cout << s.checkValidString(case2) << endl;

}
