#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            int i = m - 1;
            int j = n - 1;
            int k = m + n - 1;
    
            while (i >= 0 && j >= 0) {
                if (nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }
            }
    
            // 如果nums2還有剩，補進nums1（nums1剩的部分不用管，因為本來就已經在正確位置）
            while (j >= 0) {
                nums1[k--] = nums2[j--];
            }
        }
    };
    
int main() {
    vector<int> nums1 = {1,2,3,0,0,0};
    vector<int> nums2 = {2,5,6};
    int m = 3, n = 3;

    Solution().merge(nums1, m, nums2, n);

    for (int n : nums1) {
        cout << n << " ";
    }
    cout << endl;
    return 0;
}
