#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

// queue
// time : O(N)
// space : O(N)
class Solution {
 public:
  vector<int> rearrangeArray(vector<int>& nums) {
    int size = nums.size();
    vector<int> answer;

    queue<int> negative, positive;
    for (int& num : nums) {
      if (num < 0) {
        negative.push(num);
      } else {
        positive.push(num);
      }
    }

    for (int i = 0; i < size / 2; i++) {
      answer.push_back(positive.front());
      answer.push_back(negative.front());
      positive.pop();
      negative.pop();
    }
    return answer;
  }
};