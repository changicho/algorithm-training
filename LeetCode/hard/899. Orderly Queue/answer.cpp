#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use math
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  string orderlyQueue(string s, int k) {
    int length = s.length();

    if (k > 1) {
      sort(s.begin(), s.end());
      return s;
    }

    string answer = s;
    for (int i = 1; i < length; i++) {
      string temp = "";
      temp += s.substr(i);
      temp += s.substr(0, i);

      answer = min(answer, temp);
    }
    return answer;
  }
};