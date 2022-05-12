# 2264. Largest 3-Same-Digit Number in String

[링크](https://leetcode.com/problems/largest-3-same-digit-number-in-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

num의 길이를 N이라 하자.

각 좌표를 순회하며 연이어 3개의 숫자가 같은 경우를 찾는다.

이 경우 한번의 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

상수크기의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

각 index를 순회하며 해당 index를 시작점으로 하는 연속된 3개의 수를 만든다.

이를 구현하면 다음과 같다.

```cpp
string largestGoodInteger(string num) {
  int length = num.length();

  string largest = "";

  for (int i = 0; i <= length - 3; i++) {
    string cur = {num[i]};
    for (int j = 1; j < 3; j++) {
      cur += num[i + j];
    }

    if (cur[0] == cur[1] && cur[1] == cur[2]) {
      largest = max(largest, cur);
    }
  }

  return largest;
}
```

## 고생한 점
