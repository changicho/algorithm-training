# 4080. Design Bus Seat Booking System

[링크](https://leetcode.com/problems/design-bus-seat-booking-system/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

각 연산의 수를 N이라 하자.

각 자리를 모두 배열로 관리하고 이를 이용해 시뮬레이션을 수행할 수 있다.

이 경우 배열의 생성에 O(N), 각 연산에 O(1)의 공간 복잡도를 사용한다.

### 공간 복잡도

배열에 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     424      |    O(N)     |    O(N)     |

N \* 4 크기의 배열을 생성 후 각 자리를 toggle할 때 배열 좌석에 필요한 값을 표시한다.

이를 이용해 해당 좌석에 사람이 들어설 때 필요했던 cost를 기록해 나갈 때 cost를 감소시킨다.

현재 상태를 만들기 까지 총 비용을 관리하는 변수를 갱신하며,

최적화된 방법으로 현재 상태를 만들기 위한 최소 연산의 수는 양 끝(창가)좌석부터 채우는 방식이므로 사람이 있는 좌석의 수가 된다.

```cpp
class BusBooking {
 private:
  pair<int, int> parse(string& s) {
    int x = s[0] - 'A';
    int y = stoi(s.substr(1));

    return {y, x};
  }

  vector<vector<int>> board;
  int count = 0;
  int totalTime = 0;

 public:
  BusBooking(int n) { board.resize(n + 1, vector<int>(4, 0)); }

  void toggle(string seat) {
    auto [y, x] = parse(seat);

    if (board[y][x]) {
      count--;

      totalTime -= board[y][x];
      board[y][x] = 0;
    } else {
      count++;

      bool needCross = (x == 0 && board[y][1]) || (x == 3 && board[y][2]);
      int cost = 1 + (needCross ? 2 : 0);
      totalTime += cost;
      board[y][x] = cost;
    }
  }

  int getTotalTime() { return totalTime; }

  int getMinTime() { return count; }
};
```

## 고생한 점
