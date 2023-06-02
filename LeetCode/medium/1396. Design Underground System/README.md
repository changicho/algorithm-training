# 1396. Design Underground System

[링크](https://leetcode.com/problems/design-underground-system/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받는 역의 종류를 S, 승객의 id의 갯수를 P라 하자.

각 승객들마다 check in, check out 시간을 기록하기 위해 hash map을 사용할 수 있다. 이 경우 O(1)의 시간 복잡도를 사용한다.

또한 각 출발지와 도착지의 종류에 대해 hash map을 사용할 수 있다. 이 경우 O(1)의 시간 복잡도를 사용한다.

따라서 총 O(1)의 시간 복잡도로 조회와 갱신이 가능하다.

### 공간 복잡도

두개의 hash map을 사용할 때 다음과 같은 공간 복잡도를 사용한다.

- 승객 : O(P)
- 경로 : O(S^2) (시작역, 도착역의 조합)

따라서 총 공간 복잡도는 O(P + S^2)이다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     162      |    O(1)     | O(P + S^2)  |

각 승객마다 check in시에 출발역과 시간을 기록한다.

check out시에 출발역과 도착역의 경로를 생성하고, 해당 경로에 대한 시간을 갱신한다.

```cpp
class UndergroundSystem {
 private:
  struct CheckIn {
    string station;
    int time;
  };

  struct History {
    double totalTime;
    int count;
  };

  // id, {station, check in time}
  unordered_map<int, CheckIn> checkInMap;
  // path, {total time, count}
  unordered_map<string, History> historyMap;

 public:
  UndergroundSystem() {}

  void checkIn(int id, string stationName, int t) {
    checkInMap[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    auto checkIn = checkInMap[id];
    // erase from check in
    checkInMap.erase(id);

    string path = checkIn.station + "_" + stationName;
    double totalTime = t - checkIn.time;
    historyMap[path].totalTime += totalTime;
    historyMap[path].count++;
  }

  double getAverageTime(string startStation, string endStation) {
    string path = startStation + "_" + endStation;
    auto& History = historyMap[path];
    return History.totalTime / History.count;
  }
};
```

## 고생한 점
