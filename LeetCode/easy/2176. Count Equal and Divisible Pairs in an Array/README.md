# 2176. Count Equal and Divisible Pairs in an Array

[링크](https://leetcode.com/problems/count-equal-and-divisible-pairs-in-an-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 가진다.

### 공간 복잡도

완전 탐색에 O(1)의 공간 복잡도를 가진다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |   O(N^2)    |    O(1)     |

조건을 만족하는 쌍을 모두 탐색한다.

```cpp
int countPairs(vector<int>& nums, int k) {
  int size = nums.size();
  int answer = 0;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      if (nums[i] == nums[j] && (i * j) % k == 0) {
        answer++;
      }
    }
  }
  return answer;
}
```

## 고생한 점
