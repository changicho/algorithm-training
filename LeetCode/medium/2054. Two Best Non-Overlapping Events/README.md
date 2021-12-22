# 2054. Two Best Non-Overlapping Events

[링크](https://leetcode.com/problems/two-best-non-overlapping-events/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

event의 개수를 N이라 하자.

하나의 event를 고른 뒤에 다른 event를 골랐을 때 최대값이 되는 경우를 찾아야 한다.

이를 위해 매번 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다.

event의 시작시간에 따라 정렬을 수행해 이분 탐색으로 특정 위치의 index를 빨리 찾을 수 있다.

정렬에 O(N \* log_2(N))의 시간 복잡도가 소요된다.

이후 동적 계획법을 이용해 특정 index ~ size 까지의 이벤트 중 가장 가치있는 이벤트를 찾기위해 저장한다.

이 동적 계획법에 O(N)의 시간 복잡도를 사용한다.

이후 현재 event를 선택하고 끝나는 시간에 대해서 이분 탐색을 수행해 해당 이벤트의 위치를 잡는다.

이 방법을 이용할 경우 O(N \* log_2(N))의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색 + 동적 계획법

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     440      | O(N \* log_2(N)) |    O(N)     |

event들을 시작 시간에 따라 정렬한다.

이는 하나의 event를 선택했을 때 다른 이벤트를 선택하기 위해서 이분 탐색을 이용하면 빠르게 찾을 수 있기 때문이다.

(첫번째 끝나는 시간이 지나고 시작하는 이벤트들만 고를 수 있음)

이 때 가능한 후보군 중에서 가장 value가 높은 이벤트를 골라야한다.

이를 위해 다음과 같은 동적 계획법을 사용한다.

```cpp
// biggest[index] : biggest value of event after index (index ~ size-1)
vector<int> biggest(size, 0);

// initial value
biggest[size - 1] = events[size - 1][2];

// update
biggest[i] = max(biggest[i + 1], value);
```

따라서 이벤트를 순회하며, 해당 이벤트가 끝나는 시간이 지나고 시작하는 이벤트의 최초 위치를 찾은 뒤 해당 위치와 같은 biggest 값을 이용해 정답을 갱신한다.

이 때 하나의 event를 고르는 경우또한 답이 될 수 있다.

```cpp
int maxTwoEvents(vector<vector<int>> &events) {
  int size = events.size();

  sort(events.begin(), events.end(),
        [&](const vector<int> &a, const vector<int> &b) {
          return a[0] < b[0];
        });

  // biggest[index] : biggest value of event after index (index ~ size-1)
  vector<int> biggest(size, 0);
  biggest[size - 1] = events[size - 1][2];

  int answer = events[size - 1][2];
  for (int i = size - 2; i >= 0; i--) {
    int value = events[i][2];

    biggest[i] = max(biggest[i + 1], value);
    answer = max(answer, value);
  }

  for (int i = 0; i < size; i++) {
    // use binary search to find other maximum from i+1 ~ size
    int left = i + 1, right = size;
    bool isFind = false;

    while (left < right) {
      int mid = left + (right - left) / 2;

      // events[i].end < events[mid].start
      if (events[i][1] < events[mid][0]) {
        // pick left
        isFind = true;
        right = mid;
      } else {
        // pick right
        left = mid + 1;
      }
    }

    if (!isFind) continue;
    answer = max(events[i][2] + biggest[left], answer);
  }

  return answer;
}
```

## 고생한 점
