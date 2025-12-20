# 2110. Number of Smooth Descent Periods of a Stock

[링크](https://leetcode.com/problems/number-of-smooth-descent-periods-of-a-stock/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 prices의 크기를 N이라 하자.

배열을 순회하며 각 원소를 기준으로 내림차순 구간의 길이를 셀 경우 O(N)의 시간이 걸린다.

### 공간 복잡도

내림차순의 길이를 셀 때 상수 크기의 변수만 필요하므로 O(1)의 공간복잡도를 가진다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

각 내림차순 구간의 길이를 센다.

이후 해당 구간의 길이를 X라고 할 때 해당 구간에서 만들 수 있는 정답의 경우는 (X + 1) \* (X) / 2이다.

```cpp
long long getDescentPeriods(vector<int>& prices) {
  long long answer = 0;

  long long count = 0;
  int before = INT_MAX;
  for (int& p : prices) {
    if (before - 1 == p) {
      count++;
    } else {
      answer += (count + 1) * (count) / 2;
      count = 1;
    }
    before = p;
  }
  answer += (count + 1) * (count) / 2;
  return answer;
}
```

## 고생한 점
