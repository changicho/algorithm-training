# 731. My Calendar II

[링크](https://leetcode.com/problems/my-calendar-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

예약의 수를 N이라 하자.

중복된 예약까지 잡을 수 있으며, 중복된 예약이 3개 이상인 경우 예약이 불가능하다.

따라서 각 예약을 받을 때 마다, 기존 예약과 중복되는지, 중복된 구간들과 다시 중복되는지 검사해야 한다.

이 과정에서 순회에 O(N)의 시간 복잡도가 소요된다.

이를 예약의 수 만큼 반복하므로 시간 복잡도는 O(N^2)이다.

혹은 예약의 시작과 끝을 이루는 timestamp가 오름차순으로 정렬된 map 생성한다.

예약의 시작의 경우 값을 1을 증가시키고 끝인 경우 1을 감소시킨다.

map의 key 순서대로 순차적으로 순회하며 증가된 값이 3인 경우는 중복 예약이 3번 발생했음을 의미하므로 예약할 수 없다.

이 경우에 매번 기존 예약들을 순회하므로 O(N)의 시간 복잡도가 소요된다.

이를 예약의 횟수만큼 반복하므로 O(N^2)의 시간 복잡도가 필요하다.

### 공간 복잡도

예약들을 저장해놔야 겹치는 구간이 있는지 알 수 있으므로 O(N)의 공간 복잡도가 필요하다.

### 브루트 포스

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      72      |   O(N^2)    |    O(N)     |

각 예약의 구간을 예약할 때, 예약 데이터와 겹치는 구간 데이터들을 생성한다.

예약이 가능한지 여부를 판단할 때 겹치는 구간에서 현재 예약이 겹치는 경우 3개가 겹치는 것을 알 수 있으므로 예약이 불가능함을 알 수 있다.

- books : 예약된 구간
- overlaps : 예약된 구간들끼리 겹치는 구간

```cpp
struct Data {
  int start, end;
};
vector<Data> books;
vector<Data> overlaps;

bool book(int start, int end) {
  for (Data data : overlaps) {
    if (data.start < end && data.end > start) return false;
  }
  for (Data data : books) {
    // find overlapped range
    if (data.start < end && data.end > start) {
      overlaps.push_back({max(start, data.start), min(end, data.end)});
    }
  }

  books.push_back({start, end});
  return true;
}
```

### 영역 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     216      |   O(N^2)    |    O(N)     |

예약에 사용하는 timestamp로 이루어진 map을 생성한다.

- key : timestamp
- value : 예약의 시작인 경우 +1, 예약의 끝인 경우 -1

map을 이용하는 이유는 자동적으로 timestamp에 대해 오름차순으로 정렬하기 위함이다.

예약을 받았을 때 해당 구간에 대한 정보를 map에 갱신한다.

timestamp에 대해서 오름차순으로 순회하며 예약된 count가 3이 된 경우 3개의 예약이 중복되었다는 의미이므로 예약을 취소한다.

이는 예약의 구간을 괄호를 여닫는것이라 생각했을 때, 순차적으로 순회하며 열린괄호가 3개가 되는 구간이 있다면, 이는 3번 중복된 것이기 때문이다.

```cpp
map<int, int> m;  // time, +1 if start, -1 if end

bool book(int start, int end) {
  m[start]++;
  m[end]--;
  int booked = 0;

  for (auto it = m.begin(); it != m.end(); it++) {
    booked += it->second;
    if (booked == 3) {
      m[start]--;
      m[end]++;
      return false;
    }
  }

  return true;
}
```

## 고생한 점
