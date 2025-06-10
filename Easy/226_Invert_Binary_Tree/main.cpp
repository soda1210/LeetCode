#include <iostream>
#include <stack>
using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
 public:
  TreeNode* invertTree(TreeNode* root) {
    stack<TreeNode*> st;
    if (root != NULL) st.push(root);
    while (!st.empty()) {
      TreeNode* node = st.top();
      if (node != NULL) {
        st.pop();
        if (node->right) st.push(node->right);
        if (node->left) st.push(node->left);
        st.push(node);
        st.push(NULL);
      } else {
        st.pop();
        node = st.top();
        st.pop();
        swap(node->left, node->right);
      }
    }
    return root;
  }
};

// 輔助：中序印出樹（驗證結果）
void printInorder(TreeNode* root) {
  if (!root) return;
  printInorder(root->left);
  cout << root->val << " ";
  printInorder(root->right);
}

int main() {
  /*
         4
       /   \
      2     7
     / \   / \
    1   3 6   9
  */
  TreeNode* root = new TreeNode(4);
  root->left = new TreeNode(2, new TreeNode(1), new TreeNode(3));
  root->right = new TreeNode(7, new TreeNode(6), new TreeNode(9));

  Solution sol;
  TreeNode* inverted = sol.invertTree(root);

  cout << "Inorder of Inverted Tree: ";
  printInorder(inverted);  // Output: 9 7 6 4 3 2 1
  cout << endl;

  return 0;
}
