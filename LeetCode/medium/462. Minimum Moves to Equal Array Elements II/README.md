# 462. Minimum Moves to Equal Array Elements II

[링크](https://leetcode.com/problems/minimum-moves-to-equal-array-elements-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

특정 숫자에 대해서 diff의 합은 2차원 그래프와 유사하다.

따라서 삼분 탐색을 이용해 정답을 구할 수 있다.

이 경우 시간 복잡도는 O(N \* log_3(N))이다.

중앙값을 찾고 이를 이용해 정답을 구할 수 있다.

이 경우 완전 정렬을 사용할 경우 O(N \* log_2(N))의 시간복잡도를 사용한다.

nth_element를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬, 삼분탐색을 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |    O(N)     |    O(1)     |

정렬 후 중앙값을 정답으로 고정하고, 이 값과의 차이의 절대값을 모두 더한다.

```cpp
int minMoves2(vector<int> &nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  int median = nums[size / 2];
  int answer = 0;
  for (int &n : nums) {
    answer += abs(n - median);
  }

  return answer;
}
```

### 삼분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      43      | O(N \* log_3(N)) |    O(1)     |

특정 값에 대해서 diff의 합은 정답에 멀어질수록 증가하는 2차원 그래프와 유사하게 된다.

따라서 삼분 탐색을 이용해 최소값을 구할 수 있다.

```cpp
long long getDiff(vector<int> &nums, int key) {
  long long diff = 0;
  for (int &n : nums) {
    diff += abs(key - n);
  }
  return diff;
}

int minMoves2(vector<int> &nums) {
  int size = nums.size();

  long long answer = getDiff(nums, nums.front());

  int rangeStart = -1e9, rangeEnd = +1e9;
  while (rangeStart + 3 <= rangeEnd) {
    int left = (2 * rangeStart + rangeEnd) / 3;
    int right = (rangeStart + 2 * rangeEnd) / 3;

    long long costL = getDiff(nums, left);
    long long costR = getDiff(nums, right);

    if (costL < costR) {
      // pick leftPart
      rangeEnd = right;
      answer = min(answer, costL);
    } else {
      // pick rightPart
      rangeStart = left;
      answer = min(answer, costR);
    }
  }

  return (int)answer;
}
```

## 고생한 점
