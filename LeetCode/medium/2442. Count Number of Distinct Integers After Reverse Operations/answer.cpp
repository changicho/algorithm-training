#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

// use hash set
// time : O(N)
// space : O(N)
class Solution {
 private:
  int reverseDigit(int num) {
    int ret = 0;
    while (num > 0) {
      ret *= 10;
      ret += num % 10;
      num /= 10;
    }
    return ret;
  }

 public:
  int countDistinctIntegers(vector<int>& nums) {
    unordered_set<int> us;

    for (int& num : nums) {
      us.insert(num);
      us.insert(reverseDigit(num));
    }
    return us.size();
  }
};