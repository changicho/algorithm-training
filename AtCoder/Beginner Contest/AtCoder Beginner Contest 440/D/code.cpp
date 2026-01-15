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

struct Query {
  int x, y;
};

int calc(vector<int>& nums, int x, int y) {
  int size = nums.size();

  int s = lower_bound(nums.begin(), nums.end(), x) - nums.begin();

  int left = s, right = size, target = size;
  while (left <= right) {
    int mid = (left + right) / 2;

    if (nums[mid] - x - mid + s >= y) {
      target = mid;
      right = mid - 1;
    } else {
      left = mid + 1;
    }
  }
  return target - s;
}

vector<int> solution(int size, vector<int>& nums, int qSize,
                     vector<Query>& queries) {
  vector<int> answer;

  sort(nums.begin(), nums.end());

  for (Query& query : queries) {
    int x = query.x;
    int y = query.y;

    int buffer = calc(nums, x, y);
    int cur = x + y - 1 + buffer;

    answer.push_back(cur);
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

  vector<Query> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i].x >> queries[i].y;
  }

  auto answer = solution(N, A, Q, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}