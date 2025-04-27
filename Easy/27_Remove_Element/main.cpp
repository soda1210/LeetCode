#include <iostream>
#include <vector>
using namespace std;

int removeElement(vector<int>& nums, int val) {
  int point = 0;
  for (int i = 0; i < nums.size(); i++){
      if (nums[i] == val){
          continue;
      }
      
      nums[point++] = nums[i];
  }
  return point;
}

int main() {
  vector<int> nums = {3, 2, 2, 3};
  int val = 3;

  int newLength = removeElement(nums, val);

  cout << "新的陣列長度：" << newLength << endl;
  cout << "新的陣列內容（前" << newLength << "個元素）：" << endl;
  for (int i = 0; i < newLength; i++) {
      cout << nums[i] << " ";
  }
  cout << endl;

  return 0;
}