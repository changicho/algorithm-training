#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use bit change
// time : O(log_2(N))
// space : O(log_2(N))
class Solution {
 public:
  int findComplement(int num) {
    vector<bool> bits;
    while (num > 0) {
      bits.push_back(num % 2 == 0 ? true : false);
      num /= 2;
    }

    int answer = 0;
    for (int i = 0; i < bits.size(); i++) {
      answer += (bits[i] << i);
    }
    return answer;
  }
};

// use bit mask
// time : O(1)
// space : O(1)
class Solution {
 public:
  int findComplement(int num) {
    unsigned mask = ~0;
    while (num & mask) mask <<= 1;
    return ~mask & ~num;
  }
};