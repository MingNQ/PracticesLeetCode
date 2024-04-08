#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        int countStudents(vector<int>& students, vector<int>& sandwiches) {
            int count1 = 0, count0 = 0;
            for(int s : students) {
                if (s == 0) count0++;
                else count1++;
            }

            for(int s : sandwiches) {
                if (s == 0 && count0 == 0) return count1;
                if (s == 1 && count1 == 0) return count0;

                if (s == 0) count0--;
                else count1--;
            }

            return count0;
        }

};

main() {
    Solution s;
    // Case 1
    vector<int> students = {1,1,0,0};
    vector<int> sandwiches = {0,1,0,1};

    cout << s.countStudents(students, sandwiches) << endl;


    // case 2;
    students = {1,1,1,0,0,1};
    sandwiches = {1,0,0,0,1,1};
    
    cout << s.countStudents(students, sandwiches) << endl;
}