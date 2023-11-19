#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use brute force
// time : O(N^2)
// space : O(N)
class Solution {
 public:
  string findDifferentBinaryString(vector<string>& nums) {
    int size = nums.size();
    unordered_set<int> us;
    for (string& num : nums) {
      us.insert(stoi(num, 0, 2));
    }

    string answer = "";
    for (int num = 0; num <= size; num++) {
      if (us.count(num) > 0) continue;

      answer = bitset<16>(num).to_string().substr(16 - size);
      break;
    }

    return answer;
  }
};