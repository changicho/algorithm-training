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

// use BST map
// time : O(N * log_2(N))
// space : O(N)
class Leaderboard {
 private:
  unordered_map<int, int> scores;
  map<int, int> scoreMap;

 public:
  Leaderboard() {}

  void addScore(int playerId, int score) {
    int beforeScore = 0;
    if (scores.count(playerId)) {
      beforeScore = scores[playerId];

      scoreMap[beforeScore]--;
    }
    int newScore = beforeScore + score;
    scores[playerId] = newScore;
    scoreMap[newScore]++;
  }

  int top(int K) {
    int sum = 0;
    int left = K;

    for (auto it = scoreMap.rbegin(); it != scoreMap.rend() && left > 0; it++) {
      int count = it->second;
      int score = it->first;
      int use = min(count, left);

      sum += use * score;
      left -= use;
    }

    return sum;
  }

  void reset(int playerId) {
    if (scores.count(playerId)) {
      int beforeScore = scores[playerId];

      scoreMap[beforeScore]--;
    }
    scores[playerId] = 0;
  }
};
