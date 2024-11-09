# 2275. Largest Combination With Bitwise AND Greater Than Zero

[링크](https://leetcode.com/problems/largest-combination-with-bitwise-and-greater-than-zero/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 candidates의 길이를 N이라 하자.

모든 숫자의 비트들 중에 겹치는 갯수가 가장 많은 수를 구해야 한다.

각 비트별로 count를 수행하는데 O(N)의 시간 복잡도가 소요된다.

이후 비트를 순회하는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

비트를 count하는데 O(1)의 공간 복잡도가 필요하다.

### 비트 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      30      |    O(N)     |    O(1)     |

모든 수마다 이진수로 나타냈을 때 포함되는 비트들을 count한다.

이 비트의 수가 해당 비트를 포함하는 숫자들을 AND 연산 했을 때 0이 아닌 경우에 포함되는 수의 갯수이다.

이후 각 비트의 수가 가장 많은 비트를 찾는다.

```cpp
int largestCombination(vector<int>& candidates) {
  int bits[32] = {
      0,
  };

  for (int& num : candidates) {
    for (int i = 0; i < 32; i++) {
      if (num & (1 << i)) {
        bits[i]++;
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < 32; i++) {
    answer = max(answer, bits[i]);
  }
  return answer;
}
```

## 고생한 점
