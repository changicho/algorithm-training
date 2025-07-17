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

// use sort & two pointer
// time : O(N * log_2(N) + M * log_2(M))
// space : O(N + M)
class Solution {
 public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    int size = trainers.size();

    sort(players.begin(), players.end());
    sort(trainers.begin(), trainers.end());

    int answer = 0;
    int i = 0;
    for (int& p : players) {
      while (i < size && p > trainers[i]) {
        i++;
      }

      if (i == size) break;
      answer++;
      i++;
    }
    return answer;
  }
};

// use multiset
// time : O(M * log_2(M) + N)
// space : O(M)
class Solution {
 public:
  int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
    multiset<int> s(trainers.begin(), trainers.end());

    int answer = 0;
    for (int& p : players) {
      auto it = s.lower_bound(p);

      if (it == s.end()) continue;
      answer++;
      s.erase(it);
    }
    return answer;
  }
};