# 2283. Check if Number Has Equal Digit Count and Digit Value

[링크](https://leetcode.com/problems/check-if-number-has-equal-digit-count-and-digit-value/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

문자열의 길이는 최대 10이며 각 문자를 순회하며 count를 수행한다.

이에 들어가는 시간 복잡도는 O(1)이다. 이후 각 count를 다시 숫자 문자열로 변환 후 정답과 비교한다.

총 시간 복잡도는 O(1)이다.

### 공간 복잡도

count를 수행하는 데 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

num을 순회하며 count를 수행한 뒤, 이를 다시 문자열로 변경 후 원본 문자열과 비교한다.

이 때 원본 문자열의 길이를 같이 맞춰준다. (변경 시 뒷자리가 추가되기 때문)

이를 구현하면 다음과 같다.

```cpp
bool digitCount(string num) {
  vector<int> counts(10);
  for (char &n : num) {
    counts[n - '0']++;
  }

  string converted = "";
  for (int i = 0; i < 10; i++) {
    converted += to_string(counts[i]);
  }

  while (num.length() < 10) {
    num += '0';
  }

  return converted == num;
}
```

## 고생한 점
