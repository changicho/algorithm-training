# 1800. Maximum Ascending Subarray Sum

[링크](https://leetcode.com/problems/maximum-ascending-subarray-sum/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 직접 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

한번의 순회를 이용해 탐색할 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

직전 값과 비교하므로 별도의 공간이 필요하지 않다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

배열을 순회하며 직전 값보다 커지는 경우 현재 합에 더한다.

그 외의 경우는 현재 합을 초기화시키고 현재 값을 시작점으로 설정한다.

```cpp
int maxAscendingSum(vector<int>& nums) {
  int size = nums.size();

  int answer = nums[0];
  int sum = nums[0];

  for (int i = 1; i < size; i++) {
    int num = nums[i];
    if (nums[i - 1] >= num) {
      sum = num;
    } else {
      sum += num;
    }

    answer = max(answer, sum);
  }

  return answer;
}
```

## 고생한 점
