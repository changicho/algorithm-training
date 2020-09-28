# 43164. 여행경로

[링크](https://programmers.co.kr/learn/courses/30/lessons/43164)

| 난이도 | 완료 (명) |
| :----: | :-------: |
|  lv3   |   3397    |

## 설계

### 시간 복잡도

공항의 수는 최대 10,000개 이하이다. 항공권의 개수의 제한은 주어지지 않는다고하자.

각 경우에서 최선의 수를 탐색하며 (알파벳 빠른순) 티켓을 소모하면 된다.

최악의 경우 모든 경우의 수를 검사해야 하며 이는 티켓의 수가 주어지지 않았으므로 측정이 불가능하다.

### 공간 복잡도

항공권의 수가 int형을 벗어나는 경우 제한시간 내에 탐색이 불가능하다.

따라서 항공권이 최대 개수는 int형 이내라고 가정하고 풀이한다.

map 구조를 사용해 각 경우마다 탐색을 빠르게 한다. 이 때 map을 순회할 때는 알파벳 순으로 자동으로 순회한다.

### map

map의 구조를 다음과 같이 설정한다.

```cpp
// key 공항에서 사용할 수 있는 티켓
// value : key 도착지, value 티켓의 갯수
map<string, map<string, int>> m;
```

같은 티켓이 중복될 수 있으므로 set이 아닌 int형 value를 가지는 map으로 구성함

### DFS

모든 티켓을 때는 현재까지 지나온 공항의 수 - 1 == 티켓의 수 인 경우이다.

알파벳 순으로 자동적으로 탐색하므로, 한번 조건을 만족하는 경우 그 경우가 답이다.

```cpp
void dfs(string start, vector<string> routes) {
  if (isOver) return;

  int countLeft = 0;
  routes.push_back(start);

  if (ticket_size == routes.size() - 1) {
    isOver = true;
    answer = routes;
    return;
  }

  for (auto it = m[start].begin(); it != m[start].end(); it++) {
    string next = it->first;
    if (m[start][next] == 0) continue;

    m[start][next] -= 1;
    dfs(next, routes);
    if (isOver) return;
    m[start][next] += 1;
  }
}
```

## 고생한 점
