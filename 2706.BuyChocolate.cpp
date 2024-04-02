#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// C1: Two pair
//int buyChoco(vector<int>& prices, int money) {
//	int min = INT_MAX;
//	bool isMin = false;
//	for(int i = 0; i < prices.size() - 1; i++) {
//		for(int j = i + 1; j < prices.size(); j++) {
//			int buy = prices[i] + prices[j];
//			
//			if (buy < min) {
//				min = buy;	
//				isMin = true;
//			}
//			
//			if (min > money) {
//				isMin = false;
//			}
//		}
//	}      
//	
//	if (isMin) money -= min;
//	
//	return money;
//}

// C2: Greedy
//int buyChoco(vector<int>& prices, int money) {
//	sort(prices.begin(), prices.end());
//	int buy = prices[0] + prices[1];
//	if (money >= buy) {
//		return money - buy;
//	}
//	return money;
//}

// C3: Counting Sort
//int buyChoco(vector<int>& prices, int money) {
//	vector<int> freq(101, 0);
//	for(int i = 0; i < prices.size(); i++) {
//		freq[prices[i]]++;
//	}	
//	
//	int min = 0;
//	int secondMin = 0;
//	for(int i = 1; i <= 100; i++) {
//		if (freq[i] > 1) {
//			min = i;
//			secondMin = i;
//			break;
//		} else if (freq[i] == 1) {
//			min = i;
//			break;
//		}
//	}
//	
//	if (secondMin == 0) {
//		for (int i = min + 1; i <= 100; i++) {
//			if (freq[i] > 0) {
//				secondMin = i;
//				break;
//			}
//		}
//	}
//	
//	return money - (min + secondMin) >= 0 ? money - (min + secondMin) : money;
//}

// C4: Two pass
//int indexMin(vector<int> &array) {
//	int minIndex = 0;
//	
//	for (int i = 1; i < array.size(); i++) {
//		if (array[i] < array[minIndex]) {
//			minIndex = i;
//		}
//	}
//	
//	return minIndex;
//}
//
//int buyChoco(vector<int>& prices, int money) {
//	int minIndex = indexMin(prices);
//	
//	int buy = prices[minIndex];
//	prices[minIndex] = INT_MAX;
//	
//	int secondMinIndex = indexMin(prices);
//	
//	buy += prices[secondMinIndex];
//	
//	return money - buy >= 0 ? money - buy : money;
//}

// C5: One Pass
int buyChoco(vector<int>& prices, int money) {
	int minBuy = min(prices[0], prices[1]);
	int secondMin = max(prices[0], prices[1]);
	
	for(int i = 2; i < prices.size(); i++) {
		if (prices[i] < minBuy) {
			secondMin = minBuy;
			minBuy = prices[i];
		} else if (prices[i] < secondMin) {
			secondMin = prices[i];
		}
	}
	
	return money - (minBuy + secondMin) >= 0 ? money - (minBuy + secondMin) : money;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    vector<int> prices = {1, 2, 2};
    int money = 3;
	
	cout << buyChoco(prices, money);
}

