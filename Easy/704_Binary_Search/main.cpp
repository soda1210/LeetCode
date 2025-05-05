#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  int search(vector<int>& nums, int target) {
    int index = 0, left = 0, right = nums.size() - 1;

    while (left <= right) {
      index = (left + right) / 2;
      if (target > nums[index]) {
        left = index + 1;
      } else if (target < nums[index]) {
        right = index - 1;
      } else {
        return index;
      }
    }
    return -1;
  }
};

int main() {
  Solution sol;

  vector<int> nums = {-1, 0, 3, 5, 9, 12};
  int target = 9;

  int result = sol.search(nums, target);
  cout << "Index: " << result << endl;  // Output: 4

  return 0;
}
