#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int> hash;
    for (int i = 0; i < nums.size(); i++) {
      int diff = target - nums[i];
      if (hash.find(diff) != hash.end()){
        return {hash[diff], i};
      }
      hash[nums[i]] = i;
    }

    return {};
  }
};

int main() {
  vector<int> nums = {2, 7, 11, 15};
  int target = 9;

  Solution Sol;

  vector<int> ans = Sol.twoSum(nums, target);
  cout << ans[0] << ans[1];

  return 0;
}