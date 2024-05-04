#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 public:
  string reversePrefix(string word, char ch) {
    int size = word.size();

    for (int i = 0; i < size; i++) {
      if (word[i] == ch) {
        reverse(word.begin(), word.begin() + i + 1);
        break;
      }
    }

    return word;
  }
};