# D - Placing Rooks

[링크](https://atcoder.jp/contests/abc466/tasks/abc466_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

2차원 배열의 크기를 N^2, 연산의 수를 M이라 하자.

연산을 역순회하며 이후에 삭제되지 않을 점을 센다.

이에 방문 배열과 순회에 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 축마다의 방문 배열에 O(N)의 공간 복잡도를 사용한다.

### 역순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |  O(N + M)   |    O(N)     |

현재 점의 y,x 축이 이후에 나올 경우 해당 점은 삭제된다.

따라서 점을 역으로 순회하며 현재 점의 축이 이후에 나오는것이 보장되면 현재 점을 정답에 추가하지 않는다.

이를 반복하며 남은 점의 수를 센다.

```cpp
using pii = pair<int, int>;

auto solution(int n, int size, vector<pii>& operations) {
  vector<bool> rows(n + 1, false);
  vector<bool> cols(n + 1, false);

  int answer = 0;
  for (int i = size - 1; i >= 0; i--) {
    pii& cur = operations[i];
    int y = cur.first, x = cur.second;

    if (!rows[y] && !cols[x]) answer++;

    rows[y] = cols[x] = true;
  }

  return answer;
}
```

## 고생한 점
