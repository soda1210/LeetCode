#include <iostream>
#include <vector>
#include <stack>
#include <string>
using namespace std;

class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<long long> st; 
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+" || tokens[i] == "-" || tokens[i] == "*" || tokens[i] == "/") {
                long long num1 = st.top(); st.pop();
                long long num2 = st.top(); st.pop();
                if (tokens[i] == "+") st.push(num2 + num1);
                if (tokens[i] == "-") st.push(num2 - num1);
                if (tokens[i] == "*") st.push(num2 * num1);
                if (tokens[i] == "/") st.push(num2 / num1);
            } else {
                st.push(stoll(tokens[i]));
            }
        }

        return st.top();
    }
};

// 測試
void test(vector<string> tokens) {
    Solution sol;
    cout << "Input: ";
    for (auto& t : tokens) cout << t << " ";
    cout << "\nOutput: " << sol.evalRPN(tokens) << "\n\n";
}

int main() {
    test({"2", "1", "+", "3", "*"});         // 9
    test({"4", "13", "5", "/", "+"});        // 6
    test({"10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"});  // 22
    test({"3", "4", "+", "2", "*", "7", "/"}); // 2
    test({"5", "1", "2", "+", "4", "*", "+", "3", "-"}); // 14
    return 0;
}
