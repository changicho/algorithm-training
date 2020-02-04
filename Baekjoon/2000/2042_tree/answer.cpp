#include <math.h>
#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<long long> tree;
vector<long long> nums;

void update(int node, int left, int right, int targetIndex, long diff) {
  if (targetIndex < left || right < targetIndex) {
    return;
  } else {
    tree[node] += diff;
    if (left == right) return;

    int mid = (left + right) / 2;
    update(node * 2, left, mid, targetIndex, diff);
    update(node * 2 + 1, mid + 1, right, targetIndex, diff);
  }
}

long long query(int node, int left, int right, int targetL, int targetR) {
  // if it is outof range, return
  if (targetR < left || right < targetL) {
    return 0;
  }
  // if it is exact range, return it
  else if (targetL <= left && right <= targetR) {
    return tree[node];
  }
  // if it is combined with usefull & useless range
  else {
    int mid = (left + right) / 2;
    return query(node * 2, left, mid, targetL, targetR) +
           query(node * 2 + 1, mid + 1, right, targetL, targetR);
  }
}

long long makeTree(int left, int right, int node_index) {
  if (left == right) {
    return tree[node_index] = nums[left];
  }

  int mid = (left + right) / 2;

  tree[node_index] += makeTree(left, mid, node_index * 2);
  tree[node_index] += makeTree(mid + 1, right, node_index * 2 + 1);

  return tree[node_index];
}

void solution() {
  int N, M, K;
  cin >> N >> M >> K;

  int numSize = pow(2, (int)ceil(log2(N)));
  nums.resize(numSize + 1);

  int treeSize = pow(2, (int)ceil(log2(numSize) + 1));
  tree.resize(treeSize + 1);

  for (int i = 1; i <= N; i++) {
    cin >> nums[i];
  }
  makeTree(1, nums.size() - 1, 1);

  for (int i = 0; i < M + K; i++) {
    int a;
    long long b, c;

    cin >> a >> b >> c;

    if (a == 1) {
      long long diff = c - nums[b];
      nums[b] = c;

      update(1, 1, nums.size() - 1, b, diff);
    } else {
      cout << query(1, 1, nums.size() - 1, b, c) << "\n";
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  solution();

  return 0;
}