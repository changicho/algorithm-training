# 1526. Minimum Number of Increments on Subarrays to Form a Target Array

[링크](https://leetcode.com/problems/minimum-number-of-increments-on-subarrays-to-form-a-target-array/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 target의 길이를 N이라 하자.

왼쪽부터 순회하며 상승하는 만큼 정답을 증가시킬 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

직전 값을 저장해야 하므로 O(1)의 공간 복잡도가 필요하다.

### one pass with diff

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      95      |    O(N)     |    O(1)     |

왼쪽 부터 순회하며 직전값과 비교해 현재 값이 더 큰 경우 차이만큼 정답에 더한다.

(현재 index부터 끝날 때 까지 range 높이를 증가시킴)

이후 현재값을 직전값으로 갱신한다.

만약 현재 값이 작은 경우에는 range 높이를 증가시킬 필요가 없으므로 해당 range의 끝은 현재 index가 된다.

```cpp
int minNumberOperations(vector<int>& target) {
  int answer = 0;
  int before = 0;

  for (int& num : target) {
    if (before < num) {
      answer += (num - before);
    }
    before = num;
  }

  return answer;
}
```

## 고생한 점
