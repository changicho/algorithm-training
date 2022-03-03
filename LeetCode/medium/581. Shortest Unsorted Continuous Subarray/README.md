# 581. Shortest Unsorted Continuous Subarray

[링크](https://leetcode.com/problems/shortest-unsorted-continuous-subarray/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 원소의 갯수를 N이라 하자.

배열을 복사하고 정렬 후에 원본 배열과 비교해 정렬해야 하는 범위를 찾을 수 있다. 이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

모노토닉 스택을 이용해 한번의 순회를 하며 정렬해야 하는 범위를 찾을 수 있다. 이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

위 방법과 동일하게 한번 순회하며 풀이할 수도 있다.

### 공간 복잡도

배열을 복사하는 경우, 모노토닉 스택을 이용하는 경우 O(N)의 공간 복잡도를 사용한다.

순회만을 이용하는 경우 O(1)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      62      | O(N \* log_2(N)) |    O(N)     |

원본 배열을 복사한뒤 해당 배열을 정렬한다.

이후 index를 증가시키며 원본 배열과 다른 범위를 찾는다.

해당 범위의 원소의 갯수가 정렬해야 하는 배열의 크기이다.

```cpp
int findUnsortedSubarray(vector<int>& nums) {
  int size = nums.size();
  vector<int> sorted = nums;

  sort(sorted.begin(), sorted.end());

  int left = -1, right = -1;
  for (int i = 0; i < size; i++) {
    if (nums[i] != sorted[i] && left == -1) {
      left = i;
    }
    if (nums[i] != sorted[i]) {
      right = i;
    }
  }

  if (left == -1 && right == -1) return 0;
  return right - left + 1;
}
```

### 모노토닉 스택

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      36      |    O(N)     |    O(N)     |

위 문제에서 정렬해야 하는 범위에 대해서 생각해보자.

시작점과 끝점의 경우 원래 있어야 하는 원소는 정렬해야 하는 범위중 최소값, 최대값이다.

따라서 다음과 같은 스택을 생성하고 단조롭게 유지한다.

- maxStack(값이 증가하는 스택) : 정방향 탐색하며 원소를 증가하는 순서대로 저장
- minStack(값이 감소하는 스택) : 역방향 탐색하며 원소를 감소하는 순서대로 저장

해당 스택에는 정렬 순서가 어긋나는 경우 값을 저장하기 전에 정렬 순서를 망가뜨리는 원소를 pop하고 저장한다.

이후 원본 배열과 스택의 원소들을 순서대로 비교하며 값이 달라지는 위치를 찾아 정렬해야 하는 범위를 탐색한다.

```cpp
int findUnsortedSubarray(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;

  vector<int> maxStack, minStack;

  int left = -1, right = -1;
  for (int i = 0; i < size; i++) {
    int reversed = size - 1 - i;

    while (!maxStack.empty() && nums[maxStack.back()] > nums[i]) {
      maxStack.pop_back();
    }
    while (!minStack.empty() && nums[minStack.back()] < nums[reversed]) {
      minStack.pop_back();
    }

    maxStack.push_back(i);
    minStack.push_back(reversed);
  }

  for (int i = 0; i < size; i++) {
    int reversed = size - 1 - i;

    if (left == -1 && i != maxStack[i]) left = i;
    if (right == -1 && reversed != minStack[i]) right = reversed;

    if (left != -1 && right != -1) break;
  }

  if (left == -1 && right == -1) return 0;
  return right - left + 1;
}
```

혹은 스택의 원소를 pop할때 정답의 범위를 갱신한다.

```cpp
int findUnsortedSubarray(vector<int>& nums) {
  int size = nums.size();

  stack<int> maxStack, minStack;

  int left = size, right = 0;
  for (int i = 0; i < size; i++) {
    int reversed = size - 1 - i;

    while (!maxStack.empty() && nums[maxStack.top()] > nums[i]) {
      left = min(left, maxStack.top());
      maxStack.pop();
    }
    while (!minStack.empty() && nums[minStack.top()] < nums[reversed]) {
      right = max(right, minStack.top());
      minStack.pop();
    }

    maxStack.push(i);
    minStack.push(reversed);
  }

  return right - left > 0 ? right - left + 1 : 0;
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      38      |    O(N)     |    O(1)     |

정렬해야 하는 범위의 시작점은 범위의 최소값, 끝점은 범위의 최대값임을 이용한다.

시작점은 마지막 index부터 역순으로 순회하며 minimum값을 갱신한다. 이후 현재 값이 minimum보다 큰 경우 해당 값은 minimum이 위치해야 하므로 left를 갱신한다.

만약 제대로 정렬되어 있을 경우 minimum값은 순회하며 매번 갱신되기 때문에 현재 값이 minimum 이하인 경우만 가능하다.

끝점을 탐색할 때도 동일한 방법을 이용한다. (maximum, 정방향 순회)

```cpp
int findUnsortedSubarray(vector<int>& nums) {
  int size = nums.size();
  int left = -1, right = -1;

  int minimum = INT_MAX, maximum = INT_MIN;
  for (int i = 0; i < size; i++) {
    int reversed = size - 1 - i;

    maximum = max(maximum, nums[i]);
    minimum = min(minimum, nums[reversed]);

    if (nums[i] < maximum) right = i;
    if (nums[reversed] > minimum) left = reversed;
  }

  if (left == -1 && right == -1) return 0;
  return right - left + 1;
}
```

## 고생한 점
