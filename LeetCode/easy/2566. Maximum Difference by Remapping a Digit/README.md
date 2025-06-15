# 2566. Maximum Difference by Remapping a Digit

[링크](https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

탐욕 알고리즘을 사용해 최대값과 최소값을 구한다.

이 경우 각 자리수별로 순회하는데 O(log_10(N))의 시간복잡도를 가진다.

### 공간 복잡도

문자열로 변환하는데 O(log_10(N))의 공간복잡도를 가진다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도  |
| :----------: | :----------: | :----------: |
|      0       | O(log_10(N)) | O(log_10(N)) |

하나의 숫자를 다른 숫자로 변경해 최대값과 최소값을 만들기 위해 다음 전략을 사용한다.

- 최소값을 만들기 위해 가장 앞에 있는 숫자를 모두 0으로 변경한다.
- 최대값을 만들기 위해 가장 앞에 있는 9가 아닌 숫자를 모두 9로 변경한다.

```cpp
int minMaxDifference(int num) {
  string s = to_string(num);

  int size = s.size();

  string maximum = s, minimum = s;
  char maxTarget = '9', minTarget = s[0];

  int pos = maximum.find_first_not_of('9');
  if (pos != -1) {
    maxTarget = maximum[pos];
  }
  // for (char &c : maximum) {
  //   if (c == '9') continue;
  //   maxTarget = c;
  //   break;
  // }

  for (int i = 0; i < size; i++) {
    if (maximum[i] == maxTarget) maximum[i] = '9';
    if (minimum[i] == minTarget) minimum[i] = '0';
  }

  return stoi(maximum) - stoi(minimum);
}
```

## 고생한 점
