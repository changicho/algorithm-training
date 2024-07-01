#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

// use union find
// time : O(N + M \* log_2(M))
// space : O(N + M)
class Solution {
 private:
  vector<int> parents;
  int count = 0;

  int find(int node) {
    if (parents[node] == node) return node;

    return parents[node] = find(parents[node]);
  }

  void merge(int a, int b) {
    int parentA = find(a), parentB = find(b);
    if (parentA == parentB) return;

    if (parentA > parentB) swap(parentA, parentB);
    count--;
    parents[parentB] = parentA;
  }

 public:
  int earliestAcq(vector<vector<int>>& logs, int n) {
    parents.resize(n);
    count = n;

    for (int i = 0; i < n; i++) {
      parents[i] = i;
    }

    sort(logs.begin(), logs.end());

    int answer = -1;
    for (vector<int>& log : logs) {
      int timestamp = log[0];
      int first = find(log[1]), second = find(log[2]);

      merge(first, second);

      if (count == 1) {
        answer = timestamp;
        break;
      }
    }
    return answer;
  }
};

// use union find by rank
// time : O(N + M \* log_2(M))
// space : O(N + M)
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