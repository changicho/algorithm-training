#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

bool knows(int a, int b);

// use brute force

class Solution {
 private:
  bool isCelebrity(int node, int limit) {
    for (int next = 0; next < limit; next++) {
      if (next == node) continue;

      if (knows(next, node) && !knows(node, next)) continue;
      return false;
    }
    return true;
  }

 public:
  int findCelebrity(int n) {
    for (int i = 0; i < n; i++) {
      if (isCelebrity(i, n)) return i;
    }

    return -1;
  }
};

// use brute force with memoization

class Solution {
 private:
  unordered_map<int, unordered_map<int, bool>> um;

  bool knowsHash(int a, int b) {
    if (um.find(a) != um.end() && um[a].find(b) != um[a].end()) {
      return um[a][b];
    }
    return um[a][b] = knows(a, b);
  }

  bool isCelebrity(int node, int limit) {
    for (int next = 0; next < limit; next++) {
      if (next == node) continue;

      if (knowsHash(next, node) && !knowsHash(node, next)) continue;
      return false;
    }
    return true;
  }

 public:
  int findCelebrity(int n) {
    for (int i = 0; i < n; i++) {
      if (isCelebrity(i, n)) return i;
    }

    return -1;
  }
};

// use logical deduction

class Solution {
 private:
  bool isCelebrity(int node, int limit) {
    for (int next = 0; next < limit; next++) {
      if (next == node) continue;

      if (!knows(next, node) || knows(node, next)) return false;
    }
    return true;
  }

 public:
  int findCelebrity(int n) {
    int celebrityCandidate = 0;
    for (int i = 1; i < n; i++) {
      if (knows(celebrityCandidate, i)) {
        celebrityCandidate = i;
      }
    }
    if (isCelebrity(celebrityCandidate, n)) {
      return celebrityCandidate;
    }
    return -1;
  }
};

// use logical deduction with memoization

class Solution {
 private:
  unordered_map<int, unordered_map<int, bool>> um;

  bool knowsHash(int a, int b) {
    if (um.find(a) != um.end() && um[a].find(b) != um[a].end()) {
      return um[a][b];
    }
    return um[a][b] = knows(a, b);
  }

  bool isCelebrity(int node, int limit) {
    for (int next = 0; next < limit; next++) {
      if (next == node) continue;

      if (!knowsHash(next, node) || knowsHash(node, next)) return false;
    }
    return true;
  }

 public:
  int findCelebrity(int n) {
    int celebrityCandidate = 0;
    for (int i = 1; i < n; i++) {
      if (knowsHash(celebrityCandidate, i)) {
        celebrityCandidate = i;
      }
    }

    if (isCelebrity(celebrityCandidate, n)) {
      return celebrityCandidate;
    }

    return -1;
  }
};