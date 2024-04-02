#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

class Solution {
public:
	int MOD = 1e9 + 7;
	
//==> C1	
//    int countHomogenous(string s) {
//    	int res = 0;
//    	string h;
//        for(int i = 0; i < s.length(); i++) {
//        	h += s[i];
//        	if(s[i + 1] != s[i]) {
//        		res += sum(h);
//        		h = "";
//			}
//		}
//		
//		return res;
//    }
//    
//    long long sum(string h) {
//    	long long n = h.length();
//    	return ((n * (n + 1)) / 2) % MOD;
//	}

// ==> C2	
	int countHomogenous(string s) {
        int res = 0;
		int count = 1;
        
        for(int i = 0; i < s.length(); i++) {
        	if(s[i] != s[i + 1]) {
        		count = 1;
			} else {
				count ++;
			}
            res = (res + count) % MOD;
		}
		
		return res;
    }
	
};

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    Solution sol;
    
    string s = "abbcccaa";
    
    cout << sol.countHomogenous(s);
}

