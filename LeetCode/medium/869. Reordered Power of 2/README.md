# 869. Reordered Power of 2

[링크](https://leetcode.com/problems/reordered-power-of-2/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

N을 구성하는 자리의 숫자들을 카운팅 하고, 이를 문제 조건에 맞는 숫자들의 카운팅과 비교한다.

이 경우 O(log_10(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

각 숫자를 카운팅하는데 O(1)의 공간 복잡도를 사용한다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|      0       | O(log_10(N)) |    O(1)     |

n을 구성하는 각 자리의 숫자를 카운팅한다.

이후 1부터 2^30까지의 모든 2의 거듭제곱에 대해 각 자리의 숫자를 카운팅하고, 이를 비교한다.

```cpp
bool reorderedPowerOf2(int n) {
  vector<int> count(10);
  while (n > 0) {
    count[n % 10]++;
    n /= 10;
  }

  for (int i = 0; i < 31; i++) {
    vector<int> curCount(10);
    int num = (1 << i);

    while (num > 0) {
      curCount[num % 10]++;
      num /= 10;
    }

    if (curCount == count) return true;
  }
  return false;
}
```

## 고생한 점
