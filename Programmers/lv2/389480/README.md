# 2025 프로그래머스 코드챌린지 2차 예선 - 완전범죄

[링크](https://school.programmers.co.kr/learn/courses/30/lessons/389480)

| 난이도 |
| :----: |
|  lv2   |

## 설계

### 시간 복잡도

배열 info의 수를 L, 각 도둑 a, b의 한계를 N, M이라 하자.

동적 계획법을 사용해 모든 경우를 탐색할 경우 시간 복잡도는 O(L \* N \* M)이다.

### 공간 복잡도

동적 계획법에 O(L \* N \* M)의 공간 복잡도가 필요하다.

직전값만 사용하므로 이를 최적화 하면 O(N \* M)의 공간 복잡도로 줄일 수 있다.

### 동적 계획법

|  시간 복잡도   | 공간 복잡도 |
| :------------: | :---------: |
| O(L \* N \* M) |  O(N \* M)  |

i번째 info까지 방문했을 때 다음과 같은 경우의 수 들이 존재한다.

- A가 남긴 흔적의 경우
- B가 남긴 흔적의 경우

해당 2가지 경우에 대해서 현재 info를 A, B 둘 중 한명이 선택하는 경우를 탐색할 수 있다.

이를 이용해 각 info를 순회하며 A, B의 흔적에 대해 탐색하며 dp배열을 갱신한다.

```cpp
int solution(vector<vector<int>> info, int n, int m) {
  int size = info.size();

  bool dp[121][121] = {
      false,
  };

  dp[0][0] = true;
  for (int i = 1; i <= size; i++) {
    bool curDp[121][121] = {
        false,
    };
    int aCost = info[i - 1][0], bCost = info[i - 1][1];

    for (int a = 0; a < n; a++) {
      for (int b = 0; b < m; b++) {
        if (!dp[a][b]) continue;

        if (a + aCost < n) {
          curDp[a + aCost][b] = true;
        }
        if (b + bCost < m) {
          curDp[a][b + bCost] = true;
        }
      }
    }

    swap(dp, curDp);
  }

  for (int a = 0; a < n; a++) {
    for (int b = 0; b < m; b++) {
      if (dp[a][b]) return a;
    }
  }

  return -1;
}
```

## 고생한 점
