#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash map
// time : O(N)
// space : O(N)
class Solution {
 public:
  bool uniqueOccurrences(vector<int> &arr) {
    unordered_map<int, int> counts;
    for (int &num : arr) {
      counts[num]++;
    }

    unordered_set<int> occur;
    for (auto &it : counts) {
      int count = it.second;
      if (occur.count(count)) {
        return false;
      }
      occur.insert(count);
    }
    return true;
  }
};