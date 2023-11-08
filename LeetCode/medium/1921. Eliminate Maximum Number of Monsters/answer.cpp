#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use sort
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  int eliminateMaximum(vector<int>& dist, vector<int>& speed) {
    int size = dist.size();
    vector<int> times;

    for (int i = 0; i < size; i++) {
      int d = dist[i], s = speed[i];

      int t = ceil((double)d / s);

      times.push_back(t);
    }

    sort(times.begin(), times.end(), greater<int>());

    int answer = 0;
    int time = 0;
    while (answer < size) {
      if (time >= times.back()) break;
      times.pop_back();
      answer++;
      time++;
    }
    return answer;
  }
};