# 868. Binary Gap

[링크](https://leetcode.com/problems/binary-gap/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

각 비트별로 순회하며 거리를 갱신할 경우 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

순회 후 값을 갱신하는 데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

비트를 순회하며 1이 나올 때마다 이전에 나온 1과의 거리를 계산하여 최대값을 갱신한다.

```cpp
int binaryGap(int n) {
  int answer = 0;
  int count = 0;
  int before = 32;

  while (n > 0) {
    if (n % 2 == 1) {
      answer = max(answer, count - before);
      before = count;
    }

    n /= 2;
    count++;
  }
  return answer;
}
```

## 고생한 점
