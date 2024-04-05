#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

void print(vector<int> a) {
	for(int x : a) {
		cout << x << " ";
	}
}

//vector<int> dailyTemperatures(vector<int>& temperatures) {
//	deque<int> q;
//	
//	vector<int> res(temperatures.size(), 0);
//	
//	for(int i = temperatures.size() - 1; i >= 0;--i) {
//		if (q.empty()) {
//			q.push_front(i);
//			res[i] = 0;
//		} else {
//			while(!q.empty() && temperatures[i] >= temperatures[q.front()]) {
//				q.pop_front();
//			}
//			
//			if (q.empty()) {
//				res[i] = 0;
//			} else {
//				res[i] = q.front() - i;
//			}
//			q.push_front(i);
//		}
//	}
//	
//	return res;
//}

vector<int> dailyTemperatures(vector<int>& temperatures) {
	stack<int> st;
	
	vector<int> res(temperatures.size(), 0);
	
	for (int i = temperatures.size() - 1; i >= 0; i--) {
		while(!st.empty() && temperatures[i] >= temperatures[st.top()]) {
			st.pop();
		}
		
		if (!st.empty()) {
			res[i] = st.top() - i;
		} 
		st.push(i);
	}
	return res;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> t = {73,74,75,71,69,72,76,73};
    
    print(dailyTemperatures(t));
}

