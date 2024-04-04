#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

class Solution {
public:
    int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
        ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
        int n = dist.size();
        vector<float> arrival;
        int res = 0;
        for(int i = 0; i < n; i++) {
        	arrival.push_back((float)dist[i]/speed[i]);
		}
		
		sort(arrival.begin(), arrival.end());
		
		for(int i = 0; i < n; i++) {
			if(arrival[i] <= i) break;
            res++;
		}
        return res; 
    }
};

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Solution s;
    int n;
    cin >> n;
    vector<int> dist;
    vector<int> speed;
	

	for(int i = 0; i < n; i++) {
	    int x; cin >> x;
	    dist.push_back(x);
	}
		
	for(int i = 0; i < n; i++) {
	    int x; cin >> x;
	    speed.push_back(x);
	}
	
    cout << s.eliminateMaximum(dist, speed);
}

