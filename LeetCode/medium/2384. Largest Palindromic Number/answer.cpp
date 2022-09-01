#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy
// time : O(N)
// space : O(N)
class Solution {
 private:
  string getNum(vector<int> &keys, vector<int> &counts) {
    int odd = -1;
    for (int &key : keys) {
      if (counts[key] % 2 == 1) {
        odd = key;
        break;
      }
    }

    string half = "";
    string answer = "";
    for (int &key : keys) {
      if (half.length() == 0 && key == 0) break;

      half += string(counts[key] / 2, key + '0');
    }
    answer += half;
    if (odd != -1) {
      answer.push_back(odd + '0');
    }
    reverse(half.begin(), half.end());
    answer += half;

    if (answer.length() == 0) return "0";
    return answer;
  }

 public:
  string largestPalindromic(string num) {
    vector<int> counts(10, 0);

    for (char &c : num) {
      counts[c - '0']++;
    }

    bool oddFound = false;
    vector<int> keys;
    for (int key = 9; key >= 0; key--) {
      if (counts[key] % 2 == 0) {
        keys.push_back(key);
      } else {
        if (oddFound) {
          counts[key]--;
        } else {
          oddFound = true;
        }
        keys.push_back(key);
      }
    }

    string answer = getNum(keys, counts);
    return answer;
  }
};