# 3736. Minimum Moves to Equal Array Elements III

[링크](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-iii/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

모든 값을 최대값만큼 증가시켜야한다.

배열의 최대값을 찾는데 O(N)의 시간 복잡도를 사용한다.

이후 각 값마다 차이를 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

최대값을 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 최대값

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

최대값을 찾고 다른 값들과 해당 최대값의 차이를 더한다.

```cpp
int minMoves(vector<int>& nums) {
  int maximum = *max_element(nums.begin(), nums.end());

  int answer = 0;

  for (int& num : nums) {
    answer += maximum - num;
  }
  return answer;
}
```

혹은 위 수식을 변화시켜 다음과 같이 일반화한다.

- 해당 값을 모든 i에 대해 더한다 : `maximum - nums[i]`
- 위 식을 수정하면 : `maximum * N - sum(nums)`

```cpp
int minMoves(vector<int>& nums) {
  int size = nums.size();
  int maximum = 0;
  int sum = 0;
  for (int& num : nums) {
    sum += num;
    maximum = max(maximum, num);
  }

  int answer = size * maximum - sum;

  return answer;
}
```

## 고생한 점
