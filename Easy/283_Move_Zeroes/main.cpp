#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int first = 0;
        if (nums.size() <= 1) return;
        for (int idx = 0; idx < nums.size(); idx++) {
            if (nums[idx] != 0) {
                nums[first++] = nums[idx]; 
            }
        }
        for (int idx = first; idx < nums.size(); idx++) {
            nums[idx] = 0;
        }
    }
};

void printVector(const vector<int>& nums) {
    for (int n : nums) cout << n << " ";
    cout << endl;
}

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {0, 1, 0, 3, 12},
        {0, 0, 1},
        {1, 0, 2, 0, 3},
        {0, 0, 0, 0},
        {1, 2, 3, 4},
        {4, 2, 4, 0, 0, 3, 0, 5, 1, 0},
        {0}, 
        {}, 
        {0, 0, 0, 1}
    };

    for (auto& test : testCases) {
        sol.moveZeroes(test);
        printVector(test);
    }

    return 0;
}
