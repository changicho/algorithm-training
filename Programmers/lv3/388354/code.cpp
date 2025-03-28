#include <algorithm>
#include <climits>
#include <cmath>
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

vector<int> solution(vector<int> nodes, vector<vector<int>> edges) {
  int size = nodes.size();

  vector<int> parent(size);
  vector<int> children(size);

  function<int(int)> find = [&parent, &find](int a) {
    if (parent[a] == a) {
      return a;
    }
    return parent[a] = find(parent[a]);
  };

  function<void(int, int)> merge = [&parent, &find](int a, int b) {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (a > b) swap(a, b);

    parent[b] = a;
  };

  unordered_map<int, int> converted;
  for (int i = 0; i < size; i++) {
    parent[i] = i;
    converted[nodes[i]] = i;
  }

  for (vector<int> &edge : edges) {
    int a = converted[edge[0]];
    int b = converted[edge[1]];

    children[a]++;
    children[b]++;

    merge(a, b);
  }

  vector<int> forward(size);
  vector<int> reverse(size);
  for (int node = 0; node < size; node++) {
    int parent = find(node);
    int val = nodes[node];

    if ((val % 2) == (children[node] % 2)) {
      forward[parent]++;
    } else {
      reverse[parent]++;
    }
  }

  int forwardCount = 0, reverseCount = 0;
  for (int node = 0; node < size; node++) {
    if (find(node) != node) continue;

    if (forward[node] == 1) forwardCount++;
    if (reverse[node] == 1) reverseCount++;
  }

  return {forwardCount, reverseCount};
}