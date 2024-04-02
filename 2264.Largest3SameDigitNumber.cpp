#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

// --> C1 : Check
//vector<string> sameNums = {"999", "888", "777", "666", "555", "444", "333", "222", "111", "000"};
//
//bool contains(string sameNum, string num) {
//	for(int i = 0; i < num.size() - 2; i++) {
//		if (num[i] == sameNum[0] && num[i + 1] == sameNum[1] && num[i + 2] == sameNum[2]) 
//			return true;
//	}
//	return false;
//}
//
//string largestGoodInteger(string num) {        
//	for(string sameNum : sameNums) {
//		if (contains(sameNum, num)) {
//			return sameNum;
//		}
//	}
//	
//	return "";
//}

// C2
string largestGoodInteger(string num) {        
	string res = "";
	string maxNum = "";
	for(int i = 0; i < num.size(); i++) {
		int j = i + 1;
		int k = j + 1;
		
		if (k < num.size() && num[i] == num[j]  && num[i] == num[k] && num[j] == num[k]) {
			res += num[i];
			res += num[j];
			res += num[k];
			
			maxNum = max(res, maxNum);
			res = "";
		}
	}
	
	return maxNum;
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string num = "6777133999";
    
    cout << largestGoodInteger(num);
    
}

