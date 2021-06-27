#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// use union find

class Solution {
 public:
  string find(unordered_map<string, unordered_map<string, string>>& parents, string& name, string& email) {
    if (parents[name][email] == email) return email;

    return parents[name][email] = find(parents, name, parents[name][email]);
  }

  void merge(unordered_map<string, unordered_map<string, string>>& parents, string& name, string& email1, string& email2) {
    string parent1 = find(parents, name, email1);
    string parent2 = find(parents, name, email2);

    if (parent1 == parent2) return;
    if (parent1 > parent2) swap(parent1, parent2);

    parents[name][parent2] = parent1;
  }

  vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    unordered_map<string, unordered_map<string, string>> parents;
    vector<vector<string>> answer;

    // merge by group
    for (vector<string> account : accounts) {
      int size = account.size();
      string name = account.front();
      string parent = account[1];

      for (int i = 1; i < size; i++) {
        if (parents[name].find(account[i]) != parents[name].end()) {
          string emailParent = parents[name][account[i]];
          merge(parents, name, account[i], emailParent);
        } else {
          parents[name][account[i]] = account[i];
        }
        merge(parents, name, parent, account[i]);
      }
    }

    // divide by parents
    unordered_map<string, unordered_map<string, vector<string>>> groupByParents;
    for (auto& it : parents) {
      string name = it.first;

      for (auto& it2 : it.second) {
        string parent = find(parents, name, it2.second);

        groupByParents[name][parent].push_back(it2.first);
      }
    }

    // make answer
    for (auto& it : groupByParents) {
      string name = it.first;

      for (auto& it2 : it.second) {
        vector<string> line;
        line.push_back(name);

        for (string email : it2.second) {
          line.push_back(email);
        }

        sort(line.begin() + 1, line.end());
        answer.push_back(line);
      }
    }

    return answer;
  }
};