#include <iostream>
#include <vector>
#include <stack>

using namespace std;

class Solution {
    public:
    // Approach 1: DP, Form histogram from matrix
        int maximalRectangle(vector<vector<char>> &matrix) {
            int r = matrix.size();

            if (r == 0) return 0;

            int c = matrix[0].size();

            vector<vector<int>> mat(r + 1, vector<int>(c));
            for (int i = 1; i <= r; i++) {
                for (int j = 0; j < c; j++) {
                    mat[i][j] = matrix[i - 1][j] == '1' ? 1 : 0;
                }
            }

            vector<vector<int>> dp(r + 1, vector<int>(c));
            int res = 0;

            // For each row
            for(int i = 1; i <= r; i++) {
                // Left limit
                int leftBound = -1;
                vector<int> left(c);
                stack<int> st;

                for(int j = 0; j < c; j++) {
                    if (mat[i][j] == 1) {
                        // Form histogram
                        mat[i][j] = 1 + mat[i - 1][j];

                        while(!st.empty() && mat[i][st.top()] >= mat[i][j]) 
                            st.pop();

                        int val = leftBound;
                        
                        if (!st.empty()) {
                            val = max(val, st.top());
                        }
                        left[j] = val;
                    } else {
                        leftBound = j;
                        left[j] = 0;
                    }
                    st.push(j);
                }

                // Clear stack
                while(!st.empty()) 
                    st.pop();

                // Right limit
                int rightBound = c;
                for(int j = c - 1; j >= 0; j--) {
                    if (mat[i][j] != 0) {
                        while(!st.empty() && mat[i][st.top()] >= mat[i][j])
                            st.pop();
                        
                        int val = rightBound;
                        if (!st.empty()) {
                            val = min(val, st.top());
                        }

                        dp[i][j] = mat[i][j] * ((val - 1) - (left[j] + 1) + 1);
                        res = max(dp[i][j], res);
                        st.push(j);
                    } else {
                        dp[i][j] = 0;
                        rightBound = j;
                    }
                }
            }
            return res;
        }
};

main() {
    Solution s;
    vector<vector<char>> matrix;

    // Case 1:
    matrix = {{'1','0','1','0','0'},
            {'1','0','1','1','1'},
            {'1','1','1','1','1'},
            {'1','0','0','1','0'}
    };

    cout << s.maximalRectangle(matrix) << endl;

    // Case 2:
    matrix = {{'1'}};

    cout << s.maximalRectangle(matrix) << endl;
}