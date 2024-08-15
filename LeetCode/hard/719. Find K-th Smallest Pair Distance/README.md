# 719. Find K-th Smallest Pair Distance

[링크](https://leetcode.com/problems/find-k-th-smallest-pair-distance/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 nums의 크기를 N, 최대값을 M이라 하자.

nums를 정렬한 뒤 슬라이딩 윈도우를 사용하면 특정 값 보다 작은 pair distance의 갯수를 찾을 수 있다.

이를 위해 O(N \* log_2(N))의 시간 복잡도가 필요하다.

이후 특정 값에 대해 이분 탐색을 수행할 경우 O(N \* log_2(M))의 시간 복잡도가 필요하다.

따라서 총 시간 복잡도는 O(N \* log_2(N) + N \* log_2(M)) 이며 로그의 성질에 의해 O(N \* log_2(N \* M))이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색 & 슬라이딩 윈도우

| 내 코드 (ms) |      시간 복잡도      | 공간 복잡도 |
| :----------: | :-------------------: | :---------: |
|      11      | O(N \* log_2(N \* M)) |    O(N)     |

정렬된 배열에 대해서 특정 값 이하의 pair distance의 갯수를 슬라이딩 윈도우를 이용해 구할 수 있다.

left, right를 이용해 현재 윈도우의 차이가 특정 값 이하인 pair의 갯수를 구할 수 있다.

distance에 대해 이분 탐색을 수행하며 K번째 distance를 찾는다.

```cpp
int countPairsWithMaxDistance(vector<int>& nums, int maxDistance) {
  int size = nums.size();
  int count = 0;

  for (int left = 0, right = 0; right < size; right++) {
    while (nums[right] - nums[left] > maxDistance) {
      left++;
    }

    count += right - left;
  }
  return count;
}

int smallestDistancePair(vector<int>& nums, int k) {
  sort(nums.begin(), nums.end());
  int size = nums.size();

  int left = 0, right = nums.back() - nums.front() + 1;

  int answer = 0;
  while (left < right) {
    int mid = left + (right - left) / 2;

    int count = countPairsWithMaxDistance(nums, mid);

    if (count < k) {
      left = mid + 1;
    } else {
      answer = mid;
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
