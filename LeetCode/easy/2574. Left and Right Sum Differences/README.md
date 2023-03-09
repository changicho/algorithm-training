# 2574. Left and Right Sum Differences

[링크](https://leetcode.com/problems/left-and-right-sum-differences/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

각 경우마다 prefixSum을 구하고 답을 구할 수 있다.

이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefixSum을 직접 생성할 경우 O(N)의 공간 복잡도를 사용한다.

정답으로 반환하는 공간에 O(N)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(N)     |

왼쪽, 오른쪽부터 순회했을 때의 prefixSum을 구하고 이를 이용해 정답을 채운다.

```cpp
vector<int> leftRigthDifference(vector<int>& nums) {
  int size = nums.size();
  vector<int> leftSums(size), rightSums(size);

  for (int i = 1; i < size; i++) {
    leftSums[i] = leftSums[i - 1] + nums[i - 1];
  }
  for (int i = size - 2; i >= 0; i--) {
    rightSums[i] = rightSums[i + 1] + nums[i + 1];
  }

  vector<int> answer(size);
  for (int i = 0; i < size; i++) {
    answer[i] = abs(leftSums[i] - rightSums[i]);
  }
  return answer;
}
```

## 고생한 점
