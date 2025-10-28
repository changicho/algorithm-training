# 3354. Make Array Elements Equal to Zero

[링크](https://leetcode.com/problems/make-array-elements-equal-to-zero/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 배열 nums의 크기를 N이라 하자.

시뮬레이션을 수행할 경우 O(N^2 \* M)의 시간 복잡도를 사용한다.

prefix sum을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

시뮬레이션에 O(1)의 공간 복잡도를 사용한다.

prefix sum에 O(1)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

특정 시작점에서 문제 조건에 따라 모든 수를 0으로 만들기 위해선 조건이 다음과 같다.

현재 index 기준으로 왼쪽 부분의 합을 A, 오른쪽 부분의 합을 B라 하자.

- 왼쪽으로 출발했을 때 : A == B, A+1 == B
- 오른쪽으로 출발했을 때 : A == B, A == B+1

위 조건에 따라 prefix sum을 이용해 왼쪽 부분과 오른쪽 부분의 합을 갱신하며 정답을 증가시킨다.

```cpp
int countValidSelections(vector<int>& nums) {
  int size = nums.size();

  int leftSum = 0;
  int rightSum = accumulate(nums.begin(), nums.end(), 0);

  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (nums[i] != 0) {
      leftSum += nums[i];
      rightSum -= nums[i];
    } else {
      if (leftSum == rightSum) answer += 2;
      if (abs(leftSum - rightSum) == 1) answer++;
    }
  }
  return answer;
}
```

## 고생한 점
