#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int ans = INT_MAX;
        int left = 0, sum = 0;

        for (int right = 0; right < nums.size(); right++) {
            sum += nums[right];
            while (sum >= target) {
                ans = min(ans, right - left + 1);
                sum -= nums[left++];
            }
        }

        return ans == INT_MAX ? 0 : ans;
    }
};

int main() {
    Solution sol;

    vector<pair<int, vector<int>>> tests = {
        {7, {2,3,1,2,4,3}},          // 答案: 2 -> [4,3]
        {15, {1,2,3,4,5}},           // 答案: 5 -> [1,2,3,4,5]
        {100, {1,2,3,4,5}},          // 答案: 0 -> 無法湊出
        {4, {1,4,4}},                // 答案: 1 -> [4]
        {11, {1,2,3,4,5}},           // 答案: 3 -> [3,4,5]
        {3, {1,1}},                  // 答案: 0
        {5, {5}},                    // 答案: 1
        {6, {10, 2, 3}},             // 答案: 1 -> [10]
    };

    for (auto& [target, nums] : tests) {
        int result = sol.minSubArrayLen(target, nums);
        cout << "target = " << target << ", result = " << result << endl;
    }

    return 0;
}
