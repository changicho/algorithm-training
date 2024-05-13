# A - The bottom of the ninth

[링크](https://atcoder.jp/contests/abc351/tasks/abc351_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 두 배열 A, B의 크기는 9, 8 이다. 이를 각각 더하고 값을 비교한다.

이에 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

두 배열의 수를 각각 더하는 데 O(1)의 공간 복잡도가 필요하다.

### 구현

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

```cpp
int solution(vector<int> &a, vector<int> &b) {
  int aSum = accumulate(a.begin(), a.end(), 0),
      bSum = accumulate(b.begin(), b.end(), 0);

  if (bSum > aSum) return 0;
  return aSum - bSum + 1;
}
```

## 고생한 점
