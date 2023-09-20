# 1658. Minimum Operations to Reduce X to Zero

[링크](https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자. (N <= 10^5)

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

prefix sum을 이용해 가능한 합을 미리 구해놓는다. 이후 suffix sum을 갱신하며 특정 수의 합이 x가 되는 경우를 찾는다.

이 경우 O(N)의 시간 복잡도를 사용한다.

혹은 슬라이딩 윈도우를 이용할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도를 사용한다.

슬라이딩 윈도우를 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     331      |    O(N)     |    O(N)     |

suffix sum을 구해놓으며 각 값마다 해당 sum을 구성하기 위한 갯수를 저장해놓는다.

이후 prefix sum을 구하면서 suffixSum + prefixSum = x 가 되는 경우를 찾고 최소 갯수를 갱신한다.

```cpp
int minOperations(vector<int>& nums, int x) {
  int size = nums.size();

  int answer = INT_MAX;

  unordered_map<int, int> rights;
  rights[0] = 0;
  for (int i = size - 1, temp = 0; i >= 0; i--) {
    temp += nums[i];
    rights[temp] = size - i;
  }

  if (rights.count(x) > 0) {
    answer = min(answer, rights[x]);
  }
  for (int i = 0, temp = 0; i < size; i++) {
    temp += nums[i];
    int target = x - temp;

    if (rights.count(target) > 0 && rights[target] + i + 1 <= size) {
      answer = min(answer, i + 1 + rights[target]);
    }
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     138      |    O(N)     |    O(1)     |

문제를 변경해 x를 구하는 왼쪽, 오른쪽 prefix suffix를 구하는것이 아닌 sum-x 를 구하는 subArray를 구하는 문제로 변경한다.

이후 슬라이딩 윈도우를 이용해 subArray를 구하고 그 길이를 이용해 정답을 갱신한다.

```cpp
int minOperations(vector<int>& nums, int x) {
  int size = nums.size();
  int sum = accumulate(nums.begin(), nums.end(), 0);

  int answer = INT_MAX;

  int target = sum - x;
  if (target == 0) {
    answer = size;
  }

  for (int right = 0, left = 0, temp = 0; right < size; right++) {
    temp += nums[right];

    while (temp > target && left < right) {
      temp -= nums[left];
      left++;
    }

    if (temp == target) {
      answer = min(answer, (left) + (size - 1 - right));
    }
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
