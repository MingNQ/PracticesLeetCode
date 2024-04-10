#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Solution {
    public:

    // Approach 1: Using queue
        /*
        vector<int> deckRevealedIncreasing(vector<int> &deck) {
            int n = deck.size();    
            sort(deck.begin(), deck.end());
            queue<int> q;

            for(int i = 0; i < n; i++) {
                q.push(i);
            }

            vector<int> res(n);
            int i = 0;
            while (!q.empty()) {
                int curr = q.front();
                q.pop();
                res[curr] = deck[i];
                i++;
                q.push(q.front());
                q.pop(); 
            }
            return res;
        }
        */

    // Approach 2: Two pointers
        vector<int> deckRevealedIncreasing(vector<int> &deck) {
            int n = deck.size();
            sort(deck.begin(), deck.end());

            int i = 0;
            int j = 0;
            bool skip = false;

            vector<int> res(n);

            while(j < n) {
                if (res[i] == 0) {
                    if (!skip) {
                        res[i] = deck[j];
                        j++;
                    }
                    skip = !skip;
                }
                i = (i + 1) % n;
            }

            return res;
        }

        void print(const vector<int> &a) {
            for(int i : a) 
                cout << i << " ";
            cout << endl;
        }

};

main() {
    Solution s;

    // Case 1
    cout << "Case 1" << endl;
    vector<int> deck = {2,13,3,11,5,17,7};

    s.print(s.deckRevealedIncreasing(deck));
    
    // Case 2:
    deck = {1,1000};

    cout << "Case 2" << endl;
    s.print(s.deckRevealedIncreasing(deck));
}