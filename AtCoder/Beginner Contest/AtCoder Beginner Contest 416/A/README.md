# A - Vacation Validation

[링크](https://atcoder.jp/contests/abc416/tasks/abc416_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

순회를 이용해 문자열을 한 번만 탐색하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

```cpp
int solution(int n, int left, int right, string &s) {
  for (int i = left - 1; i <= right - 1; i++) {
    if (s[i] != 'o') {
      return false;
    }
  }

  return true;
}
```

## 고생한 점
