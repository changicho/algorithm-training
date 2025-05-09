# 325. Maximum Size Subarray Sum Equals k

[링크](https://leetcode.com/problems/maximum-size-subarray-sum-equals-k/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

prefix sum을 이용할 경우 O(N)의 시간 복잡도로 문제를 해결할 수 있다.

### 공간 복잡도

prefix sum을 저장하기 위해 O(N)의 공간 복잡도가 필요하다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     164      |    O(N)     |    O(N)     |

prefix sum을 이용해 합이 K인 부분 배열의 최대 길이를 구할 수 있다.

왼쪽부터 순회하며 현재까지의 prefix sum의 left most index를 저장한다.

현재까지 sum과 K를 뺀 값이 left most index에 존재한다면, 그 index와 현재 index의 차이가 최대 길이가 된다.

```cpp
int maxSubArrayLen(vector<int>& nums, int k) {
  int size = nums.size();
  unordered_map<long long, int> leftMostIndexes;

  int answer = 0;
  long long sum = 0;
  leftMostIndexes[0] = -1;
  for (int i = 0; i < size; i++) {
    sum += nums[i];

    if (leftMostIndexes.count(sum - k)) {
      answer = max(answer, i - leftMostIndexes[sum - k]);
    }

    if (!leftMostIndexes.count(sum)) {
      leftMostIndexes[sum] = i;
    }
  }
  return answer;
}
```

## 고생한 점
