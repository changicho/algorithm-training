# 2841. Maximum Sum of Almost Unique Subarray

[링크](https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* K)이다. 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

이 때 숫자의 종류를 체크하기 위해 hash map을 사용할 경우 각 상황마다 O(1)의 시간 복잡도를 사용할 수 있다.

### 공간 복잡도

슬라이딩 윈도우를 사용할 경우 O(K)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     143      |    O(N)     |    O(K)     |

길이 K의 윈도우에 숫자의 종류를 저장하기 위해 hash map을 사용한다.

right가 증가할 때마다 숫자와 합을 증가시키고 left가 증가할 때마다 숫자와 합을 감소시킨다.

```cpp
long long maxSum(vector<int>& nums, int m, int k) {
  int size = nums.size();

  long long answer = 0;
  long long sum = 0;
  unordered_map<int, int> counts;
  for (int i = 0; i < k; i++) {
    int num = nums[i];
    sum += num;
    counts[num]++;
  }

  // update init
  if (counts.size() >= m) {
    answer = max(answer, sum);
  }

  for (int right = k; right < size; right++) {
    int left = right - k;

    counts[nums[left]]--;
    sum -= nums[left];
    if (counts[nums[left]] == 0) {
      counts.erase(nums[left]);
    }

    sum += nums[right];
    counts[nums[right]]++;

    if (counts.size() >= m) {
      answer = max(answer, sum);
    }
  }
  return answer;
}
```

## 고생한 점
