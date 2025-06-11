#include <iostream>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  bool compare(TreeNode* left, TreeNode* right) {
    if (left == NULL && right != NULL)
      return false;
    else if (left != NULL && right == NULL)
      return false;
    else if (left == NULL && right == NULL)
      return true;
    else if (left->val != right->val)
      return false;

    bool outside = compare(left->left, right->right);
    bool inside = compare(left->right, right->left);
    return outside && inside;
  }

  bool isSymmetric(TreeNode* root) {
    if (root == NULL) return true;
    return compare(root->left, root->right);
  }
};

int main() {
  TreeNode* root = new TreeNode(1);
  root->left = new TreeNode(2, new TreeNode(3), new TreeNode(4));
  root->right = new TreeNode(2, new TreeNode(4), new TreeNode(3));

  Solution sol;
  cout << (sol.isSymmetric(root) ? "True" : "False") << endl;  // 應輸出 True

  return 0;
}
