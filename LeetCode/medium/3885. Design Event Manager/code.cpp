#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <functional>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

using ll = long long;

// BST set
// time : O(N * log_2(N))
// space : O(N)
class EventManager {
 private:
  set<pair<int, int>> s;
  unordered_map<int, int> um;

 public:
  EventManager(vector<vector<int>>& events) {
    for (vector<int>& e : events) {
      int id = e[0], p = e[1];

      um[id] = p;
      s.insert({p, -id});
    }
  }

  void updatePriority(int eventId, int newPriority) {
    int beforeP = um[eventId];
    um[eventId] = newPriority;

    s.erase({beforeP, -eventId});
    s.insert({newPriority, -eventId});
  }

  int pollHighest() {
    if (s.empty()) return -1;

    auto it = prev(s.end());
    int target = abs(it->second);
    s.erase(it);

    return target;
  }
};

// BST map
// time : O(N * log_2(N))
// space : O(N)
class EventManager {
 private:
  map<int, set<int>> m;
  unordered_map<int, int> um;

 public:
  EventManager(vector<vector<int>>& events) {
    for (vector<int>& e : events) {
      int id = e[0], p = e[1];

      m[p].insert(id);
      um[id] = p;
    }
  }

  void updatePriority(int eventId, int newPriority) {
    int beforeP = um[eventId];

    m[beforeP].erase(eventId);
    if (m[beforeP].size() == 0) {
      m.erase(beforeP);
    }

    um[eventId] = newPriority;
    m[newPriority].insert(eventId);
  }

  int pollHighest() {
    if (m.size() == 0) return -1;
    auto it = prev(m.end());
    int p = it->first;
    int target = *(it->second.begin());

    it->second.erase(target);
    if (it->second.size() == 0) {
      m.erase(p);
    }

    return target;
  }
};
