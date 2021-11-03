#include <algorithm>
#include <iostream>
#include <queue>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use union find - rank & heap & hashmap

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
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int length = s.length();

    parents.resize(length);
    counts.resize(length, 1);

    for (int i = 0; i < length; i++) {
      parents[i] = i;
    }

    for (vector<int>& pair : pairs) {
      int first = find(pair[0]), second = find(pair[1]);

      merge(first, second);
    }

    unordered_map<int, priority_queue<char, vector<char>, greater<char>>> um;
    for (int i = 0; i < length; i++) {
      int key = find(i);
      char value = s[i];

      um[key].push(value);
    }

    string answer(length, ' ');
    for (int i = 0; i < length; i++) {
      int key = find(i);
      answer[i] = um[key].top();
      um[key].pop();
    }

    return answer;
  }
};

// use union find - rank & hash map

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
  string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
    int length = s.length();

    parents.resize(length);
    counts.resize(length, 1);
    for (int i = 0; i < length; i++) {
      parents[i] = i;
    }

    for (vector<int>& pair : pairs) {
      int first = find(pair[0]), second = find(pair[1]);

      merge(first, second);
    }
    string answer(length, ' ');
    unordered_map<int, vector<int>> um;

    for (int i = 0; i < length; i++) {
      int key = find(i);
      int value = i;

      um[key].emplace_back(value);
    }

    for (auto& it : um) {
      int key = find(it.first);
      vector<int> array = it.second;

      string line = "";
      for (int& i : array) {
        line += s[i];
      }
      sort(line.begin(), line.end());

      int index = 0;
      for (int i : array) {
        answer[i] = line[index];
        index++;
      }
    }

    return answer;
  }
};