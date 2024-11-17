# 2023 KAKAO BLIND RECRUITMENT - 미로 탈출 명령어

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/150365)

| 난이도 |
| :----: |
|  lv3   |

## 설계

### 시간 복잡도

입력받은 2차원 배열의 크기를 N \* M, 단계를 K라 하자.

동적 계획법을 이용할 경우 O(N \* M \* K)의 시간 복잡도가 소요된다.

### 공간 복잡도

동적 계획법에 O(N \* M \* K)의 공간 복잡도가 필요하다.

직전값만 필요하므로 이를 개선할 경우 O(N \* M)의 공간 복잡도가 필요하다.

### 동적 계획법

|  시간 복잡도   | 공간 복잡도 |
| :------------: | :---------: |
| O(N \* M \* K) |  O(N \* M)  |

각 좌표마다 다음 좌표로 이동하는 path를 저장한다. 이 때 사전순으로 앞서는 경우만 탐색함에 유의한다.

이를 K번 반복하며, 이후 목표 좌표에 도달한 경우 해당 path를 반환한다.

```cpp
struct Axis {
  int y, x;
};

struct Status {
  Axis axis;
  string path;
};

char dirChars[4] = {'l', 'r', 'u', 'd'};
Axis dirs[4] = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

string solution(int n, int m, int x, int y, int r, int c, int k) {
  vector<vector<string>> dp(n, vector<string>(m, "-"));

  Axis start = {x - 1, y - 1}, goal = {r - 1, c - 1};

  dp[start.y][start.x] = "";

  for (int step = 0; step < k; step++) {
    vector<vector<string>> newDp(n, vector<string>(m, "-"));

    for (int y = 0; y < n; y++) {
      for (int x = 0; x < m; x++) {
        if (dp[y][x] == "-") continue;

        for (int i = 0; i < 4; i++) {
          string nextPath = dp[y][x];
          nextPath += dirChars[i];

          Axis next = {y + dirs[i].y, x + dirs[i].x};

          if (next.y < 0 || next.y >= n || next.x < 0 || next.x >= m) continue;
          if (newDp[next.y][next.x] == "-") {
            newDp[next.y][next.x] = nextPath;
          } else {
            newDp[next.y][next.x] = min(newDp[next.y][next.x], nextPath);
          }
        }
      }
    }

    dp = newDp;
  }

  if (dp[goal.y][goal.x] == "-") {
    return "impossible";
  }

  return dp[goal.y][goal.x];
}
```

## 고생한 점
