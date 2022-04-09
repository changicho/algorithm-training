#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

// use hash map
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    unordered_set<int> players;
    unordered_map<int, int> loseCount;

    for (vector<int>& match : matches) {
      int winner = match[0], loser = match[1];

      players.insert(winner);
      players.insert(loser);

      loseCount[loser]++;
    }

    vector<int> notLostPlayers;
    vector<int> oneLostPlayers;

    for (int p : players) {
      if (loseCount[p] == 0) {
        notLostPlayers.push_back(p);
      } else if (loseCount[p] == 1) {
        oneLostPlayers.push_back(p);
      }
    }

    sort(notLostPlayers.begin(), notLostPlayers.end());
    sort(oneLostPlayers.begin(), oneLostPlayers.end());
    return {notLostPlayers, oneLostPlayers};
  }
};

// use BST map
// time : O(N * log_2(N))
// space : O(N)
class Solution {
 public:
  vector<vector<int>> findWinners(vector<vector<int>>& matches) {
    map<int, int> loseCount;

    for (vector<int>& match : matches) {
      int winner = match[0], loser = match[1];

      if (loseCount.count(winner) == 0) {
        loseCount[winner] = 0;
      }
      loseCount[loser]++;
    }

    vector<int> notLostPlayers;
    vector<int> oneLostPlayers;
    for (auto& [p, c] : loseCount) {
      if (c == 0) {
        notLostPlayers.push_back(p);
      } else if (c == 1) {
        oneLostPlayers.push_back(p);
      }
    }

    return {notLostPlayers, oneLostPlayers};
  }
};