#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

//int numberOfBeams(vector<string>& bank) {
//	vector<int> sum(bank.size(), 0);
//	
//	for(int i = 0; i < bank.size(); i++) {
//		for(int j = 0; j < bank[i].length(); j++) {
//			if (bank[i][j] == '1') sum[i]++;
//		}
//	}        
//	
//	int res = 0;
//	
//	for(int i = 0; i < sum.size() - 1; ) {
//		int j = i + 1;
//		
//		while(!sum[j]) {
//			j++;
//		}
//		
//		if (sum[i] == 0 || j > sum.size()) {
//			i++;
//		} else {
//			res += sum[i]*sum[j];
//			i = j;
//		}
//	}
//	
//	return res;
//}

int numberOfBeams(vector<string>& bank) {
	int res = 0, prev = 0;
	for(string s : bank) {
		int count = 0;
		for(char c : s) {
			if (c == '1') {
				count++;
			}
		}
		
		if (count) {
			res += (prev * count);
			prev = count;
		}
	}
	
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<string> bank = {"011001","000000","010100","001000"};
    
    cout << numberOfBeams(bank);
    
}

