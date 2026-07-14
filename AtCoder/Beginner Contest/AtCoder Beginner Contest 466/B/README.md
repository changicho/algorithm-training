# B - Representative Balls

[링크](https://atcoder.jp/contests/abc466/tasks/abc466_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 색마다 최대값을 저장하는데 O(M)의 시간 복잡도를 사용한다.

순회하며 각 색의 최대값을 갱신하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 색의 최대값을 저장하는데 O(M)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |  O(N + M)   |    O(M)     |

순회하며 각 색마다 최대 size를 갱신한다.

```cpp
vector<int> solution(int size, vector<pair<int, int>>& balls, int m) {
  vector<int> answer(m, -1);

  // color, size
  for (pair<int, int>& ball : balls) {
    int c = ball.first, s = ball.second;

    answer[c - 1] = max(answer[c - 1], s);
  }

  return answer;
}
```

## 고생한 점
