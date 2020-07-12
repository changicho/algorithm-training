# 12906. 새로운 하노이 탑

[링크](https://www.acmicpc.net/problem/12906)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Gold III |  Gold III   |

## 설계

### 시간 복잡도

하나의 탑당 처음에 10개 씩 원판이 쌓일 수 있다.

최악의 경우 한 탑에 원판 30개가 쌓일 수 있다.

최악의 경우 가능한 경우의 수는

```cpp
30^3 * 30^3 * 30^3 = 27,000^3
```

이므로 제한 시간을 초과한다.

따라서 탐색할 때 중복된 경우는 건너뛰어야 한다.

### 공간 복잡도

A, B, C 세가지 경우만 표현하면 된다.

각 원판을 char 형으로 선언하고, 각 타워를 stack으로 만든다.

중복된 경우를 표현하기 위해서 다음과 같은 요소를 포함한 문자열을 생성한다.

- A타워의 상태
- B타워의 상태
- C타워의 상태

각 타워의 상태 사이에 특수문자를 끼워넣어 구분한다.

### BFS

먼저 각 타워의 상태를 표현하기 위해 구조체를 생성한다.

```cpp
struct Tower {
  vector<char> v; // 타워의 원판
  char target; // 타워에 있어야 하는 원판의 종류
};
```

타워에 쌓여있는 원판을 stack 대신 vector 로 선언한다. 이는 나중에 문자열로 치환할 때 편하게 처리하기 위함이다.

각 타워들의 현재 상황을 구조체로 다음과 같이 선언한다.

```cpp
struct Status {
  Tower tower[3];
  int count;
};
```

위 구조체들을 토대로 다음과 같이 bfs로 탐색한다.

```cpp
while (!q.empty()) {
  Status cur = q.front();
  q.pop();

  if (checking(cur)) {
    answer = cur.count;
    break;
  }
  string status_string = change(cur);
  if (visited.find(status_string) != visited.end()) continue;
  visited.insert(status_string);

  for (int from = 0; from < 3; from++) {
    for (int to = 0; to < 3; to++) {
      if (from == to) continue;
      Status next = cur;
      if (next.tower[from].v.empty()) continue;

      char target = next.tower[from].v.back();
      next.tower[to].v.push_back(target);
      next.tower[from].v.pop_back();

      next.count += 1;
      q.push(next);
    }
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     1732     |       76       |

## 고생한 점
