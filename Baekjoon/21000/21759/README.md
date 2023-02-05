# 21759. 두 개의 팀

[링크](https://www.acmicpc.net/problem/21759)

| 정답률 (%) |    난이도    |
| :--------: | :----------: |
|   21.678   | 플래티넘 III |

## 설계

### 시간 복잡도

노드의 갯수를 N이라 하자. (N <= 200,000)

각 노드들은 트리 구조이다. 따라서 사이클이 존재하지 않는다.

루트에서 부터 노드를 DFS로 순회하며 방문한 값들을 이용해 정답을 갱신할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS를 이용할 경우 O(N)의 공간 복잡도를 사용한다.

각 노드마다의 값들을 저장하기 위해 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     120      |    O(N)     |    O(N)     |

```cpp
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
```

## 고생한 점
