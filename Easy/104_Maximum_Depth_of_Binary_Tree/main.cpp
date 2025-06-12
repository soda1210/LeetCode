#include <iostream>
#include <queue>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  int maxDepth(TreeNode* root) {
    if (root == NULL) return 0;
    int depth = 0;
    queue<TreeNode*> que;
    que.push(root);
    while (!que.empty()) {
      int size = que.size();
      depth++;
      for (int i = 0; i < size; i++) {
        TreeNode* node = que.front();
        que.pop();
        if (node->left) que.push(node->left);
        if (node->right) que.push(node->right);
      }
    }
    return depth;
  }
};

int main() {
  // 測試用例：建構以下樹
  //     1
  //    / \
    //   2   3
  //  /
  // 4
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2, new TreeNode(4), nullptr);
  root->right = new TreeNode(3);

  Solution sol;
  cout << "Max Depth: " << sol.maxDepth(root) << endl;  // 應輸出 3

  return 0;
}
