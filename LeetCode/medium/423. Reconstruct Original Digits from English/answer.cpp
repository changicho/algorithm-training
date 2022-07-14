#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use distinct char
// time : O(L)
// space : O(L)
class Solution {
 public:
  string originalDigits(string s) {
    vector<string> words = {"zero", "two",   "four", "six",   "eight",
                            "one",  "three", "five", "seven", "nine"};
    vector<int> nums = {0, 2, 4, 6, 8, 1, 3, 5, 7, 9};
    vector<int> distinctChars = {'z', 'w', 'u', 'x', 'g',
                                 'o', 'r', 'f', 'v', 'i'};
    vector<int> counts(26, 0);

    for (char c : s) {
      counts[c - 'a']++;
    }

    vector<int> numCount(10, 0);
    for (int num = 0; num < 10; num++) {
      int count = counts[distinctChars[num] - 'a'];

      for (char &c : words[num]) {
        counts[c - 'a'] -= count;
      }

      numCount[nums[num]] = count;
    }

    string result = "";
    for (int num = 0; num < 10; num++) {
      while (numCount[num] > 0) {
        numCount[num]--;
        result += (num + '0');
      }
    }
    return result;
  }
};