# 2682. Find the Losers of the Circular Game

[링크](https://leetcode.com/problems/find-the-losers-of-the-circular-game/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N, K라 하자.

중복 방문하는 순간 순회를 그만두어야 하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

방문 여부를 체크하기 위해 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(N)     |

각 순서마다 K를 여러번 더해야 한다. 이 때 수는 순회한다.

나머지 연산을 이용해 순회를 반복하고 방문한 숫자를 기록한다.

이후 중복 방문하는 경우 순회를 그만둔다.

```cpp
vector<int> circularGameLosers(int n, int k) {
  bool visited[51] = {
      false,
  };

  int cur = 0;
  int step = 1;
  while (visited[cur] == false) {
    visited[cur] = true;

    cur += (k * step);
    cur %= n;
    step++;
  }

  vector<int> answer;
  for (int i = 0; i < n; i++) {
    if (visited[i] == false) {
      answer.push_back(i + 1);
    }
  }
  return answer;
}
```

## 고생한 점
