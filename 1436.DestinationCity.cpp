#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// C1: Brute Force
//string destCity(vector<vector<string>>& paths) {
//	for(int i = 0; i < paths.size(); i++) {
//		string curr = paths[i][1];
//		bool check = true;
//		
//		for(int j = 0; j < paths.size(); j++) {
//			if (paths[j][0] == curr) {
//				check = false;
//				break;
//			}
//		}
//		
//		if (check) {
//			return curr;
//		}
//	}
//	
//	return "";        
//}

// C2: Hash set
string destCity(vector<vector<string>>& paths) {
	unordered_set<string> s;
        
    for(int i = 0; i < paths.size(); i++) {
        s.insert(paths[i][0]);
    }
        
    for(int j = 0; j < paths.size(); j++) {
        string curr = paths[j][1];   
        if (s.find(curr) == s.end()) {
           return curr;
        }
    }
        
    return "";    
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<vector<string>> paths = {{"B","C"},{"D","B"},{"C","A"}};
    
    cout << destCity(paths);
}

