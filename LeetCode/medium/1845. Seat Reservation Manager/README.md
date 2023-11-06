# 1845. Seat Reservation Manager

[링크](https://leetcode.com/problems/seat-reservation-manager/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 자리의 갯수를 N, 연산의 수를 M이라 하자.

min heap을 사용해 각 경우마다 최소값을 찾을 수 있다. 이 경우 각 연산에 O(log_2(N))의 시간 복잡도를 사용한다.

모든 초기값을 heap에 넣는데 O(N \* log_2(N))의 시간 복잡도가 소요된다.

따라서 시간 복잡도는 O((N + M) \* log_2(N)) 이다.

### 공간 복잡도

heap에 O(N)의 공간 복잡도를 사용한다.

### min heap

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     305      | O((N + M) \* log_2(N)) |    O(N)     |

N개의 자리를 모두 min heap에 넣는다.

이후 reserve가 호출되면 heap에서 최소값을 꺼내 반환한다.

unreserve가 호출되면 해당 자리를 다시 heap에 넣는다.

```cpp
class SeatManager {
 private:
  priority_queue<int, vector<int>, greater<int>> pq;

 public:
  SeatManager(int n) {
    for (int i = 0; i < n; i++) {
      pq.push(i + 1);
    }
  }

  int reserve() {
    int ret = pq.top();
    pq.pop();

    return ret;
  }

  void unreserve(int seatNumber) { pq.push(seatNumber); }
};
```

## 고생한 점
