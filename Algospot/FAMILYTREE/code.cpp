#include <algorithm>
#include <climits>
#include <cmath>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

template <class T>
struct SegmentTree {
  const T NULL_VALUE = INT_MAX;
  int size;
  vector<T> tree;

  SegmentTree(vector<T> &array) {
    size = array.size();

    tree.resize(size * 4);

    init(1, 0, size - 1, array);
  }

  // operation part

  T operation(T x, T y) { return min(x, y); }

  // initialize part

  void init(int node, int start, int end, vector<T> &array) {
    if (start == end) {
      tree[node] = array[start];
      return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid, array);
    init(node * 2 + 1, mid + 1, end, array);

    tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
  }

  // query part

  T query(int left, int right) { return query(1, 0, size - 1, left, right); }

  T query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
      return NULL_VALUE;
    }
    if (left <= start && end <= right) {
      return tree[node];
    }

    int mid = (start + end) / 2;
    T leftPart = query(node * 2, start, mid, left, right);
    T rightPart = query(node * 2 + 1, mid + 1, end, left, right);
    return operation(leftPart, rightPart);
  }
};

void preOrder(int node, vector<vector<int>> &graph, vector<int> &visitPath,
              unordered_map<int, int> &newIndex, int depth,
              vector<int> &depths) {
  if (newIndex.count(node) == 0) {
    newIndex[node] = newIndex.size();
  }
  depths[node] = depth;

  visitPath.push_back(newIndex[node]);

  for (int &child : graph[node]) {
    preOrder(child, graph, visitPath, newIndex, depth + 1, depths);
    visitPath.push_back(newIndex[node]);
  }
}

void solution() {
  int N, Q;
  cin >> N >> Q;

  vector<vector<int>> graph(N);
  for (int node = 1; node < N; node++) {
    int parent;
    cin >> parent;

    graph[parent].push_back(node);
  }

  vector<int> visitPath;
  unordered_map<int, int> newIndex;
  vector<int> depths(N);

  preOrder(0, graph, visitPath, newIndex, 0, depths);

  unordered_map<int, int> newIndexReverse;
  for (auto &it : newIndex) {
    int key = it.first, val = it.second;
    newIndexReverse[val] = key;
  }

  vector<int> firstIndex(N, -1);
  for (int i = 0; i < visitPath.size(); i++) {
    int cur = visitPath[i];

    firstIndex[cur] = i;
  }

  SegmentTree<int> segment(visitPath);

  for (int i = 0; i < Q; i++) {
    int leftNode, rightNode;
    cin >> leftNode >> rightNode;

    int left = firstIndex[newIndex[leftNode]];
    int right = firstIndex[newIndex[rightNode]];

    if (left > right) swap(left, right);
    int LCA = newIndexReverse[segment.query(left, right)];

    int leftDepth = depths[leftNode] - depths[LCA];
    int rightDepth = depths[rightNode] - depths[LCA];

    cout << leftDepth + rightDepth << "\n";
  }
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 0; testCase < C; testCase++) {
    solution();
  }

  return 0;
}