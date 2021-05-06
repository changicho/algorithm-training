# 72413. 합승 택시 요금

[링크](https://programmers.co.kr/learn/courses/30/lessons/72413)

| 난이도 | 완료(명) |
| :----: | :------: |
|  lv3   |   1427   |

## 설계

### 시간복잡도

모든 노드에 대해서 각 두 노드 사이의 거리를 모두 알아야 한다.

따라서 플로이드 와셜 알고리즘을 이용해 모든 노드 사이의 거리를 구할 수 있다. O(N^3)

이후 택시를 타고 같이 갈 노드 까지는 브루트 포스 방법으로 탐색한다.

노드의 최대 개수는 200 이므로 제한시간 내에 충분하다.

### 공간복잡도

플로이드 와셜 알고리즘을 사용할 경우 모든 노드 사이의 거리를 저장할 2차원 배열이 필요하다.

따라서 필요한 공간 복잡도는 O(N^2)이다.

거리를 계산할 때 덧셈이 들어가므로 overflow가 날 수도 있다.

최악의 경우 정답은 최악의 비용과 모든 노드의 곱 이므로 100,000 \* 200 이다.

이는 20,000,000 이며 덧셈 시에도 int형으로 overflow가 발생하지 않는다.

### 플로이드 워셜 알고리즘

모든 노드에 대해서 두 노드 사이의 최소 비용을 찾는 알고리즘이다.

어떤 특정 정점을 거쳤을 때의 경로가 최단이라면 table을 update한다.

이전에 구했던 최단 경로를 통해 새로운 최단 경로를 찾는 방식으로 진행된다.

먼저 이를 위해 간선들을 이용해 costs 배열을 만들어야 한다.

입력받는 간선의 정보가 A, B, Cost로 이루어져 있으므로 이를 파싱해 배열을 만든다.

여기서 입력받는 노드의 번째는 1번째부터 시작이므로 index와 맞춰 주기 위해 1씩 빼준다.

```cpp
s -= 1;
a -= 1;
b -= 1;
```

```cpp
vector<vector<int>> costs(n, vector<int>(n, 100000 * 200 + 1));

for (vector<int> fare : fares) {
  int from = fare[0] - 1;
  int to = fare[1] - 1;
  int cost = fare[2];

  costs[from][to] = cost;
  costs[to][from] = cost;
}

for (int i = 0; i < n; i++) {
  costs[i][i] = 0;
}
```

이후 플로이드 워셜 알고리즘을 이용해 모든 노드에 대해서 최단거리를 구한다.

```cpp
for (int through = 0; through < n; through++) {
  for (int from = 0; from < n; from++) {
    for (int to = 0; to < n; to++) {
      costs[from][to] = min(costs[from][to], costs[from][through] + costs[through][to]);
    }
  }
}
```

이후 시작지점에서 어느지점까지 같이 택시를 타고 갈 지를 브루트 포스를 이용해 구한다.

```cpp
// 택시를 이용하지 않는 경우
answer = costs[s][a] + costs[s][b];

for (int through = 0; through < n; through++) {
  int aCost = costs[s][through] + costs[through][a];
  int bCost = costs[through][b];

  answer = min(answer, aCost + bCost);
}
```

## 고생한 점
