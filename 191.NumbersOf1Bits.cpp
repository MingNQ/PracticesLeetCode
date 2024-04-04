#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// C1: Bit Manipulation
//int hammingWeight(uint32_t n) {
//    int ans = 0;
//    while(n>0) {
//        ans += n & 1;
//        n = n >> 1;
//    }
//    return ans;
//}

// C2: Brian Kernighan's Algorithm
int hammingWeight(uint32_t n) {
    int count = 0;
    while (n != 0) {
        n &= (n - 1);
        count++;
    }
    return count;
}
imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    cout << hammingWeight(00000000000000000000000000001011);
}

