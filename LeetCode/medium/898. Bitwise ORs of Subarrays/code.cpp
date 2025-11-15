#include <algorithm>
#include <climits>
#include <cmath>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use hash set
// time : O(N * M)
// space : O(M)
class Solution {
 public:
  int subarrayBitwiseORs(vector<int> arr) {
    unordered_set<int> answer;

    unordered_set<int> cur;
    for (int &num : arr) {
      unordered_set<int> next = {num};
      for (int before : cur) {
        next.insert(num | before);
      }

      swap(cur, next);
      for (int num : cur) answer.insert(num);
    }
    return answer.size();
  }
};