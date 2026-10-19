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

// sort & cycle count
// time : O(N * (log_2(N) + log_10(M)))
// space : O(N)
class Solution {
 private:
  vector<int> convert(int num, int index) {
    int origin = num;

    int sum = 0;
    while (num > 0) {
      sum += num % 10;
      num /= 10;
    }
    return {sum, origin, index};
  }

 public:
  int minSwaps(vector<int>& nums) {
    int size = nums.size();
    vector<vector<int>> converted;

    for (int i = 0; i < size; i++) {
      vector<int> cur = convert(nums[i], i);

      converted.push_back(cur);
    }

    sort(converted.begin(), converted.end());

    vector<int> nextIndexes;
    for (int i = 0; i < size; i++) {
      nextIndexes.push_back(converted[i][2]);
    }

    vector<int> visited(size);
    int cycleCount = 0;
    for (int i = 0; i < size; i++) {
      if (!visited[i]) {
        cycleCount++;

        int next = i;
        while (!visited[next]) {
          visited[next] = true;
          next = nextIndexes[next];
        }
      }
    }

    return size - cycleCount;
  }
};