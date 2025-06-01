#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        for (int k = 0; k < nums.size(); k++) {
            if (k > 0 && nums[k] == nums[k - 1]) continue;
            if ((long)nums[k] > target && nums[k] >= 0) break;

            for (int i = k + 1; i < nums.size(); i++) {
                if (i > k + 1 && nums[i] == nums[i - 1]) continue;
                if ((long)nums[k] + nums[i] > target && nums[k] + nums[i] >= 0) break;

                int left = i + 1;
                int right = nums.size() - 1;
                while (left < right) {
                    long sum = (long)nums[k] + nums[i] + nums[left] + nums[right];
                    if (sum > target) {
                        right--;
                    } else if (sum < target) {
                        left++;
                    } else {
                        result.push_back({nums[k], nums[i], nums[left], nums[right]});
                        while (left < right && nums[left] == nums[left + 1]) left++;
                        while (left < right && nums[right] == nums[right - 1]) right--;
                        left++;
                        right--;
                    }
                }
            }
        }
        return result;
    }
};

// 輔助函數：印出結果
void printResult(vector<vector<int>>& res) {
    for (auto& quad : res) {
        cout << "[";
        for (int i = 0; i < quad.size(); ++i) {
            cout << quad[i];
            if (i != quad.size() - 1) cout << ", ";
        }
        cout << "]\n";
    }
    cout << "------------------\n";
}

int main() {
    Solution sol;

    vector<pair<vector<int>, int>> testCases = {
        {{1, 0, -1, 0, -2, 2}, 0},               // 標準測資
        {{2, 2, 2, 2, 2}, 8},                    // 重複值
        {{-3, -1, 0, 2, 4, 5}, 2},               // 有負有正
        {{0, 0, 0, 0}, 0},                       // 全為 0
        {{1, -2, -5, -4, -3, 3, 3, 5}, -11},     // 極端負數測資
        {{}, 0},                                 // 空陣列
        {{1}, 0},                                // 單一元素
        {{1000000000, 1000000000, 1000000000, 1000000000}, 4000000000} // 大數測試
    };

    for (auto& [nums, target] : testCases) {
        cout << "Input: ";
        for (int n : nums) cout << n << " ";
        cout << "\nTarget: " << target << "\nResult:\n";
        vector<vector<int>> res = sol.fourSum(nums, target);
        printResult(res);
    }

    return 0;
}
