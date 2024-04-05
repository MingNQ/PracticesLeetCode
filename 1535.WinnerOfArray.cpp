#include <bits/stdc++.h>
#define MingO main()
using namespace std;

/* ==> C1
int getWinner(vector<int>& arr, int k) {
    int n = arr.size();
	int max;
	int count = 0;
	
	for(int i = 1; i < n; i++) {
		if(arr[0] > arr[i]) {
			count++;	
			max = arr[0];
		} else if(arr[0] < arr[i]) {
			count = 1;
			max = arr[i];
			int temp = arr[0];
			arr[0] = arr[i];
			arr[i] = temp;
		}
		
		if(count == k) return max;
	}
	  
	return max; 
}
*/

/* ==> C2
int getWinner(vector<int>& arr, int k) {
    int maxElement = arr[0];
    queue<int> queue;
    for (int i = 1; i < arr.size(); i++) {
        maxElement = max(maxElement, arr[i]);
        queue.push(arr[i]);
    }
        
    int curr = arr[0];
    int winstreak = 0;
        
    while (!queue.empty()) {
        int opponent = queue.front();
        queue.pop();
            
        if (curr > opponent) {
            queue.push(opponent);
            winstreak++;
        } else {
            queue.push(curr);
            curr = opponent;
            winstreak = 1;
        }
            
        if (winstreak == k || curr == maxElement) {
            return curr;
        }
	}
        
    return -1;
}
*/

MingO {
	int n;
	cin >> n;
	vector<int> arr;
 	
 	for(int i = 0; i < n; i++) {
 		int x ; cin >> x;
 		arr.push_back(x);
	}
	
	int k; cin >> k;
	
	cout << getWinner(arr, k);
}

