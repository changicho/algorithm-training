# 2429. Minimize XOR

[링크](https://leetcode.com/problems/minimize-xor/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

num1, num2 중 최대값을 N이라 하자. (N <= 10^9)

그리디 알고리즘을 사용해 필요한 비트를 추가한다.

이에 O(log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

비트 연산에 O(1)의 공간 복잡도가 필요하다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

num2의 비트 수를 가지며 num1과 XOR 연산 했을 때 최소값이 되는 수를 구해야 한다.

이를 위해 사용 가능한 비트들 중 num1의 큰 비트부터 채워넣는다.

남는 비트는 가장 작은 비트부터 채워넣는다.

```cpp
int minimizeXor(int num1, int num2) {
  int count1 = __builtin_popcount(num1);
  int count2 = __builtin_popcount(num2);

  int diff = count2 - count1;

  int answer = 0;
  for (int i = 31; i >= 0; i--) {
    if (num1 & (1 << i) && count2 > 0) {
      answer |= (1 << i);
      count2--;
    }
  }
  for (int i = 0; i < 32 && diff > 0; i++) {
    if (answer & (1 << i)) continue;
    answer |= (1 << i);
    diff--;
  }

  return answer;
}
```

## 고생한 점
