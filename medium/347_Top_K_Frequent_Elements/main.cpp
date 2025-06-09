#include <iostream>
#include <queue>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

class Solution {
 public:
  class mycomparison {
   public:
    bool operator()(const pair<int, int>& lhs, const pair<int, int>& rhs) {
      return lhs.second > rhs.second;  // 小根堆：頻率低的在上面
    }
  };

  vector<int> topKFrequent(vector<int>& nums, int k) {
    unordered_map<int, int> map;
    for (int i = 0; i < nums.size(); i++) {
      map[nums[i]]++;
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, mycomparison>
        pri_que;

    for (auto& it : map) {
      pri_que.push(it);
      if (pri_que.size() > k) {
        pri_que.pop();
      }
    }

    vector<int> result(k);
    for (int i = k - 1; i >= 0; i--) {
      result[i] = pri_que.top().first;
      pri_que.pop();
    }
    return result;
  }
};

// 測試
void test(vector<int> nums, int k) {
  Solution sol;
  vector<int> res = sol.topKFrequent(nums, k);
  cout << "Top " << k << " frequent elements: ";
  for (int n : res) cout << n << " ";
  cout << "\n";
}

int main() {
  test({1, 1, 1, 2, 2, 3}, 2);         // Output: 1 2
  test({1}, 1);                        // Output: 1
  test({4, 1, -1, 2, -1, 2, 3}, 2);    // Output: -1 2
  test({5, 3, 1, 1, 1, 3, 73, 1}, 2);  // Output: 1 3
  return 0;
}
