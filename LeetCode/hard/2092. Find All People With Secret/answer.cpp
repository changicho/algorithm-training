#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

// use sort & union find reset
// time : O(E * (log_2(E) + V))
// space : O(E + V)
class Solution {
 private:
  int find(int node, unordered_map<int, int> &parents) {
    if (parents[node] == node) return node;
    return find(parents[node], parents);
  }

  void merge(int a, int b, unordered_map<int, int> &parents) {
    a = find(a, parents), b = find(b, parents);
    if (a > b) swap(a, b);
    parents[b] = a;
  }

  void choose(vector<vector<int>> &edges, unordered_set<int> &knows) {
    unordered_map<int, int> parents;

    for (vector<int> &e : edges) {
      int a = e[0], b = e[1];
      parents[a] = a;
      parents[b] = b;
    }
    for (vector<int> &e : edges) {
      int a = e[0], b = e[1];

      merge(a, b, parents);
    }
    for (vector<int> &e : edges) {
      int a = e[0], b = e[1];

      if (knows.count(a) > 0) {
        knows.insert(find(a, parents));
      }
      if (knows.count(b) > 0) {
        knows.insert(find(b, parents));
      }
    }
    for (vector<int> &e : edges) {
      int a = e[0], b = e[1];
      if (knows.count(find(a, parents))) {
        knows.insert(a);
        knows.insert(b);
      }
    }
  }

 public:
  vector<int> findAllPeople(int n, vector<vector<int>> &meetings,
                            int firstPerson) {
    sort(meetings.begin(), meetings.end(),
         [](auto &a, auto &b) { return a[2] < b[2]; });

    int time = 0;

    unordered_set<int> knows;
    knows.insert(0);
    knows.insert(firstPerson);

    vector<vector<int>> selected;

    for (vector<int> &m : meetings) {
      int a = m[0], b = m[1], t = m[2];

      if (t != time) {
        time = t;
        choose(selected, knows);
        selected.clear();
      }

      selected.push_back({a, b});
    }

    choose(selected, knows);
    selected.clear();

    vector<int> answer(knows.begin(), knows.end());
    sort(answer.begin(), answer.end());
    return answer;
  }
};