#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        vector<int> ans(nums.size());
        int left = 0;
        int right = nums.size()-1;
        int index = nums.size()-1;

        while (left <= right){
            if (pow(nums[left], 2) > pow(nums[right], 2)){
                ans[index--] = pow(nums[left++], 2);
            }else{
                ans[index--] = pow(nums[right--], 2);
            }
        }

        return ans;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> testCases = {
        {-7, -3, 2, 3, 11},       // 混合負正數
        {-4, -1, 0, 3, 10},       // 常見例子
        {-5, -3, -2, -1},         // 全負數
        {1, 2, 3, 4, 5},          // 全正數
        {0, 0, 0},                // 全為零
        {0},                      // 單一元素：0
        {-1},                     // 單一元素：負數
        {1},                      // 單一元素：正數
        {-10000, 0, 10000},       // 大數測試
        {}                        // 空陣列
    };

    for (const auto& test : testCases) {
        vector<int> result = sol.sortedSquares(const_cast<vector<int>&>(test));
        cout << "Input: ";
        for (int n : test) cout << n << " ";
        cout << "\nOutput: ";
        for (int n : result) cout << n << " ";
        cout << "\n\n";
    }

    return 0;
}
