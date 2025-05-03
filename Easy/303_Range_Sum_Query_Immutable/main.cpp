#include <iostream>
#include <vector>
using namespace std;

class NumArray {
 private:
  vector<int> prefix;

 public:
  NumArray(vector<int>& nums) {
    prefix.resize(nums.size() + 1, 0);
    for (int i = 0; i < nums.size(); ++i) {
      prefix[i + 1] = nums[i] + prefix[i];
    }
  }

  int sumRange(int left, int right) { return prefix[right + 1] - prefix[left]; }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */

int main() {
  vector<int> nums = {-2, 0, 3, -5, 2, -1};
  NumArray obj(nums);
  cout << obj.sumRange(0, 2) << endl;  // 1
  cout << obj.sumRange(2, 5) << endl;  // -1
  cout << obj.sumRange(0, 5) << endl;  // -3
  return 0;
}
