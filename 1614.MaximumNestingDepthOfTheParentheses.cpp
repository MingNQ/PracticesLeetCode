#include <iostream>
#include <stack>

using namespace std;

class Solution {
    public:
        int maxDepth(string s) {
            int count = 0, res = 0;

            for (char c : s) {
                if (c == '(') count++;
                else if (c == ')') count--;
                res = max(res, count);
            }

            return res;
        } 
        
};

int main()
{
    Solution s;
    string case1 = "(1+(2*3)+((8)/4))+1";
    string case2 = "(1)+((2))+(((3)))";

    cout << s.maxDepth(case1) << endl;
    cout << s.maxDepth(case2) << endl;
    
    return 0;
}
