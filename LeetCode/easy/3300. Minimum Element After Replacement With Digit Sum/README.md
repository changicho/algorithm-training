# 3300. Minimum Element After Replacement With Digit Sum

[링크](https://leetcode.com/problems/minimum-element-after-replacement-with-digit-sum/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N, 원소의 값을 M이라 하자.

각 숫자마다 변환 후 정답을 구할 경우 O(N \* log_10(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) |    시간 복잡도    | 공간 복잡도 |
| :----------: | :---------------: | :---------: |
|      0       | O(N \* log_10(M)) |    O(1)     |

각 값을 순회하며 변환 후 정답을 구한다.

```cpp
int minElement(vector<int>& nums) {
  int answer = INT_MAX;

  for (int& num : nums) {
    int cur = 0;
    while (num > 0) {
      cur += num % 10;
      num /= 10;
    }

    answer = min(answer, cur);
  }
  return answer;
}
```

## 고생한 점
