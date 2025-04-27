#include <iostream>
#include <numeric>  // for std::gcd 這個版本沒有
using namespace std;

int findGCD(int a, int b) {
  // 輾轉相除法 求最大公因數
  while (b) {
    int temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

string GCDofString(string str1, string str2) {
  if (str1 + str2 != str2 + str1) {
    return "";
  }

  int maxGCD = findGCD(str1.size(), str2.size());

  return str1.substr(0, maxGCD);
}

int main() {
  if (GCDofString("ABCABC", "ABC") == "ABC") {
    cout << "Pass \n";
  }
  if (GCDofString("ABABAB", "ABAB") == "AB") {
    cout << "Pass \n";
  }
  if (GCDofString("LEET", "CODE") == "") {
    cout << "Pass \n";
  }
}
