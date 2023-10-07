# 2366. Minimum Replacements to Sort the Array

[링크](https://leetcode.com/problems/minimum-replacements-to-sort-the-array/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

수를 쪼개며 감소시켜야 하며 이를 모든 경우를 탐색할 경우 제한시간 내에 불가능하다.

따라서 쪼개야 하는 구간에서 최소한의 수만 쪼개야 한다.

이 경우 역순으로 순회하며 판단할 수 있으므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

별도의 배열 등이 필요하지 않으므로 O(1)의 공간 복잡도를 사용한다.

### 그리디 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      87      |    O(N)     |    O(1)     |

현재 방문중인 index를 i라 하자.

i번째 수보다 i+1번째 수가 작은 경우 i번째 수를 쪼개야 한다.

이 때 너무 작은 수로 쪼갤 경우 i번째 이전 수들도 영향을 받으므로 쪼갤 수 있는 최대값으로 쪼개야 한다.

만약 i+1번째 이후 숫자들이 i+1번째보다 크다는 것이 보장될 경우 i+1번째 수 또한 쪼개 최대값으로 만들 수 있다.

쪼개는 횟수를 최소한으로 하며 가장 큰 수로 쪼개기 위해 다음과 같은 방법을 사용한다.

- 두 수의 합의 1을 뺀 값을 구한다.
- 합을 i+1번째 수로 나눈다.
- 나눈 값에 올림을 수행한다.

위 값이 쪼개는 횟수이며 내림차순을 생성하지 않기 위해 현재 수를 해당 횟수로 나눈 값으로 변경한다.

이를 i를 감소시키며 반복하며, 이전 i값은 위 연산이 끝난 뒤 가장 왼쪽에 있던 값이 된다.

```cpp
long long minimumReplacement(vector<int>& nums) {
  int size = nums.size();

  long long answer = 0;
  for (int i = size - 2; i >= 0; i--) {
    if (nums[i] <= nums[i + 1]) {
      continue;
    }

    long long replaceCount =
        ceil((nums[i] + nums[i + 1] - 1LL) / (nums[i + 1]));

    answer += replaceCount - 1;

    nums[i] = nums[i] / replaceCount;
  }

  return answer;
}
```

## 고생한 점
