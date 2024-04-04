#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
	unordered_map<int, vector<pair<int, int>>> adj;
	
	for(auto& flight : flights) {
		adj[flight[0]].push_back({flight[1], flight[2]});
	}
	
	// min distance/ price
	vector<int> dist(n, INT_MAX);
	dist[src] = 0;
	
	queue<pair<int, int>> q;
	q.push({src, 0});
	int stops = 0; // count times stop
	
	// BFS
	while(!q.empty() && stops <= k) {
		int sz = q.size();
		
		while(sz-- > 0) {
			auto [node, distance] = q.front();
			q.pop();
			
			if (!adj.count(node)) continue;
			
			for(auto& [neighbour, price] : adj[node]) {
				if (distance + price >= dist[neighbour]) continue;
				dist[neighbour] = distance + price;
				q.push({neighbour, dist[neighbour]});
			}	
		}
		stops++;
	}
	return dist[dst] == INT_MAX ? -1 : dist[dst];
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    int n = 4;
    vector<vector<int>> flights = {
		{0, 1, 100},  {1, 2, 100},  {2, 0, 100}, {1, 3, 600}, {2, 3, 200}
	};
	int src = 0, dst = 3, k = 1;
	
	cout << findCheapestPrice(n, flights, src, dst, k);
}

