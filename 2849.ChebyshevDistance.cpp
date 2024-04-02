#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// - Chebyshev distance between is max(y2 - y1, x2 - x1).
//Logic : 
    // 1. Find shortest distance between two points = d 
    // 2. Chebyshev Distance = max(|x2 - x1|, |y2 - y1|) is the shortest distance between two points with 8 directional adjacency.
    // 3. If t >= d, its always possible to reach the end point at exactly t'th second. 
    // 4. Excess =|t - d| seconds can be wasted on other cell in the infinite 2D plane.
    
class Solution {
public:
    bool isReachableAtTime(int sx, int sy, int fx, int fy, int t) {
        if(sx == fx && sy == fy && t == 1) return false;
        return t >= max(abs(fy-sy), abs(fx-sx));
    }
};

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
}

