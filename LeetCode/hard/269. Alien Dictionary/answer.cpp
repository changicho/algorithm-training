#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use topological sort

class Solution {
 private:
  unordered_map<char, vector<char>> graph;
  unordered_map<char, int> inDegree;
  bool canMakeAnswer = true;

  void findDiff(string a, string b) {
    int length = min(a.length(), b.length());
    for (int i = 0; i < length; i++) {
      if (a[i] != b[i]) {
        // a is faster
        graph[b[i]].push_back(a[i]);
        inDegree[a[i]]++;
        return;
      }
    }

    if (a.length() > b.length()) canMakeAnswer = false;
  }

 public:
  string alienOrder(vector<string> &words) {
    unordered_set<char> uniqueChars;

    int size = words.size();
    // initialize
    for (string &word : words) {
      for (char c : word) {
        uniqueChars.insert(c);
        inDegree[c] = 0;
        graph[c];
      }
    }

    for (int i = 0; i < size - 1; i++) {
      findDiff(words[i], words[i + 1]);
    }
    if (!canMakeAnswer) return "";

    queue<char> q;
    // push all indegree 0 node to q;
    for (auto &it : inDegree) {
      if (it.second == 0) {
        q.push(it.first);
      }
    }

    string answer = "";
    while (!q.empty()) {
      char cur = q.front();
      q.pop();

      answer += cur;

      for (char next : graph[cur]) {
        inDegree[next]--;

        if (inDegree[next] == 0) {
          q.push(next);
        }
      }
    }

    if (answer.length() != uniqueChars.size()) return "";

    reverse(answer.begin(), answer.end());
    return answer;
  }
};

// use topological sort (remove duplicate)

class Solution {
 private:
  unordered_map<char, unordered_set<char>> graph;
  unordered_map<char, unordered_set<char>> reverseGraph;
  unordered_map<char, int> inDegree;

  bool canMakeAnswer = true;

  void findDiff(string a, string b) {
    int length = min(a.length(), b.length());
    for (int i = 0; i < length; i++) {
      if (a[i] != b[i]) {
        graph[b[i]].insert(a[i]);
        reverseGraph[a[i]].insert(b[i]);
        return;
      }
    }
    // edge case
    if (a.length() > b.length()) canMakeAnswer = false;
  }

 public:
  string alienOrder(vector<string> &words) {
    unordered_set<char> uniqueChars;

    int size = words.size();
    // initialize
    for (string &word : words) {
      for (char c : word) {
        uniqueChars.insert(c);
        inDegree[c] = 0;
        graph[c];
      }
    }

    for (int i = 0; i < size - 1; i++) {
      findDiff(words[i], words[i + 1]);
    }
    if (!canMakeAnswer) return "";

    for (auto &it : reverseGraph) {
      inDegree[it.first] = it.second.size();
    }

    queue<char> q;
    // push all inDegree 0 node to q;
    for (auto &it : inDegree) {
      if (it.second == 0) {
        q.push(it.first);
      }
    }

    string answer = "";
    while (!q.empty()) {
      char cur = q.front();
      q.pop();

      answer += cur;

      for (char next : graph[cur]) {
        inDegree[next]--;

        if (inDegree[next] == 0) {
          q.push(next);
        }
      }
    }

    if (answer.length() != uniqueChars.size()) return "";

    reverse(answer.begin(), answer.end());
    return answer;
  }
};