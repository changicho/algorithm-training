#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use dynamic programming
// time : O(N^2)
// space : O(N)
class Solution {
 private:
  struct Player {
    int age, score;
  };

 public:
  int bestTeamScore(vector<int>& scores, vector<int>& ages) {
    int size = scores.size();

    vector<Player> players;
    for (int i = 0; i < size; i++) {
      players.push_back({ages[i], scores[i]});
    }

    sort(players.begin(), players.end(), [](Player& a, Player& b) {
      if (a.age != b.age) return a.age < b.age;
      return a.score < b.score;
    });


    vector<int> dp(size);
    for (int i = 0; i < size; i++) {
      dp[i] = players[i].score;
    }

    for (int i = 0; i < size; i++) {
      for (int j = i - 1; j >= 0; j--) {
        if (players[i].score >= players[j].score) {
          dp[i] = max(dp[i], players[i].score + dp[j]);
        }
      }
    }

    int answer = 0;
    for (int i = 0; i < size; i++) {
      answer = max(answer, dp[i]);
    }

    return answer;
  }
};