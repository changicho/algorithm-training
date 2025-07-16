#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use one pass
// time : O(N)
// space : O(1)
class Solution {
 private:
  unordered_set<char> vowels = {'a', 'e', 'i', 'o', 'u'};
  unordered_set<char> consonants = {'b', 'c', 'd', 'f', 'g', 'h', 'j',
                                    'k', 'l', 'm', 'n', 'p', 'q', 'r',
                                    's', 't', 'v', 'w', 'x', 'y', 'z'};

  bool isOnlyDigitsEnglish(string &word) {
    for (char &c : word) {
      if (!isdigit(c) && !islower(c) && !isupper(c)) return false;
    }
    return true;
  }

  bool hasVowelConsonant(string &word) {
    int vowel = 0, consonant = 0;
    for (char &c : word) {
      if (vowels.count(tolower(c)) > 0)
        vowel++;
      else if (consonants.count(tolower(c)) > 0)
        consonant++;
    }

    return vowel > 0 && consonant > 0;
  }

 public:
  bool isValid(string word) {
    return word.size() >= 3 && isOnlyDigitsEnglish(word) &&
           hasVowelConsonant(word);
  }
};