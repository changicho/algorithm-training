# 2025 프로그래머스 코드챌린지 2차 예선 - 서버 증설 횟수

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/389479)

| 난이도 |
| :----: |
|  lv2   |

## 설계

### 시간 복잡도

players의 크기를 N이라 하자. (N = 24)

players 중 최대값을 X라 하자.

각 경우를 시뮬레이션을 수행해 구현할 경우 O(N)의 시간 복잡도가 소요된다.

큐를 이용해 최대값을 직접 구현할 경우 O(N \* X)의 시간 복잡도가 소요된다.

상수를 이용해 최대값을 직접 구현할 경우 O(N)의 시간 복잡도가 소요된다.

이는 O(1)이다.

### 공간 복잡도

큐를 이용해 서버의 수를 직접 구현할 경우 O(X)의 공간 복잡도가 필요하다.

상수를 이용해 서버의 수를 직접 구현할 경우 O(1)의 공간 복잡도가 필요하다.

### 시뮬레이션

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(1)     |    O(1)     |

각 시간마다 반환되는 서버의 수를 관리하는 배열을 사용한다.

각 과정마다 증설되는 서버와 각 서버들의 반환되는 시간을 관리한다.

시뮬레이션을 이용해 정답을 구한다.

```cpp
int solution(vector<int> players, int m, int k) {
  int reserved[24] = {
      0,
  };
  int server = 0;

  int answer = 0;
  for (int time = 0; time < 24; time++) {
    server -= reserved[time];

    int player = players[time];
    int capacity = (server + 1) * m - 1;

    int diff = player - capacity;

    int needed = max(0, (int)ceil((double)diff / m));

    answer += needed;
    server += needed;

    if (time + k < 24) {
      reserved[time + k] += needed;
    }
  }

  return answer;
}
```

## 고생한 점
