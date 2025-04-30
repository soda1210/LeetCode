#include <iostream>
#include <unordered_map>
using namespace std;

class Solution {
  public:
      bool isAnagram(string s, string t) {
          unordered_map<char, int> hash;
  
          if (s.size() != t.size()) { return false; }
  
          for (int i = 0; i<s.size(); i++){
              hash[s[i]]++;
              hash[t[i]]--;
          }
          
          for (const auto& target:hash){
              if(target.second != 0){
                  return false;
              }
          }
          return true;
      }
  };