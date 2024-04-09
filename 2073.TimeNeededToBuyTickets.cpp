#include <iostream>
#include <vector>
#include <queue>

using namespace std;

class Solution {
    public:
    // Approach 1: One Pass

    /*
        int timeRequiredToBuy(vector<int> tickets, int k) {
            int res = 0;

            for (int i = 0; i < tickets.size(); i++) {
                if (i <= k) {
                    res += min(tickets[i], tickets[k]);
                } else {
                    res += min(tickets[i], tickets[k] - 1);
                }
            }
            return res;
        }
    */

    // Approach 2: Use Queue
        int timeRequiredToBuy(vector<int> tickets, int k) {
            queue<int> q;

            for(int i = 0; i < tickets.size(); i++) {
                q.push(i);
            }
            int res = 0;
            while(!q.empty()) {
                int curr = q.front();
                q.pop();

                res++;
                tickets[curr]--;

                if (k == curr && tickets[curr] == 0) 
                    return res;

                if (tickets[curr] != 0) {
                    q.push(curr);
                }
            }
            return res;
        }
};

main() {
    Solution s;

    // Case 1
    vector<int> tickets = {2,3,2};
    int k = 2;

    cout << s.timeRequiredToBuy(tickets, k) << endl;

    // Case 2
    tickets = {5,1,1,1};
    k = 0;

    cout << s.timeRequiredToBuy(tickets, k) << endl;
}