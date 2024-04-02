#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// ==> C1 Hash - map
//int garbageCollection(vector<string>& garbage, vector<int>& travel) {
//	vector<int> prefixSum(travel.size() + 1, 0);
//	prefixSum[1] = travel[0];
//	for(int i = 1; i < travel.size(); i++) {
//		prefixSum[i + 1] = travel[i] + prefixSum[i];
//	}
//	
//	unordered_map<char, int> garbageLastPos;
//	
//	unordered_map<char, int> garbageCount;
//	
//	for(int i = 0; i < garbage.size(); i++) {
//		for(char c : garbage[i]) {
//			garbageLastPos[c] = i;
//			garbageCount[c]++;
//		}
//	}       
//	
//	char garbageTypes[3] = {'M', 'P', 'G'};
//	int res = 0;
//	
//	for(char c : garbageTypes) {
//		if(garbageCount[c]) {
//			res += prefixSum[garbageLastPos[c]] + garbageCount[c];
//		}
//	}
//	
//	return res;
//}

// ==> C2
/*
garbage = ["G","P","GP","GG"], travel = [2,4,3]

Time to collect all garbage = 1 + 1 + 2 + 2 = 6

Maximum distance for each truck:
G -> 3
P -> 2
M -> 0

Time for each truck to reah its maximum house:
G -> 2 + 4 + 3 = 9
P -> 2 + 4 = 6
M -> 0

Total time = 6 + 9 + 6 + 0 = 21
*/
int garbageCollection(vector<string>& garbage, vector<int>& travel) {
	ll totalMinutes = 0;
	ll currentTravelTime = 0;
	
	totalMinutes += garbage[0].size();
	
	vector<int> lastGarbageIndices(3, -1);
	
	for(int i = 1; i < garbage.size(); i++) {
		totalMinutes += garbage[i].size();
		
		// Update the indice of last occurrence of each type of garbage
		if(garbage[i].find("M") != garbage[i].npos) {
			lastGarbageIndices[0] = i - 1;
		}
		if(garbage[i].find("P") != garbage[i].npos) {
			lastGarbageIndices[1] = i - 1;
		}
		if(garbage[i].find("G") != garbage[i].npos) {
			lastGarbageIndices[2] = i - 1;
		}
	}
	
	for(int i = 0; i < travel.size(); i++) {
		currentTravelTime += travel[i];
		
		// Add the minutes required to collect garbage if a garbage truck is at the corresponding house
		for(int j = 0; j < 3; j++) {
			if(lastGarbageIndices[j] == i) {
				totalMinutes += currentTravelTime;
			}
		}
	}
	
	return totalMinutes;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<string> garbage = {"G","P","GP","GG"};
    vector<int> travel = {2,4,3};
    
    cout << garbageCollection(garbage, travel);
}

