# 3848. Check Digitorial Permutation

[링크](https://leetcode.com/problems/check-digitorial-permutation/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

N의 각 자리 수마다의 갯수를 구하며 팩토리얼 또한 구할 수 있다.

이 경우 O(log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 자리수별 갯수와 합을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(log_10(N)) |    O(1)     |

N을 구성하는 숫자들의 갯수를 구한다.

이 과정에서 각 숫자들의 팩토리얼 합을 구하고, 해당 합을 구성하는 숫자들의 갯수를 구한다.

N과 팩토리얼 합을 구성하는 숫자들의 수가 동일한지 확인한다.

```cpp
bool isDigitorialPermutation(int n) {
  int facto[10] = {
      0,
  };
  facto[0] = 1;
  for (int i = 1; i <= 9; i++) {
    facto[i] = facto[i - 1] * i;
  }

  int count[10] = {
      0,
  };

  int sum = 0;
  while (n > 0) {
    count[n % 10]++;

    sum += facto[n % 10];

    n /= 10;
  }

  while (sum > 0) {
    count[sum % 10]--;
    sum /= 10;
  }

  for (int i = 0; i < 10; i++) {
    if (count[i] != 0) return false;
  }

  return true;
}
```

## 고생한 점
