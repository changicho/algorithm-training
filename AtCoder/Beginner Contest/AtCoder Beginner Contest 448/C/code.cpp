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

struct Query {
  int size;
  vector<int> nums;
};

auto solution(int size, int qSize, vector<int>& balls, vector<Query>& queries) {
  vector<int> answer;

  multiset<int> ballSet;
  for (int& ball : balls) {
    ballSet.insert(ball);
  }

  for (Query& q : queries) {
    for (int& num : q.nums) {
      ballSet.erase(ballSet.find(balls[num - 1]));
    }
    answer.push_back(*ballSet.begin());

    for (int& num : q.nums) {
      ballSet.insert(balls[num - 1]);
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

  vector<Query> queries(Q);
  for (int i = 0; i < Q; i++) {
    cin >> queries[i].size;
    queries[i].nums.resize(queries[i].size);
    for (int j = 0; j < queries[i].size; j++) {
      cin >> queries[i].nums[j];
    }
  }

  auto answer = solution(N, Q, A, queries);

  // cout << answer << endl;
  // cout << (answer ? "Yes" : "No") << endl;
  for (auto& line : answer) {
    cout << line << "\n";
  }
  cout << endl;

  return 0;
}