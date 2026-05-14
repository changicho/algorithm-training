# 2553. Separate the Digits in an Array

[링크](https://leetcode.com/problems/separate-the-digits-in-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 수는 최대 10^5 이며 이를 자리별로 순회하는데 O(1)의 시간 복잡도를 사용한다.

따라서 총 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

변환에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

각 수를 순회하며 자리수별로 배열에 집어넣는다.

이 때 첫번째 자리수가 나온 이후 0은 포함되어야 하므로 추가한다.

```cpp
vector<int> separateDigits(vector<int>& nums) {
  vector<int> answer;

  for (int& num : nums) {
    bool hasFind = false;
    for (int digit = 1e5; digit >= 1; digit /= 10) {
      if (!hasFind && digit > num) continue;
      hasFind = true;

      answer.push_back(num / digit);
      num %= digit;
    }
  }

  return answer;
}
```

## 고생한 점
