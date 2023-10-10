# 2009. Minimum Number of Operations to Make Array Continuous

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N <= 10^5)

배열 내에 원소들의 최대값과 최소값의 범위를 제한해야 하므로 값의 대소를 빠르게 판단하기 위해 정렬을 수행한다.

이에 O(N * log_2(N))의 시간 복잡도를 사용한다.

이후 슬라이딩 윈도우를 사용해 각 과정마다의 값을 변경하는 최소횟수를 구한다. 이에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

슬라이딩 윈도우에 O(N)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|     289      | O(N * log_2(N)) |    O(N)     |

값을 우선 정렬한다.

이후 슬라이딩 윈도우를 사용해 최소값(왼쪽)과 최대값(오른쪽)의 차이가 N-1 이하인 경우가 되도록 큐의 원소를 제거한다.

이 과정에서 큐에 존재하지 않는 값들은 수정되어야 하는 값들이다.

이 때 큐에 들어있는 원소들 중에 중복된 값이 존재할 수 있으며 이 값들 또한 변경해야 한다.

중복된 값의 체크를 위해 슬라이딩 윈도우에 존재하는 원소의 수를 count하며 관리한다.

이후 전체 숫자의 갯수 - 큐 안의 원소의 수 + 큐 안의 중복된 원소의 수 를 구해 정답을 갱신한다.

```cpp
int minOperations(vector<int>& nums) {
  int size = nums.size();
  sort(nums.begin(), nums.end());

  int target = size - 1;
  int answer = size;

  queue<int> q;
  unordered_map<int, int> counts;
  int duplicated = 0;
  for (int& num : nums) {
    while (!q.empty() && num - q.front() > target) {
      int key = q.front();
      if (counts[key] > 1) duplicated--;
      counts[key]--;
      if (counts[key] == 0) counts.erase(key);
      q.pop();
    }

    q.push(num);
    if (counts[num] > 0) duplicated++;
    counts[num]++;

    int curCost = size - q.size() + duplicated;

    answer = min(curCost, answer);
  }
  return answer;
}
```

## 고생한 점
