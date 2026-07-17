# 3658. GCD of Odd and Even Sums

[링크](https://leetcode.com/problems/gcd-of-odd-and-even-sums/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

1부터 홀수, 짝수를 더해가며 구할 경우 O(N)의 시간 복잡도를 사용하며 등차수열의 합공식을 사용할 경우 O(1)의 시간 복잡도로 합을 구한다.

이후 gcd연산에 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

연산에 O(1)의 공간 복잡도를 사용한다.

### 수학 (등차수열)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(N)) |    O(1)     |

등차수열의 합공식을 사용해 짝수부, 홀수부의 합을 구한 뒤 gcd를 구한다.

```cpp
int gcdOfOddEvenSums(int n) {
  int odd = n * (2 + (n - 1) * 2) / 2;
  int even = n * (4 + (n - 1) * 2) / 2;

  return gcd(odd, even);
}
```

## 고생한 점
