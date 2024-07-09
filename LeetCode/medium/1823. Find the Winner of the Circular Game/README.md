# 1823. Find the Winner of the Circular Game

[링크](https://leetcode.com/problems/find-the-winner-of-the-circular-game/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 두 수를 N, K라 하자.

시뮬레이션을 이용해 풀이할 경우 시간 복잡도는 O(N \* K) 이다.

수학적으로 풀이할 경우 시간 복잡도는 O(N) 이다.

### 공간 복잡도

큐를 이용해 시뮬레이션을 수행할 경우 O(N)의 공간 복잡도가 필요하다.

수학적으로 풀이할 경우 별도의 공간이 필요하지 않다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |  O(N \* K)  |    O(N)     |

큐를 이용해 시뮬레이션을 수행한다.

```cpp
int findTheWinner(int n, int k) {
  queue<int> q;
  for (int i = 1; i <= n; i++) {
    q.push(i);
  }

  while (q.size() > 1) {
    for (int i = 0; i < k - 1; i++) {
      q.push(q.front());
      q.pop();
    }

    q.pop();
  }

  return q.front();
}
```

## 고생한 점
