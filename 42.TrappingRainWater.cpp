#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

class Solution {
    public:
    // Approach 1: Two Pointers
    /*
        int trap(std::vector<int> &height) {
            int n = height.size();

            std::vector<int> left(n); left[0] = height[0];
            std::vector<int> right(n); right[n - 1] = height[n - 1];   

            int res = 0;
            for(int i = 1; i < n; i++) {
                left[i] = std::max(left[i - 1], height[i]);
            }

            for(int i = n - 2; i >= 0; i--) {
                right[i] = std::max(right[i + 1], height[i]);
            }

            for(int i = 0; i < n; i++) {
                res += std::min(left[i], right[i]) - height[i];
            }

            return res;
        }
    */

    // Approach 2: Using Stack
        int trap(std::vector<int> &height) {
            int n = height.size();
            int res = 0;

            std::stack<int> st;
            for(int r = 0; r < n; r++) {
                while(!st.empty() && height[st.top()] < height[r]) {
                    int m = st.top();
                    st.pop();
                    if (st.empty()) break;
                    int l = st.top();
                    int h = std::min(height[r] - height[m], height[l] - height[m]);
                    int w = r - l - 1;
                    res += h*w; 
                }
                st.push(r);
            }
            return res;
        }
};

main() {
    Solution s;
    std::vector<int> height;

    // Case 1
    height = {0,1,0,2,1,0,1,3,2,1,2,1};
    std::cout << "Case 1: " << std::endl;
    std::cout << s.trap(height) << std::endl;

    // Case 2
    height = {4,2,0,3,2,5};
    std::cout << "Case 2: " << std::endl;
    std::cout << s.trap(height) << std::endl;
}