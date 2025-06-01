# 2894. Divisible and Non-divisible Sums Difference

[링크](https://leetcode.com/problems/divisible-and-non-divisible-sums-difference/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

순회를 이용할 경우 O(N)의 시간 복잡도를 갖는다.

수학을 사용할 경우 (등차수열) O(1)의 시간 복잡도를 갖는다.

### 공간 복잡도

합들을 저장하는데 O(1)의 공간 복잡도를 갖는다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

1 ~ n 까지의 합을 등차수열의 합공식으로 구할 수 있다.

또한 num2를 등차수열로 구할 수 있으며, 이를 이용해 num1을 구할 수 있다.

```cpp
int differenceOfSums(int n, int m) {
  int sum = (n + 1) * n / 2;

  int count = n / m;
  int limit = (n / m) * m;

  int num2 = count * (2 * m + (count - 1) * m) / 2;
  int num1 = sum - num2;

  return num1 - num2;
}
```

## 고생한 점
