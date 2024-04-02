#include <bits/stdc++.h>

using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t) {
            int n = s.length();

            unordered_map<char, char> mp1, mp2;

            for(int i = 0; i < n; i++) {
                char left = s[i], right = t[i];

                if (mp1.count(left) == 0 && mp2.count(right) == 0) {
                    mp1[left] = right;
                    mp2[right] = left;
                } else {
                    if (mp1[left] != right || mp2[right] != left) return false;
                }
            }
            return true;
        }
};

int main() {
	Solution s;
    cout << s.isIsomorphic("paper", "title");

    return 0;
}
