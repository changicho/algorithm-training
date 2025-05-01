# 1295. Find Numbers with Even Number of Digits

[링크](https://leetcode.com/problems/find-numbers-with-even-number-of-digits/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. 이 중 최대값을 M이라 한다.

각 숫자를 순회하며 자릿수를 세는 작업을 수행한다.

각 자리수를 셀 때 log_10(M)의 시간 복잡도를 사용하며 이를 단순하게 비교할 경우 이는 거의 O(1)이다.

이에 O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

O(1)의 공간 복잡도를 가진다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 숫자마다 10^6부터 자리수를 비교하며 1까지 10으로 나누어 가며 비교한다.

각 자리수 이상의 값인 경우 해당 자리수에 맞는 값을 반환한다.

```cpp
bool check(int num) {
  for (int d = 100000, c = 0; d >= 1; d /= 10, c++) {
    if (num >= d) {
      return c % 2 == 0;
    }
  }
  return false;
}

int findNumbers(vector<int>& nums) {
  int answer = 0;

  for (int& num : nums) {
    if (check(num)) {
      answer++;
    }
  }
  return answer;
}
```

## 고생한 점
