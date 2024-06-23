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
  long long numberOfSubstrings(string s) {
    long long answer = 0;
    int counts[26] = {
        0,
    };

    for (char &c : s) {
      answer += counts[c - 'a'];
      counts[c - 'a']++;
    }
    return answer + s.size();
  }
};