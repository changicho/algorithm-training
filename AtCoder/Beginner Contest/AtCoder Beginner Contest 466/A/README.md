# A - Compromise

[링크](https://atcoder.jp/contests/abc466/tasks/abc466_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회해 0 이상의 값이 있는지 판단하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(1)     |

```cpp
bool solution(int size, vector<int>& x) {
  for (int& num : x) {
    if (num >= 0) return false;
  }

  return true;
}
```

## 고생한 점
