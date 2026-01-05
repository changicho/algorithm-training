# 1390. Four Divisors

[링크](https://leetcode.com/problems/four-divisors/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 각 원소의 최대값을 M이라 하자.

각 숫자마다 약수의 갯수를 구하는데 O(sqrt(M))의 시간 복잡도를 사용한다.

따라서 전체 시간 복잡도는 O(N \* sqrt(M))이다.

### 공간 복잡도

각 숫자마다 약수의 갯수를 구할 때 상수 공간을 사용하므로, 전체 공간 복잡도는 O(1)이다.

### 완전 탐색

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      57      | O(N \* sqrt(M)) |    O(1)     |

각 숫자에 대해 약수의 수를 세며, 약수의 수가 4개인 경우 약수의 합을 반환한다.

해당 합들을 더한다.

```cpp
int hasFour(int& num) {
  int count = 0;
  int sum = 0;

  for (int i = 1; i <= sqrt(num); i++) {
    if (num % i == 0) {
      count += 2;
      sum += i;
      sum += num / i;

      if (num / i == i) {
        count--;
        sum -= num / i;
      }
    }
  }

  return count == 4 ? sum : 0;
}

int sumFourDivisors(vector<int>& nums) {
  int sum = 0;

  for (int& num : nums) {
    sum += hasFour(num);
  }
  return sum;
}
```

## 고생한 점
