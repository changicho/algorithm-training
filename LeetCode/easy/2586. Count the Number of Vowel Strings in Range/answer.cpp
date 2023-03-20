#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use one pass
// time: O(N)
// space : O(1)
class Solution {
 private:
  unordered_set<char> vowels = {'a', 'e', 'o', 'i', 'u'};

  bool isVowel(char &c) { return vowels.count(c) > 0; }

  bool isVowelWord(string &word) {
    return isVowel(word.front()) && isVowel(word.back());
  }

 public:
  int vowelStrings(vector<string> &words, int left, int right) {
    int size = words.size();

    int count = 0;
    for (int i = left; i <= right; i++) {
      if (isVowelWord(words[i])) count++;
    }
    return count;
  }
};