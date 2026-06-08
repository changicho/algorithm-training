# B - The Honest Woodcutters

[링크](https://atcoder.jp/contests/abc461/tasks/abc461_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회를 하며 비교해 조건을 만족하는지 판단하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회 및 비교에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

배열 B에서 주어지는 값에 해당하는 인원이 가지고 있는 번호가 B의 index와 같은지 비교한다.

```cpp
bool solution(int size, vector<int>& a, vector<int>& b) {
  for (int i = 0; i < size; i++) {
    if (a[b[i] - 1] != i + 1) return false;
  }
  return true;
}
```

## 고생한 점
