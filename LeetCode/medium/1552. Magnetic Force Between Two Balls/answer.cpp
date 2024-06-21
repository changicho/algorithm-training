#include <algorithm>
#include <climits>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort & binary search
// time : O(N * (log_2(N) + log_2(K)))
// space : O(N)
class Solution {
 private:
  bool check(vector<int> &position, int m, int dist) {
    int before = position[0];

    int count = 1;
    for (int &pos : position) {
      if (pos - before >= dist) {
        count++;
        before = pos;
      }
    }

    return count >= m;
  }

 public:
  int maxDistance(vector<int> &position, int m) {
    sort(position.begin(), position.end());
    int left = 0, right = *max_element(position.begin(), position.end());

    int answer = 0;
    while (left < right) {
      int mid = left + (right - left) / 2;

      if (check(position, m, mid)) {
        answer = max(answer, mid);
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return answer;
  }
};