# 683. K Empty Slots

[링크](https://leetcode.com/problems/k-empty-slots/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 bulbs의 크기를 N, 입력받은 수를 K라 하자.

각 시간마다 전구가 켜질 때 마다 위치의 차이가 K인 전구가 존재하는지 BST set을 이용해 판단할 경우 O(N \* log_2(N))의 시간 복잡도를 갖는다.

슬라이딩 윈도우를 사용할 경우 O(N)으로 시간 복잡도를 사용한다.

### 공간 복잡도

BST set을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

슬라이딩 윈도우를 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### BST set

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      48      | O(N \* log_2(N)) |    O(N)     |

현재 전구와 이전에 추가된 전구 사이에 K개의 빈 공간이 존재하는지 확인해야 한다.

이를 upper_bound와 lower_bound를 이용해 현재 추가된 값과 가장 가까운 큰값, 작은값을 구해 찾는다.

이후 각 일마다 전구를 bst set에 추가한다.

```cpp
int kEmptySlots(vector<int>& bulbs, int k) {
  int size = bulbs.size();

  set<int> s;

  for (int i = 0; i < size; i++) {
    int left = -1, right = -1;

    if (s.empty()) {
      s.insert(bulbs[i]);
      continue;
    }

    auto up = s.upper_bound(bulbs[i]);
    auto low = prev(up);

    if (up != s.end()) {
      right = *up - bulbs[i] - 1;
    }
    if (up != s.begin()) {
      left = bulbs[i] - *low - 1;
    }

    if (left == k || right == k) return i + 1;

    s.insert(bulbs[i]);
  }

  return -1;
}
```


### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      6       |    O(N)     |    O(N)     |

각 전구마다 추가되는 날짜를 저장한다.

이후 길이가 K인 윈도우를 왼쪽부터 이동시키며, 현재 윈도우 양 끝에 전구가 존재하며 사이가 빈 경우 정답을 갱신한다.

```cpp
int kEmptySlots(vector<int>& bulbs, int k) {
  int size = bulbs.size();

  vector<int> turnOns(size);

  for (int i = 0; i < size; i++) {
    turnOns[bulbs[i] - 1] = i + 1;
  }

  int left = 0, right = k + 1;
  int answer = INT_MAX;
  for (int day = 0; right < size && day < size; day++) {
    if (max(turnOns[left], turnOns[right]) < turnOns[day]) continue;

    if (day == right) {
      answer = min(answer, max(turnOns[left], turnOns[right]));
    }

    left = day, right = k + 1 + day;
  }

  return (answer == INT_MAX) ? -1 : answer;
}
```

## 고생한 점
