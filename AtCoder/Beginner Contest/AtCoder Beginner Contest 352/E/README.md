# E - Clique Connect

[링크](https://atcoder.jp/contests/abc352/tasks/abc352_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

그래프의 노드의 갯수를 N, 연결관계를 표현하는 subset의 갯수를 M이라 하자.

(N <= 2 \* 10^5, M <= 2 \* 10^5)

각 subset에는 K'개의 노드가 존재한다.

모든 K'의 합은 4 \* 10^5 이하이며 이를 K라 하자.

모든 간선정보를 이용해 그래프를 만들 경우 간선의 갯수는 최대 K^2개가 존재한다.

이를 E라 했을 때 프림의 알고리즘을 이용할 경우 시간 복잡도는 O(K^2 * log_2(N)) 이다.

이는 제한시간 내에 불가능하다. (8 \* 10^10 이상이므로)

크루스칼 알고리즘을 이용해 유니온 파인드로 MST를 구할 수 있다.

각 subset을 cost로 정렬 후 낮은 cost부터 방문할 수 있다. 이 경우 정렬에 O(M \* log_2(M))의 시간 복잡도가 소요된다.

이후 각 subset을 순회하며 유니온 파인드를 이용해 연결할 경우 시간 복잡도는 O(M \* log_2(M) + K) 이다.

### 공간 복잡도

유니온 파인드에 O(N)의 공간 복잡도를 사용한다.

정렬에 O(M)의 공간 복잡도를 사용한다.

### 크루스칼 알고리즘

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      77      | O(M \* log_2(M) + K) |  O(N + M)   |

각 subset들은 C의 cost를 가진 간선으로 생각할 수 있다.

이를 cost를 기준으로 오름차순 정렬한다.

이후 크루스칼 알고리즘을 사용해 MST를 구한다.

```cpp
struct Subset {
  int cost;
  vector<int> nodes;
};

long long solution(int n, vector<Subset> &subsets) {
  sort(subsets.begin(), subsets.end(),
       [](const Subset &a, const Subset &b) { return a.cost < b.cost; });

  vector<int> parents(n + 1);
  for (int node = 1; node <= n; node++) {
    parents[node] = node;
  }
  int graphCount = n;

  long long answer = 0;

  function<int(int)> find = [&](int node) -> int {
    if (parents[node] == node) return node;
    return parents[node] = find(parents[node]);
  };

  function<void(int, int, int)> merge = [&](int a, int b, int cost) -> void {
    a = find(a);
    b = find(b);

    if (a == b) return;
    if (a < b) swap(a, b);

    graphCount--;
    answer += cost;
    parents[a] = b;
  };

  for (Subset &subset : subsets) {
    int parent = find(subset.nodes[0]);

    for (int node : subset.nodes) {
      merge(parent, node, subset.cost);
    }
  }

  if (graphCount > 1) return -1;

  return answer;
}
```

## 고생한 점
