#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use two pass
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool isVowel(char c) {
    c = tolower(c);
    if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') {
      return true;
    }
    return false;
  }

 public:
  string reverseVowels(string s) {
    string answer = "";
    string vowels = "";

    for (char &c : s) {
      if (isVowel(c)) {
        vowels += c;
        answer += 'a';
      } else {
        answer += c;
      }
    }

    for (int i = 0; i < answer.length(); i++) {
      if (answer[i] != 'a') continue;

      answer[i] = vowels.back();
      vowels.pop_back();
    }

    return answer;
  }
};