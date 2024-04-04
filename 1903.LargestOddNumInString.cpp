#include <bits/stdc++.h>
#define imy main()
#define ll long long
using namespace std;

string largestOddNumber(string num) {
	for(int i = num.size() - 1; i >= 0; i--) {
		if ((num[i] - '0') % 2 != 0) {
			return num.substr(0, i + 1);
		}
	}
	
	return "";     
}

imy {
 	ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    string num = "4206";
	cout << largestOddNumber(num);
}

