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

int recursive(int left, int right, vector<int> &trees) {
  if (left == right) return trees[left];
  int mid = left + (right - left) / 2;

  int ret = max(recursive(left, mid, trees), recursive(mid + 1, right, trees));
  int lo = mid, hi = mid;
  int height = trees[mid];
  ret = max(ret, height);

  while (left < lo || hi < right) {
    if (hi < right && (lo == left || trees[lo - 1] < trees[hi + 1])) {
      hi++;
      height = min(height, trees[hi]);
    } else {
      lo--;
      height = min(height, trees[lo]);
    }
    ret = max(ret, height * (hi - lo + 1));
  }
  return ret;
}

int solution(vector<int> &trees) {
  int size = trees.size();

  return recursive(0, size - 1, trees);
}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  freopen("./input.txt", "r", stdin);

  int C;
  cin >> C;

  for (int testCase = 1; testCase <= C; testCase++) {
    int N;
    cin >> N;

    vector<int> trees(N);
    for (int i = 0; i < N; i++) {
      cin >> trees[i];
    }

    int answer = solution(trees);

    cout << answer << "\n";
  }

  return 0;
}
