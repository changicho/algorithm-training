#include <algorithm>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use union find

class Solution {
 private:
  struct Node {
    string parent;
    double value;
  };
  unordered_map<string, Node> data;

  string find(string key, double &value) {
    while (data[key].parent != key) {
      value = value * data[key].value;
      key = data[key].parent;
    }

    return key;
  }

  void merge(string a, string b, double v) {
    double valueA = 1.0, valueB = 1.0;
    string parentA = find(a, valueA), parentB = find(b, valueB);

    if (parentA == parentB) return;
    data[parentA].parent = parentB;
    data[parentA].value = v * valueB / valueA;
  }

 public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    for (int i = 0; i < equations.size(); i++) {
      string a = equations[i][0], b = equations[i][1];
      double value = values[i];

      if (!data.count(a)) {
        data[a].parent = a;
        data[a].value = 1;
      }

      if (!data.count(b)) {
        data[b].parent = b;
        data[b].value = 1.0;
      }

      merge(a, b, value);
    }

    vector<double> answer;
    for (vector<string> &query : queries) {
      if (!data.count(query[0]) || !data.count(query[1])) {
        answer.push_back(-1);
        continue;
      }

      double valueA = 1, valueB = 1;
      string parentA = find(query[0], valueA), parentB = find(query[1], valueB);

      if (parentA != parentB) {
        answer.push_back(-1);
      } else {
        answer.push_back(valueA / valueB);
      }
    }
    return answer;
  }
};

// use memoization & DFS

class Solution {
 private:
  unordered_map<string, unordered_map<string, double>> memo;

  double recursive(string from, string to, unordered_set<string> &visited) {
    if (memo[from].find(to) != memo[from].end()) return memo[from][to];

    double ret = 0;
    for (pair<const string, double> &next : memo[from]) {
      if (visited.find(next.first) != visited.end()) continue;
      visited.insert(next.first);

      double value = recursive(next.first, to, visited);

      if (value == 0) continue;

      ret = next.second * value;
      break;
    }
    return ret;
  }

 public:
  vector<double> calcEquation(vector<vector<string>> &equations,
                              vector<double> &values,
                              vector<vector<string>> &queries) {
    vector<double> answer;
    for (int i = 0; i < values.size(); ++i) {
      double value = values[i];
      string from = equations[i][0], to = equations[i][1];

      memo[from].insert({to, value});
      if (value == 0) continue;

      memo[to].insert({from, 1 / value});
    }

    for (vector<string> &query : queries) {
      string &from = query[0], &to = query[1];

      unordered_set<string> visited;
      double diff = recursive(from, to, visited);

      if (diff) {
        answer.push_back(diff);
      } else {
        answer.push_back(-1);
      }
    }
    return answer;
  }
};