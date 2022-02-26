#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use memoization backtracking BFS & bit

class Solution {
 private:
  struct Status {
    int visited;
    int node;
    int step;
  };

  int cache[1 << 12][12] = {0};

 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int size = graph.size();

    queue<Status> q;

    for (int node = 0; node < size; node++) {
      int bit = 0;
      bit |= 1 << node;

      q.push({bit, node, 0});
    }

    int answer = -1;
    int step = 0;
    while (!q.empty() && answer == -1) {
      int qSize = q.size();

      while (qSize--) {
        Status cur = q.front();
        q.pop();

        int node = cur.node;

        if (cur.visited == (1 << size) - 1) {
          answer = step;
          break;
        }

        for (int to : graph[node]) {
          Status next = cur;
          next.visited |= 1 << to;
          next.node = to;
          next.step++;

          if (cache[next.visited][next.node] != 0 &&
              cache[next.visited][next.node] <= next.step) {
            continue;
          }
          cache[next.visited][next.node] = next.step;

          q.push(next);
        }
      }

      step++;
    }

    return answer;
  }
};

// use memoization backtracking BFS (string)

class Solution {
 private:
  struct Status {
    string visited;
    int node;
    int step;
  };

 public:
  int shortestPathLength(vector<vector<int>>& graph) {
    int size = graph.size();

    queue<Status> q;
    vector<unordered_map<string, int>> cache(size);

    string target(size, '1');

    for (int node = 0; node < size; node++) {
      string visited(size, '0');
      visited[node] = '1';

      q.push({visited, node, 0});

      cache[node][visited] = 0;
    }

    int answer = -1;
    int step = 0;
    while (!q.empty() && answer == -1) {
      int qSize = q.size();

      while (qSize--) {
        Status cur = q.front();
        q.pop();

        int node = cur.node;
        if (cur.visited == target) {
          answer = step;
          break;
        }

        for (int to : graph[node]) {
          Status next = cur;
          next.visited[to] = '1';
          next.node = to;
          next.step++;

          if (cache[to].find(next.visited) != cache[to].end() &&
              cache[to][next.visited] <= next.step) {
            continue;
          }
          cache[to][next.visited] = next.step;

          q.push(next);
        }
      }

      step++;
    }

    return answer;
  }
};