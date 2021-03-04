# 2533. 사회망 서비스(SNS)

[링크](https://www.acmicpc.net/problem/2533)

|  난이도  | 정답률(\_%) | 시간 제한(초) |
| :------: | :---------: | :-----------: |
| Gold III |   35.335    |       3       |

## 설계

### 시간 복잡도

트리의 노드의 수는 최대 1,000,000개 까지이다.

### 공간 복잡도

정답의 개수는 노드의 개수 이하여야 하므로 최대 1,000,000 이하임이 보장된다.

따라서 int형으로 선언한다.

### 트리의 생성

입력받는 노드들의 관계를 그래프로 설정해준다.

```cpp
int from, to;
for (int i = 0; i < N - 1; i++) {
  cin >> from >> to;

  graph[from].push_back(to);
  graph[to].push_back(from);
}
```

이후 특정 노드 (1번노드)를 루트로 설정하고 탐색을 이어나간다.

여기서 입력받은 노드들의 관계는 트리임이 보장되므로 이전에 방문 여부를 판단하지 않아도 된다.

```cpp
void make_tree(int node, int parent) {
  // 부모에 자식을 집어넣음
  tree[parent].push_back(node);

  for (int next : graph[node]) {
    if (next == parent) continue;
    make_tree(next, node);
  }
}
```

### 일반식

```cpp
int dp[node][isEarly]; // node번째 노드가 얼리어답터인지 아닌제에 따라 최대로 전파 가능한 수
```

이 경우 1번 노드를 루트로 했을 때, 탐색의 끝에 존재하는 노드들만 초기값을 할당할 수 있다.

```cpp
dp[end_nodes][0] = 0;
dp[end_nodes][1] = 1;
```

이 때 현재 노드가 얼리어답터인지 아닌지 여부에 따라서 탐색의 범위가 좁혀진다.

현재 노드가 얼리어답터인경우 다음노드

- 얼리어답터임
- 얼리어답터가 아님

현재 노드가 얼리어답터가 아닌경우 다음노드

- 얼리어답터여야함

이는 현재 노드가 얼리어답터가 아닌경우에 다음노드가 얼리어답터가 아닌 경우, 모든 노드에 도달하지 못하는 경우가 생기기 때문이다.

(얼리 아답터가 아닌 사람들은 자신의 모든 친구들이 얼리 아답터일 때만 이 아이디어를 받아들인다.)

### 동적 계획법 (top-down)

시간 : 1004ms

끝에 존재하는 노드들을 탐색하며 dp를 갱신하기 위해 top-down 방식을 사용한다.

```cpp
int recursive(int node, bool isEarly) {
  if (visited[node][isEarly]) {
    return dp[node][isEarly];
  }
  visited[node][isEarly] = true;

  int count = isEarly ? 1 : 0;
  if (isEarly) {  // 현재 노드가 얼리어답터인 경우 자식은 아무 상태가 되어도 상관없다.
    for (int next : tree[node]) {
      count += min(recursive(next, false), recursive(next, true));
    }
  } else {  // 현재 노드가 얼리어답터가 아닌경우 자식은 얼리어답터여야함
    for (int next : tree[node]) {
      count += recursive(next, true);
    }
  }

  return dp[node][isEarly] = count;
}
```

이후 루트 노드(1번)가 얼리어답터인경우, 얼리어답터가 아닌 경우에 따라 dp배열을 갱신한다.

```cpp
recursive(1, false);
recursive(1, true);

int answer = min(dp[1][false], dp[1][true]);
```

### 동적 계획법 (bottom-up)

시간 : 1032ms

루트로부터 멀리 떨어져 있는 노드들 순으로 초기값을 설정해야 하므로 트리를 만들 때 다음과 같은 상태를 이용한다.

```cpp
struct Status {
  int node, depth;

  bool operator<(const Status &b) const {
    return depth > b.depth;
  }
};

void make_tree(int node, int parent, int depth) {
  tree[parent].push_back(node);

  for (int next : graph[node]) {
    if (next == parent) continue;
    make_tree(next, node, depth + 1);
  }
  node_visit_array.push_back({node, depth});
}
```

이후 트리를 만든 뒤 한번 정렬해준다.

```cpp
make_tree(1, 0, 0);
sort(node_visit_array.begin(), node_visit_array.end());
```

이후 dp배열을 갱신한다.

```cpp
for (Status cur : node_visit_array) {
  int node = cur.node;

  dp[node][true] = 1;
  dp[node][false] = 0;
  for (int next : tree[node]) {
    dp[node][true] += min(dp[next][false], dp[next][true]);
  }
  for (int next : tree[node]) {
    dp[node][false] += dp[next][true];
  }
}

int answer = min(dp[1][false], dp[1][true]);
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     1004     |       96       |

## 고생한 점
