#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use union find

class Solution {
 private:
  vector<int> parents;
  int find(int node) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    int parentA = find(a), parentB = find(b);

    if (parentA > parentB) swap(parentA, parentB);

    parents[parentB] = parentA;
  }

  int countParents() {
    unordered_set<int> us;
    for (int parent : parents) {
      us.insert(find(parent));
    }
    return us.size();
  }

 public:
  int earliestAcq(vector<vector<int>>& logs, int n) {
    int answer = -1;
    sort(logs.begin(), logs.end());

    parents.resize(n);
    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    for (vector<int>& log : logs) {
      int timestamp = log[0];
      int from = log[1], to = log[2];

      merge(from, to);

      if (countParents() == 1) {
        answer = timestamp;
        break;
      }
    }

    return answer;
  }
};

// use union find by rank

class Solution {
 private:
  vector<int> parents;
  vector<int> counts;

  int find(int node) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    int parentA = find(a), parentB = find(b);
    if (parentA == parentB) return;

    if (parentA > parentB) swap(parentA, parentB);
    if (counts[parentA] < counts[parentB]) swap(parentA, parentB);

    parents[parentB] = parentA;
    counts[parentA] += counts[parentB];
  }

 public:
  int earliestAcq(vector<vector<int>>& logs, int n) {
    parents.resize(n);
    counts.resize(n, 1);

    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    sort(logs.begin(), logs.end());

    int answer = -1;
    for (vector<int>& log : logs) {
      int timestamp = log[0];
      int first = find(log[1]), second = find(log[2]);

      merge(first, second);

      if (counts[find(first)] == n) {
        answer = timestamp;
        break;
      }
    }
    return answer;
  }
};