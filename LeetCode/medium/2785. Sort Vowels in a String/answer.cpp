#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use counting sort
// time : O(N)
// space : O(N)
class Solution {
 private:
  bool is_vowel(char c) {
    c = tolower(c);
    return c == 'a' || c == 'e' || c == 'o' || c == 'u' || c == 'i';
  }

 public:
  string sortVowels(string s) {
    int size = s.size();

    string keys = "AEIOUaeiou";
    int counts[256] = {
        0,
    };
    for (char &c : s) {
      if (is_vowel(c)) {
        counts[c]++;
      }
    }

    string vowels = "";
    for (char &key : keys) {
      vowels += string(counts[key], key);
    }

    int index = 0;
    for (int i = 0; i < size; i++) {
      char c = s[i];

      if (is_vowel(c)) {
        s[i] = vowels[index];
        index++;
      }
    }
    return s;
  }
};