#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int removeDuplicates(vector<int> &nums) {
    int point = 2;

    // 小於二的例外處理
    if (nums.size() < 2) {
      return nums.size();
    }

    // 由index=2開始向前兩格數值比對
    for (int idx = 2; idx < nums.size(); idx++) {
      // 注意: 這裡需要比對point的前兩項而不是idx
      if (nums[idx] != nums[point - 2]) {
        nums[point++] = nums[idx];
      }
    }

    return point;
  }
};

int maim() {
  vector<int> nums = {0, 0, 1, 1, 1, 1, 2, 3, 3};
  Solution sol;
  int len = sol.removeDuplicates(nums);
  for (int idx = 0; idx < len; idx++) {
    cout << nums[idx] << " ";
  }
  cout << endl;
}