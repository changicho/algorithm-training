#include <algorithm>
#include <iostream>
#include <queue>
#include <set>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use eulerian path (multiset)

class Solution {
 private:
  unordered_map<string, multiset<string>> graph;

  void recursive(string node, vector<string>& answer) {
    while (!graph[node].empty()) {
      string next = *graph[node].begin();
      graph[node].erase(graph[node].begin());

      recursive(next, answer);
    }

    answer.push_back(node);
  }

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> answer;

    for (vector<string>& ticket : tickets) {
      string from = ticket[0], to = ticket[1];

      graph[from].insert(to);
    }
    recursive("JFK", answer);

    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// use eulerian path (heap)

class Solution {
 private:
  unordered_map<string, priority_queue<string, vector<string>, greater<string>>>
      graph;

  void recursive(string node, vector<string>& answer) {
    while (!graph[node].empty()) {
      string next = graph[node].top();
      graph[node].pop();

      recursive(next, answer);
    }

    answer.push_back(node);
  }

 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> answer;

    for (vector<string>& ticket : tickets) {
      string from = ticket[0], to = ticket[1];

      graph[from].push(to);
    }
    recursive("JFK", answer);

    reverse(answer.begin(), answer.end());
    return answer;
  }
};
