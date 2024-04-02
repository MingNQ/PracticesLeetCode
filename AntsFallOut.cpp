#include <bits/stdc++.h>

using namespace std;

// ====== Last Moment Before All Ants Fall Out of Plank
/* ===> C1

int getMin(vector<int> vt) {
    int min = 10e4;
    for(auto x : vt) {
        if(x < min) min = x;
    }

    return min;
}

int getMax(vector<int> vt) {
    int max = -10e4;
    for(auto x : vt) {
    	if(x > max) max = x;
    }

    return max;
}

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int resR = 0;
    int resL = 0;

    int minR = getMin(right);
    int maxL = getMax(left);

    while(minR < n) {
        minR++;
        resR++;
    } 
    for(int i = maxL; i > 0; i--) {
        resL++;
    }
        
    return resR > resL ? resR : resL; 
}
*/

/* ===> C2

int getLastMoment(int n, vector<int>& left, vector<int>& right) {
    int answer = -1e9;

    for (auto& e : left) {
        answer = max(answer, e);
    }

    for (auto& e : right) {
        answer = max(answer, abs(e - n));
    }

    return answer;
}
*/

int main() {
	return 0;---
}
