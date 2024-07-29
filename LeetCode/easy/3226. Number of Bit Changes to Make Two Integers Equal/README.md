# 3226. Number of Bit Changes to Make Two Integers Equal

[링크](https://leetcode.com/problems/number-of-bit-changes-to-make-two-integers-equal/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 수를 N, K라 하자.

비트 연산을 이용해 정답을 구할 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

비트 연산을 사용할 경우 O(1)의 공간 복잡도가 필요하다.

### 비트 연산

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

각 비트 자리수별로 비교한 뒤 K의 해당 비트가 1이고 N의 해당 비트가 0인 경우는 정답을 생성할 수 없으므로 -1을 반환한다.

그 외의 경우는 차이만큼 더한다.

```cpp
int minChanges(int n, int k) {
  int answer = 0;
  for (int i = 0; i < 32; i++) {
    int bit = 1 << i;

    if ((n & bit) == (k & bit)) continue;

    if ((n & bit) > 0 && (k & bit) == 0)
      answer++;
    else
      return -1;
  }
  return answer;
}
```

## 고생한 점
