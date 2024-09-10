# 3282. Reach End of Array With Max Score

[링크](https://leetcode.com/problems/reach-end-of-array-with-max-score/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N <= 10^5)

모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이므로 제한시간 내에 불가능하다.

동적 계획법을 사용할 경우 O(N^2)의 시간 복잡도를 사용한다. 이 또한 제한시간 내에 불가능하다.

그리디 알고리즘을 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

그리디 알고리즘에 O(1)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     183      |    O(N)     |    O(1)     |

이전 위치를 i, 현재 위치를 j라 했을 때 i에서 j로 점프할 때 얻을 수 있는 점수는 다음과 같다.

- (j - i) * nums[i]

이는 반대로 이야기 하면 nums[i]값이 i부터 j까지 더해지는 것을 의미한다.

따라서 이전까지 최대값을 매 index마다 더하는 경우 최대값을 만들 수 있다.

직전까지 최대값보다 현재값이 큰 경우 최대값을 갱신한다.

```cpp
long long findMaximumScore(vector<int>& nums) {
  long long answer = 0;

  int maximum = 0;
  for (int& num : nums) {
    answer += maximum;
    maximum = max(num, maximum);
  }
  return answer;
}
```

## 고생한 점
