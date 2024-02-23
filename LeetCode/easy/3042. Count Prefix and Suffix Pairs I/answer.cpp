#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2 * L)
// space : O(L)
class Solution {
 private:
  bool isFine(string &s, string &line) {
    int size = s.size();

    if (size > line.size()) return false;

    string prefix = line.substr(0, size);
    string suffix = line.substr(line.size() - size, size);

    if (prefix != suffix) return false;

    return s == prefix;
  }

 public:
  int countPrefixSuffixPairs(vector<string> &words) {
    int size = words.size();
    int answer = 0;

    for (int i = 0; i < size; i++) {
      for (int j = i + 1; j < size; j++) {
        if (isFine(words[i], words[j])) {
          answer++;
        }
      }
    }

    return answer;
  }
};