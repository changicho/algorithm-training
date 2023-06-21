# 2090. K Radius Subarray Averages

[링크](https://leetcode.com/problems/k-radius-subarray-averages/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N, 반지름의 크기를 K라 하자. (N <= 10^5, K <= 10^5)

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* K) 이므로 제한시간 내에 불가능하다.

슬라이딩 윈도우를 이용해 O(N)의 시간 복잡도로 풀이할 수 있다.

### 공간 복잡도

정답으로 반환하는 배열에 O(N)의 공간 복잡도를 사용한다.

슬라이딩 윈도우에 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     261      |    O(N)     |    O(N)     |

k가 0인 경우는 nums 그대로 반환한다.

k가 0이 아닌 경우, k를 반지름으로 하는 윈도우를 만들고 윈도우 내부의 합을 구한뒤 평균을 구한다.

이후 윈도우를 한칸씩 이동시키며 합을 갱신시킨다.

이 때 윈도우의 크기는 2 \* k + 1이며, 윈도우위 범위가 nums의 index를 넘어갈 수 있음에 유의한다.

정답의 앞 뒤로 k개씩은 범위를 벗어나므로 -1로 채운다.

이후 나머지 정답을 채운다.

```cpp
vector<int> getAverages(vector<int>& nums, int k) {
  int size = nums.size();
  int windowSize = 2 * k + 1;

  if (k == 0) {
    return nums;
  }

  vector<int> answer(size, -1);
  if (windowSize > size) {
    return answer;
  }

  long long sum = 0;
  for (int i = 0; i < windowSize; ++i) {
    sum += nums[i];
  }
  answer[k] = sum / windowSize;

  for (int right = windowSize; right < size; ++right) {
    int left = right - windowSize;
    sum -= nums[left];
    sum += nums[right];

    answer[right - k] = sum / windowSize;
  }

  return answer;
}
```

## 고생한 점
