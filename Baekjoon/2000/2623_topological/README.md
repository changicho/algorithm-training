# 2623. 음악프로그램

[링크](https://www.acmicpc.net/problem/2623)

| 난이도  | 정답률(\_%) | 시간 제한(초) |
| :-----: | :---------: | :-----------: |
| Gold II |   48.953    |       1       |

## 설계

### 시간 복잡도

가수의 총 수는 1,000 까지이다. PD들이 정한 순서는 최대 100개 까지이다.

위상 정렬을 이용할 경우 시간 복잡도는 O(V+E) 이다. 간선은 최대 100^2 미만이므로 최악의 경우도 제한시간 1초 내에 충분하다.

### 공간 복잡도

입력받는 수들은 전부 1,000 이하이므로 int형으로 선언한다.

### 위상 정렬

위상 정렬은 순서가 정해져있는 작업 차례로 수행해야 할 때, 그 순서를 결정해주는 알고리즘이다.

초기 그래프를 생성할 때, 우선 순위 순서만 주어지므로 이를 분석해 그래프를 생성한다.

```cpp
cin >> size;
if (size == 0) continue;

vector<int> array(size);
cin >> array[0];
for (int i = 1; i < size; i++) {
  cin >> array[i];

  int from = array[i - 1], to = array[i];
  graph[from].push_back(to);
  inDegree[to] += 1;
}
```

```cpp
queue<int> q;
for (int node = 1; node <= N; node++) {
  if (inDegree[node] == 0) {
    q.push(node);
  }
}

for (int index = 0; index < N; index++) {
  if (q.empty()) {
    // 사이클이 발생해 위상정렬이 불가능한 경우
    result.resize(0);
    result.clear();
    result.push_back(0);

    break;
  }

  int cur = q.front();
  q.pop();
  result[index] = cur;

  for (int next : graph[cur]) {
    inDegree[next]--;

    if (inDegree[next] == 0) {
      q.push(next);
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점

사이클이 발생해 정렬을 수행할 수 없는경우의 처리가 없었음.
