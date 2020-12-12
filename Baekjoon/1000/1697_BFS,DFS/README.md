# 1697. 숨바꼭질

[링크](https://www.acmicpc.net/problem/1697)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   24.857    |

## 설계

### 시간 복잡도

두 점의 좌표는 100,000 이하이다.

모든 경우를 탐색할 경우 중복되는 경우가 많으므로 중복되는 경우에서의 탐색은 제외해야한다.

메모이제이션을 이용한다.

### 공간 복잡도

K보다 큰 위치에서 감소해 정답에 도달할 수 있으므로 중복되는 경우의 axis는 최대 2K 크기까지 만든다.

좌표의 값들은 최대 100,000 이하이므로 int형으로 선언한다.

### BFS를 이용한 방법

다음과 같은 구조체로 관리한다.

```cpp
struct Status {
  int axis;
  int depth;
};
```

중복되는 경우를 제외하기 위해 다음과 같은 memoization를 선언한다.

```cpp
int table[200001];
memset(table, -1, sizeof(table));
```

탐색을 진행하면서 불가능한 경우는 탐색을 더이상 진행하지 않는다.

```cpp
queue<Status> q;
q.push({N, 0});

while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (cur.axis < 0 || cur.axis > 2 * K) continue;
  if (table[cur.axis] != -1 && table[cur.axis] < cur.depth) continue;
  table[cur.axis] = cur.depth;

  if (cur.axis == K) {
    answer = cur.depth;

    while (!q.empty()) q.pop();
    continue;
  }

  q.push({cur.axis + 1, cur.depth + 1});
  q.push({cur.axis - 1, cur.depth + 1});
  q.push({cur.axis * 2, cur.depth + 1});
}
```

### 재귀호출을 이용한 방법

K에서 탐색을 진행해 N으로 도달 가능한지 판별한다.

```cpp
int recursive(int axis, int target) {
  if (axis <= target) {
    return target - axis;
  } else if (axis == 1) {
    return 1;
  } else if (axis % 2) {
    return 1 + min(recursive(axis - 1, target), recursive(axis + 1, target));
  } else {
    return min(axis - target, 1 + recursive(axis / 2, target));
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      16      |       0        |

## 고생한 점
