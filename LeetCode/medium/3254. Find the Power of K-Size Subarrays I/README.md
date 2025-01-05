# 3254. Find the Power of K-Size Subarrays I

[링크](https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N \* K)의 시간 복잡도가 필요하다. 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우에 O(K)의 공간 복잡도가 필요하다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(K)     |

크기가 k인 윈도우의 모든 원소는 1씩 증가하는 오름차순 이여야 한다.

따라서 윈도우에 원소를 집어 넣을 때 원소의 마지막 값과 현재 값을 비교해 윈도우가 유효한지 판단한다.

유효하지 않은 경우 윈도우를 비우고 다시 시작한다.

```cpp
vector<int> resultsArray(vector<int>& nums, int k) {
  int size = nums.size();
  deque<int> dq;

  vector<int> answer;

  for (int i = 0; i < size; i++) {
    if (dq.size() >= k) {
      dq.pop_front();
    }

    if (!dq.empty() && dq.back() + 1 != nums[i]) {
      dq.clear();
    }
    dq.push_back(nums[i]);

    if (i >= k - 1) {
      if (dq.size() == k) {
        answer.push_back(dq.back());
      } else {
        answer.push_back(-1);
      }
    }
  }
  return answer;
}
```

## 고생한 점
