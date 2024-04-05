#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int mostBooked(int n, vector<vector<int>>& meetings) {
	sort(meetings.begin(), meetings.end());
	vector<long long> roomAvailTime(n, 0);
	vector<int> meetingCount(n, 0);
	
	for(auto& meeting : meetings) {
		int start = meeting[0], end = meeting[1];
		long long minAvailTime = LLONG_MAX;
		int minTimeRoom = 0;
		bool isUsedRoom = false;
		
		for(int i = 0; i < n; i++) {
			if (roomAvailTime[i] <= start) {
				isUsedRoom = true;
				roomAvailTime[i] = end;
				meetingCount[i]++;
				break;
			}
			
			if (minAvailTime < roomAvailTime[i]) {
				minAvailTime = roomAvailTime[i];
				minTimeRoom = i;
			}
		}
		
		if (!isUsedRoom) { // neu khong tim thay phong trong
			roomAvailTime[minTimeRoom] += end - start;
			meetingCount[minTimeRoom]++;
		}
	}
	int maxMeetingCount = 0, maxMeetingRoom = 0;
	for(int i = 0; i < n; i++) {
		if (meetingCount[i] > maxMeetingCount) {
			maxMeetingCount = meetingCount[i];
			maxMeetingRoom = i;
		}
	}
	
	return maxMeetingRoom;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr); 
    
    vector<vector<int>> meetings = {{0,10}, {1,5}, {2,7}, {3,4}};
    int n = 2;
    
    cout << mostBooked(n, meetings);
}

