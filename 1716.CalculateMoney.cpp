#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// C1
//int totalMoney(int n) {
//	int res = 0;	 
//	int money = 0;
//	int total = 1;
//	for(int i = 0; i < n; i++) {
//		if(i % 7 == 0 && i >= 7) {
//			money++;
//			total = 1;
//		}
//		res += total + money;
//		total++;
//	}    
//	
//	return res;
//}

// C2: Math

int totalMoney(int n) {
	int k = n / 7;  // Count how many full week? 
	int F = 28;    // The first full week has sum is 28
	int L = 28 + (k - 1) * 7; // The last full week has sum is L
	int arithmeticSum = k * (F + L) / 2; // Sum of k full week
	
	// Work on other day left, that is not full week
	int monday = 1 + k;
	int finalWeek = 0;
	
	for(int i = 0; i < n % 7; i++) {
		finalWeek += monday + i;
	} 
	
	return arithmeticSum + finalWeek;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
	
	int n = 20;
	
	cout << totalMoney(n);
}

