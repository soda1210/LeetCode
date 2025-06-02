#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    void reverse(string& s, int start, int end){ 
        for (int i = start, j = end; i < j; i++, j--) {
            swap(s[i], s[j]);
        }
    }

    void removeExtraSpaces(string& s) {
        int slow = 0;   
        for (int i = 0; i < s.size(); ++i) { 
            if (s[i] != ' ') { 
                if (slow != 0) s[slow++] = ' '; 
                while (i < s.size() && s[i] != ' ') { 
                    s[slow++] = s[i++];
                }
            }
        }
        s.resize(slow); 
    }

    string reverseWords(string s) {
        removeExtraSpaces(s); 
        reverse(s, 0, s.size() - 1);
        int start = 0; 
        for (int i = 0; i <= s.size(); ++i) {
            if (i == s.size() || s[i] == ' ') { 
                reverse(s, start, i - 1); 
                start = i + 1; 
            }
        }
        return s;
    }
};

// 測試函數
void runTest(const string& input) {
    Solution sol;
    string result = sol.reverseWords(input);
    cout << "Input: \"" << input << "\"\n";
    cout << "Output: \"" << result << "\"\n";
    cout << "------------------------\n";
}

int main() {
    vector<string> testCases = {
        "the sky is blue",
        "  hello world  ",
        "a good   example",
        "  Bob    Loves  Alice   ",
        "Alice does not even like bob"
    };

    for (const string& test : testCases) {
        runTest(test);
    }

    return 0;
}
