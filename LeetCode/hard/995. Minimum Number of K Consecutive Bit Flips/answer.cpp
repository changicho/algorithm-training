#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use flip count
// time : O(N)
// space : O(N)
class Solution {
 public:
  int minKBitFlips(vector<int>& nums, int k) {
    int size = nums.size();

    vector<bool> isFlipped(size, false);
    int count = 0;
    int answer = 0;

    for (int i = 0; i < size; i++) {
      if (i >= k && isFlipped[i - k]) {
        count--;
      }

      if (count % 2 == nums[i]) {
        if (i + k > size) {
          return -1;
        }

        count++;
        isFlipped[i] = true;
        answer++;
      }
    }

    return answer;
  }
};