#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
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

using ll = long long;

// sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> highFive(vector<vector<int>>& items) {
    int size = items.size();

    sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
      if (a[0] != b[0]) return a[0] < b[0];
      return a[1] > b[1];
    });

    vector<vector<int>> answer;

    for (int i = 0; i < size; i++) {
      int id = items[i][0];

      int sum = 0;
      for (int j = 0; j < 5; j++) {
        sum += items[i + j][1];
      }

      answer.push_back({id, sum / 5});

      while (i + 1 < size && items[i][0] == items[i + 1][0]) {
        i++;
      }
    }

    return answer;
  }
};