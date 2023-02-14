# 1523. Count Odd Numbers in an Interval Range

[링크](https://leetcode.com/problems/count-odd-numbers-in-an-interval-range/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 두 수의 범위를 N이라 하자.

이를 모두 순회하며 구할 경우 O(N)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

수의 차이를 구해 홀수의 갯수를 셀 경우 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

수의 차이를 이용할 경우 O(1)의 시간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

범위에 있는 가장 작은 짝수부터 high까지의 갯수를 구한다.

이 중 절반의 갯수가 홀수이므로 이를 이용한다.

이 때 low가 홀수인 경우 1을 더한다.

```cpp
int countOdds(int low, int high) {
  int answer = 0;
  if (low % 2 == 1) {
    answer += 1;
    low++;
  }

  int diff = high - low + 1;
  answer += diff / 2;

  return answer;
}
```

## 고생한 점
