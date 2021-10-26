#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use BFS

class Solution {
 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int size = isConnected.size();
    vector<bool> visited(size, false);

    int answer = 0;
    for (int start = 0; start < size; start++) {
      if (visited[start]) continue;
      answer += 1;

      visited[start] = true;
      queue<int> q;
      q.push(start);

      while (!q.empty()) {
        int cur = q.front();
        q.pop();

        for (int next = 0; next < size; next++) {
          if (isConnected[cur][next] == 0) continue;
          if (visited[next]) continue;

          visited[next] = true;
          q.push(next);
        }
      }
    }
    return answer;
  }
};

// use disjoint set

class Solution {
 private:
  int find(int node, vector<int>& parents) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node], parents);
  }

  void merge(int a, int b, vector<int>& parents) {
    // make a smaller
    if (a > b) swap(a, b);
    if (parents[a] == parents[b]) return;

    int parentA = find(a, parents);
    int parentB = find(b, parents);

    parents[parentB] = parentA;
    find(b, parents);
  }

 public:
  int findCircleNum(vector<vector<int>>& isConnected) {
    int size = isConnected.size();
    vector<int> parents(size);

    for (int node = 0; node < size; node++) {
      parents[node] = node;
    }

    for (int from = 0; from < size; from++) {
      for (int to = from + 1; to < size; to++) {
        if (isConnected[from][to] != 1) continue;

        merge(from, to, parents);
      }
    }

    // update parents
    for (int node = 0; node < size; node++) {
      find(node, parents);
    }

    unordered_set<int> counts;
    for (int parent : parents) {
      counts.insert(parent);
    }

    return counts.size();
  }
};