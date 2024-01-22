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
  int maxFrequencyElements(vector<int>& nums) {
    int answer = 0;
    int maxFreq = 0;
    int counts[101] = {
        0,
    };

    for (int& num : nums) {
      counts[num]++;

      int count = counts[num];
      if (count > maxFreq) {
        answer = count;
        maxFreq = count;
      } else if (count == maxFreq) {
        answer += count;
      }
    }

    return answer;
  }
};