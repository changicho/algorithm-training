#include <algorithm>
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

struct Node {
  int val1, val2, count1, count2;
};

struct SegmentTree {
  const Node NULL_VALUE = {0, 0, 0, 0};
  int size;
  vector<Node> tree;

  SegmentTree(vector<int> &array) {
    size = array.size();

    tree.resize(size * 4);

    init(1, 0, size - 1, array);
  }

  // operation part
  Node operation(Node x, Node y) {
    map<int, int> kv;
    kv[x.val1] += x.count1;
    kv[x.val2] += x.count2;
    kv[y.val1] += y.count1;
    kv[y.val2] += y.count2;

    auto it = kv.end();
    it--;
    int val1 = it->first, count1 = it->second;
    it--;
    int val2 = it->first, count2 = it->second;
    return {val1, val2, count1, count2};
  }

  // initialize part
  void init(int node, int start, int end, vector<int> &array) {
    if (start == end) {
      tree[node] = Node({array[start], 0, 1, 0});
      return;
    }

    int mid = (start + end) / 2;
    init(node * 2, start, mid, array);
    init(node * 2 + 1, mid + 1, end, array);

    tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
  }

  // query part
  Node query(int left, int right) { return query(1, 0, size - 1, left, right); }

  Node query(int node, int start, int end, int left, int right) {
    if (right < start || end < left) {
      return NULL_VALUE;
    }
    if (left <= start && end <= right) {
      return tree[node];
    }

    int mid = (start + end) / 2;
    Node leftPart = query(node * 2, start, mid, left, right);
    Node rightPart = query(node * 2 + 1, mid + 1, end, left, right);
    return operation(leftPart, rightPart);
  }

  // update part
  void update(int index, int val) { update(1, 0, size - 1, index, index, val); }

  void update(int node, int start, int end, int left, int right, int val) {
    if (right < start || end < left) {
      return;
    }
    if (start == end) {
      tree[node] = {val, 0, 1, 0};
      return;
    }

    int mid = (start + end) / 2;
    update(node * 2, start, mid, left, right, val);
    update(node * 2 + 1, mid + 1, end, left, right, val);

    tree[node] = operation(tree[node * 2], tree[node * 2 + 1]);
  }
};

vector<int> solution(vector<int> &arr, vector<vector<int>> &queries) {
  vector<int> answer;

  SegmentTree segmentTree(arr);

  for (vector<int> &q : queries) {
    int a = q[0], b = q[1], c = q[2];
    if (a == 1) {
      segmentTree.update(b - 1, c);
    } else {
      Node result = segmentTree.query(b - 1, c - 1);

      answer.push_back(result.count2);
    }
  }

  return answer;
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  cout.precision(10);

  // freopen("./input.txt", "r", stdin);

  int N, Q;
  cin >> N >> Q;
  vector<int> A(N);

  for (int i = 0; i < N; i++) {
    cin >> A[i];
  }

  vector<vector<int>> queries(Q);
  for (int i = 0; i < Q; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    queries[i] = {a, b, c};
  }

  vector<int> answer = solution(A, queries);

  for (int i = 0; i < answer.size(); i++) {
    cout << answer[i] << "\n";
  }

  return 0;
}