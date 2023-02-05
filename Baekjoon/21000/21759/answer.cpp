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

typedef long long ll;

using namespace std;

const int MAX = 1e9 + 1;

int skill[200001];
// dp1[i]; i가 팀장이 되어 팀을 구성했을 때 최대 점수
// dp2[i]; i가 팀장일 때 i의 자식 노드들에 대해 dp1[i]에 속하지 않은 정점을
// 대상으로 팀을 구성했을 때 최대 점수
// dp3[i]; i가 루트인 서브 트리가 가질 수 있는 최대 점수
ll dp1[200001], dp2[200001], dp3[200001];
vector<int> tree[200001];

void dfs(int node, ll &answer) {
  dp1[node] = skill[node];
  dp2[node] = -1e18;

  vector<ll> dp3Children;
  for (int child : tree[node]) {
    dfs(child, answer);

    if (dp1[child] > 0) {
      dp1[node] += dp1[child];
      dp2[node] = max(dp2[node], dp2[child]);
    } else {
      dp2[node] = max(dp2[node], dp3[child]);
    }
    dp3Children.push_back(dp3[child]);
  }

  answer = max(answer, dp1[node] + dp2[node]);

  dp3[node] = dp1[node];

  // pick from child node case
  if (dp3Children.empty()) return;
  sort(dp3Children.begin(), dp3Children.end(), greater<ll>());

  dp3[node] = max(dp3[node], dp3Children[0]);
  if (dp3Children.size() >= 2) {
    answer = max(answer, dp3Children[0] + dp3Children[1]);
  }
}

long long solution() {
  ll answer = -1e18;
  dfs(1, answer);

  return answer;
}

void init() {}

void clear() {}

int main() {
  ios_base ::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);

  // // decimal point
  // cout << fixed;
  // cout.precision(8);

  init();

  // freopen("./input.txt", "r", stdin);

  int N;
  cin >> N;

  for (int i = 1; i <= N; i++) {
    int parent;
    cin >> skill[i] >> parent;

    if (parent > 0) {
      tree[parent].push_back(i);
    }
  }

  long long answer = solution();

  cout << answer << "\n";

  return 0;
}
