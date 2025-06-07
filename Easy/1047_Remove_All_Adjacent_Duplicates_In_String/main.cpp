#include <iostream>
#include <string>
#include <stack>
#include <algorithm>
using namespace std;

class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> st;
        for (char s : S) {
            if (st.empty() || s != st.top()) {
                st.push(s);
            } else {
                st.pop(); 
            }
        }

        string result = "";
        while (!st.empty()) { 
            result += st.top();
            st.pop();
        }
        reverse(result.begin(), result.end()); 
        return result;
    }
};

// 測試函式
void test(const string& input) {
    Solution sol;
    cout << "Input: \"" << input << "\" → Output: \"" << sol.removeDuplicates(input) << "\"" << endl;
}

int main() {
    test("abbaca");      // "ca"
    test("azxxzy");      // "ay"
    test("aababaab");    // "bab"
    test("aaaa");        // ""
    test("abcddcba");    // ""
    test("abccba");      // ""
    test("");            // ""
    test("a");           // "a"
    return 0;
}
