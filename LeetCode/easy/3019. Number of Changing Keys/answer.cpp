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
  int countKeyChanges(string s) {
    int size = s.size();

    int answer = 0;

    char before = tolower(s[0]);
    for (char &c : s) {
      if (tolower(c) == before) {
        continue;
      }

      answer++;
      before = tolower(c);
    }

    return answer;
  }
};