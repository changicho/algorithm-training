#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use greedy & sort

class Solution {
 public:
  string largestNumber(vector<int> &nums) {
    vector<string> numStrings;

    for (int &num : nums) {
      string numString = to_string(num);

      numStrings.emplace_back(numString);
    }

    sort(numStrings.begin(), numStrings.end(),
         [](const string &a, const string &b) { return (a + b) > (b + a); });

    if (numStrings.front() == "0") return "0";

    string answer = "";
    for (string num : numStrings) {
      answer += num;
    }
    return answer;
  }
};
