# 11400. 단절선

[링크](https://www.acmicpc.net/problem/11400)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |   36.952    |

## 설계

### dfs를 이용한 단절선 찾기

```cpp
vector<vector<int>> graph;
vector<int> discovered;
// from, to
vector<pair<int, int>> cutLines;

int start_node = 1;

int findCutLine(int here, int parent) {
  discovered[here] = start_node;
  start_node += 1;

  int ret = discovered[here];

  for (int next : graph[here]) {
    if (next == parent) continue;

    if (discovered[next]) {
      ret = min(ret, discovered[next]);
      continue;
    }

    int prev = findCutLine(next, here);

    if (prev > discovered[here]) {
      int from = min(here, next);
      int to = max(here, next);

      cutLines.push_back({from, to});
    }

    ret = min(ret, prev);
  }

  return ret;
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     212      |                |

## 고생한 점

cutLines의 형태를 vector<pair<int, int>> cutLines 로 하지 않으면 런타임 에러가 발생했다.

```cpp
struct line{
  int from, to
};
```

위와 같은 형태로 생성하고, compare 함수를 만들어도 런타임 에러가 발생...

pair를 사용하는 것을 연습해야 겠다.
