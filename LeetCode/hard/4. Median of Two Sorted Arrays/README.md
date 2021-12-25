# 4. Median of Two Sorted Arrays

[링크](https://leetcode.com/problems/median-of-two-sorted-arrays/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

두 배열을 합친 후 정렬할 경우 O((N + M) \* log_2(N + M))의 시간 복잡도로 풀이가 가능하다.

데크(투 포인터)를 이용해서 median을 구할 경우 O(N + M)의 시간 복잡도로 풀이가 가능하다.

이분 탐색을 이용할 경우 O(log_2(N + M))의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

별도의 공간을 사용할 경우 O(N + M)의 공간 복잡도로 풀이가 가능하다.

그 외에 이분 탐색, 투 포인터의 경우 O(1)의 공간 복잡도로 풀이가 가능하다.

### 데크

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      40      |  O(N + M)   |  O(N + M)   |

(투 포인터를 이용할 경우 동일한 시간복잡도에 O(1)의 공간 복잡도로 구현 가능)

nums1, nums2는 정렬되어 있으므로 중앙값을 찾기 위해 1개 혹은 2개의 원소만 남기고 작은 숫자, 큰 숫자를 pop하고 남은 숫자로 중앙값을 구한다.

- 원소의 개수가 홀수 : size / 2 번 뽑는다
- 원소의 개수가 짝수 : (size / 2) - 1 번 뽑는다.

각 경우마다 작은수, 큰수를 뽑을 때 두 deque의 맨앞, 맨 뒤를 비교해 하나의 원소를 뺀다.

이를 반복하면 중앙값을 찾을 수 있다.

```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  int size1 = nums1.size(), size2 = nums2.size(),
      size = nums1.size() + nums2.size();

  deque<int> dq1, dq2;

  for (int& num : nums1) {
    dq1.push_back(num);
  }
  for (int& num : nums2) {
    dq2.push_back(num);
  }

  for (int i = 0; i < (size + 1) / 2 - 1; i++) {
    if (dq1.empty()) {
      dq2.pop_front();
      continue;
    }
    if (dq2.empty()) {
      dq1.pop_front();
      continue;
    }

    if (dq1.front() < dq2.front()) {
      dq1.pop_front();
    } else {
      dq2.pop_front();
    }
  }

  for (int i = 0; i < (size + 1) / 2 - 1; i++) {
    if (dq1.empty()) {
      dq2.pop_back();
      continue;
    }
    if (dq2.empty()) {
      dq1.pop_back();
      continue;
    }

    if (dq1.back() > dq2.back()) {
      dq1.pop_back();
    } else {
      dq2.pop_back();
    }
  }

  vector<int> ret;
  while (!dq1.empty()) {
    ret.push_back(dq1.front());
    dq1.pop_front();
  }
  while (!dq2.empty()) {
    ret.push_back(dq2.front());
    dq2.pop_front();
  }

  if (ret.size() == 1) return (double)ret.front();
  return (double)(ret.front() + ret.back()) / 2;
}
```

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도   | 공간 복잡도 |
| :----------: | :-------------: | :---------: |
|      32      | O(log_2(N + M)) |    O(1)     |

위 문제에서 median은 어느 범위에 위치할지를 생각해 볼 수 있다.

두 배열은 모두 정렬되어 있으므로 다음과 같이 분할할 수 있다.

|        left_part        |          right_part           |
| :---------------------: | :---------------------------: |
| A[0], A[1], ..., A[i-1] | A[i], A[i+1], ..., A[sizeA-1] |
| B[0], B[1], ..., B[j-1] | B[j], B[j+1], ..., B[sizeB-1] |

여기서 A[i] ~ B[j-1]까지 원소의 개수를 전체 원소의 크기의 절반이다. (원소의 개수가 홀수인 경우는 절반 + 1개)

또한 해당 범위 내에 median이 있는것이 보장된다.

|     left      |        range (has median)        |      right       |
| :-----------: | :------------------------------: | :--------------: |
| A[0] ~ A[i-1] | A[i] ~ A[sizeA-1], B[0] ~ B[j-1] | B[j]~ B[sizeB-1] |

따라서 해당 범위애 대해서 이분 탐색을 진행해 답을 구할 수 있다.

따라서 배열을 다음과 같이 분할해 생각한다.

이 때 탐색시에 다음과 같은 3가지 경우가 생긴다.

- left에 range에 속한 B[j]보다 큰값이 있음.
- right에 range에 속한 A[i]보다 큰값이 있음.
- A[i] <= B[j-1] && B[j-1] <= A[i]

중앙값이 될 수 있는 후보는 A[i], B[j-1] 두 숫자이다.

이 때 range의 개수는 절반임이 보장되므로 B[j-1]과 A[i]에 대해서 left, right의 중앙값이 될 수 있는 후보에 비교하면 된다.

3번째 경우에 도달한 경우 중앙값을 찾은 경우이므로 이때 각 경우마다 중앙값을 구해준다.

- i, j가 임계값에 도달한 경우 (0 혹은 size)
- i, j가 임계값이 아닌 경우

이 때 원소의 개수가 홀수인 경우와 짝수인 경우에 대해 분기 처리한다.

이를 이용해 구현하면 다음과 같다.

```cpp
double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.empty() && nums2.empty()) return 0;
  if (nums1.size() > nums2.size()) swap(nums1, nums2);
  // nums1.size() < nums2.size()
  int size1 = nums1.size(), size2 = nums2.size(),
      half = (size1 + size2 + 1) / 2;

  // binary search of range of nums1
  int left = 0, right = size1;
  while (left <= right) {
    int from = (left + right) / 2;
    int to = half - from;

    if (from > 0 && nums1[from - 1] > nums2[to]) {
      // move range to left
      right = from - 1;
    } else if (from < size1 && nums2[to - 1] > nums1[from]) {
      // move range to right
      left = from + 1;
    } else {
      // find leftMax, rightMin
      int leftMax, rightMin;
      if (from == 0) {
        leftMax = nums2[to - 1];
      } else if (to == 0) {
        leftMax = nums1[from - 1];
      } else {
        leftMax = max(nums1[from - 1], nums2[to - 1]);
      }

      if ((size1 + size2) % 2 == 1) return leftMax;

      if (from == size1) {
        rightMin = nums2[to];
      } else if (to == size2) {
        rightMin = nums1[from];
      } else {
        rightMin = min(nums1[from], nums2[to]);
      }

      return (double)(leftMax + rightMin) / 2;
    }
  }

  return 0.0;
}
```

## 고생한 점
