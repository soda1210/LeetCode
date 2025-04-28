#include <iostream>
#include <vector>
using namespace std;

int removeDuplicates(vector<int> &nums) {
  int ans = 0;
  for (int i = 1; i < nums.size(); i++) {
    if (nums[i] != nums[ans]) {
      nums[++ans] = nums[i];
    }
  }
  return ans + 1;
}

int main() {
  vector<int> nums = {1, 1, 2, 2, 3};
  int len = removeDuplicates(nums);
  cout << "新陣列長度：" << len << endl;
  cout << "新陣列內容：";
  for (int i = 0; i < len; i++) {
    cout << nums[i] << " ";
  }
  cout << endl;
  return 0;
}
