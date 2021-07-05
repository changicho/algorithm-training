# 729. My Calendar I

[링크](https://leetcode.com/problems/my-calendar-i/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 예약의 최대 개수를 N이라 하자.

예약을 추가하기 전에 모든 예약을 비교할 경우 이전 예약을 순회하는데 들어가는 시간 복잡도는 O(N)이다.

이를 모든 예약에 대해서 반복하므로 O(N^2)의 시간 복잡도가 소요된다.

혹은 binary search를 이용해 구현할 수 있다.

map등을 이용해 range들을 오름차순으로 저장한 뒤 겹칠 가능성이 있는 range와 현재 range를 비교해 겹치는지 판별한다.

이 경우 예약을 비교할 때 들어가는 시간 복잡도는 O(log_2(N))이다.

이를 모든 예약에 대해서 반복하므로 시간 복잡도는 O(N \* log_2(N))

### 공간 복잡도

이전 예약들과 현재 예약을 비교해야 하므로 예약들을 저장할 공간이 필요하다.

공간 복잡도는 O(N) 이다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     104      |   O(N^2)    |    O(N)     |

예약이 들어올 때마다 이미 예약에 성공한 모든 데이터들과 한번씩 비교한다.

range가 겹치는 것이 있을 경우 예약을 취소하고, 겹치지 않을경우 예약에 추가한다.

A와 B가 겹치는지 여부는 다음을 판단한다.

- A.start < B.end
- B.start < A.end

각 range의 시작점이 다른 range의 끝 점보다 작은 경우 겹친다.

만약 end가 같은 두 점에 대해서 비교해보자

- 10, 20
- 15, 20

두 점 모두 start가 다른 end보다 작으므로 겹치는 것을 알 수 있다.

반대로 start가 같은 두 점에 대해서 비교해보자

- 10, 15
- 10, 20

이 경우도 마찬가지임을 알 수 있다.

```cpp
struct Data {
  int start, end;
};
vector<Data> array;

bool book(int start, int end) {
  for (Data data : array) {
    // overlapped
    if (data.start < end && data.end > start) return false;
  }

  array.push_back({start, end});
  return true;
}
```

### BST

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      76      | O(N \* log_2(N)) |    O(N)     |

예약에 성공한 range를 특정 기준에 따라 이진 탐색 트리에 저장한다.

이후 예약이 들어올 때마다 겹칠 위험이 있는 예약들과 현재 예약이 겹치는지를 비교한다.

이 경우 이진 트리에서 찾으므로 검색에 O(log_2(N))의 시간 복잡도가 소요된다.

map, set을 이용해서 BST를 구성할 수 있다.

데이터를 start, end로 저장하는 경우 다음과 같이 구현한다.

입력받은 예약의 start를 lower_bound를 이용해 찾고, 찾은 값과 그 이전값에 대해서 range가 겹치는지 비교한다.

```cpp
// use map
map<int, int> data; // start, end

bool book(int start, int end) {
  auto it = data.lower_bound(start);

  if (it != data.end() && it->first < end) return false;
  if (it != data.begin() && start < prev(it)->second) return false;
  data[start] = end;

  return true;
}

// use set
set<pair<int, int>> data; // start, end

bool book(int start, int end) {
  auto it = data.lower_bound({start, end});

  if (it != data.end() && it->first < end) return false;
  if (it != data.begin() && start < prev(it)->second) return false;

  data.insert({start, end});
  return true;
}
```

혹은 end에 대해서 map을 만들어 풀이할 수도 있다.

start를 초과하는 end를 가진 range를 BST에서 찾는다.

해당 range의 start가 입력받은 end보다 작은지 판별한다.

```cpp
// use map
map<int, int> data; // end, start

bool book(int start, int end) {
  auto it = data.upper_bound(start);

  if (it != data.end() && it->second < end) return false;

  data[end] = start;
  return true;
}

// use set
set<pair<int, int>> data; // end, start

public:
bool book(int start, int end) {
  auto it = data.upper_bound({start, end});

  if (it != data.end() && it->second < end) return false;

  data.insert({end, start});
  return true;
}
```

## 고생한 점
