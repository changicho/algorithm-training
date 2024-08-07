# 2134. Minimum Swaps to Group All 1's Together II

[링크](https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

슬라이딩 윈도우를 이용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

슬라이딩 윈도우에 index를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      55      |    O(N)     |    O(1)     |

nums에 존재하는 1의 갯수를 ones라 하자.

결과적으로 연속된 1의 갯수가 ones가 아닌경우 ones - (연속된 1의 갯수) 만큼의 1을 이동시켜야 한다.

슬라이딩 윈도우를 사용해 ones 크기의 윈도우에서 1의 갯수를 세고, 이를 이동시키며 최소값을 갱신한다.

이 때 원형 배열 임에 유의한다.

```cpp
int minSwaps(vector<int>& nums) {
  int ones = accumulate(nums.begin(), nums.end(), 0);

  int size = nums.size();

  int curOne = 0;
  for (int i = 0; i < ones; i++) {
    curOne += nums[i];
  }

  int answer = INT_MAX;
  for (int left = 0; left < size; left++) {
    int right = (left + ones) % size;

    answer = min(answer, ones - curOne);
    curOne -= nums[left];
    curOne += nums[right];
  }

  return answer;
}
```

## 고생한 점
