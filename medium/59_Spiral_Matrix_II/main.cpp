#include <iostream>
#include <vector>
using namespace std;

class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    vector<vector<int>> ans(n, vector<int>(n, 0));
    int startX = 0, startY = 0;
    int offset = 1;
    int count = 1;

    for (int k = 0; k < n / 2; k++) {
      int i = startX;
      int j = startY;
      for (j = startY; j < n - offset; j++) {
        ans[i][j] = count++;
      }
      for (i = startX; i < n - offset; i++) {
        ans[i][j] = count++;
      }
      for (; j > startX; j--) {
        ans[i][j] = count++;
      }
      for (; i > startY; i--) {
        ans[i][j] = count++;
      }
      startX++;
      startY++;
      offset++;
    }

    if (n % 2 == 1) {
      ans[n / 2][n / 2] = count;
    }

    return ans;
  }
};

void printMatrix(const vector<vector<int>>& matrix) {
  for (const auto& row : matrix) {
    for (int val : row) {
      cout << val << "\t";
    }
    cout << endl;
  }
  cout << "--------" << endl;
}

int main() {
  Solution solution;
  vector<int> testCases = {1, 2, 3, 4, 5};

  for (int n : testCases) {
    cout << "Matrix n = " << n << endl;
    vector<vector<int>> result = solution.generateMatrix(n);
    printMatrix(result);
  }

  return 0;
}
