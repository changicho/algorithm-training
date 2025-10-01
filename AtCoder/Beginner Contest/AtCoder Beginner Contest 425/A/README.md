# A - Sigma Cubes

[링크](https://atcoder.jp/contests/abc425/tasks/abc425_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

순회를 이용해 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

```cpp
auto solution(int n) {
  int answer = 0;

  for (int i = 1; i <= n; i++) {
    answer += i * i * i * (i % 2 == 0 ? +1 : -1);
  }

  return answer;
}
```

## 고생한 점
