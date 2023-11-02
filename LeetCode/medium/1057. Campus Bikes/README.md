# 1057. Campus Bikes

[링크](https://leetcode.com/problems/campus-bikes/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 worker의 수를 N, bike의 수를 M이라 하자.

worker와 bike의 쌍의 수를 NM이라 하자.

정렬을 이용해 가장 우선순위가 높은 쌍부터 선택할 수 있다. 이 경우 O(NM \* log_2(NM))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬을 사용할 경우 모든 쌍을 저장할 공간이 필요하므로 O(NM)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |    시간 복잡도     | 공간 복잡도 |
| :----------: | :----------------: | :---------: |
|     247      | O(NM \* log_2(NM)) |    O(NM)    |

각 바이크와 작업자, 해당 쌍의 거리를 모두 계산한다.

이후 이를 우선순위가 높은 순으로 정렬한 뒤 선택할 수 있는 경우 선택한다.

이 때 이미 선택한 bike거나 worker인 경우 다시 선택할 수 없다.

정렬의 우선순위는 다음과 같다.

- 거리가 짧은순
- worker의 index가 작은순
- bike의 index가 작은순

```cpp
struct Data {
  int dist, worker, bike;

  bool operator<(const Data& other) const {
    if (dist != other.dist) return dist < other.dist;
    if (worker != other.worker) return worker < other.worker;
    return bike < other.bike;
  }
};

int findDistance(vector<int>& worker, vector<int>& bike) {
  return abs(worker[0] - bike[0]) + abs(worker[1] - bike[1]);
}

vector<int> assignBikes(vector<vector<int>>& workers, vector<vector<int>>& bikes) {
  // dist, worker, bike
  vector<Data> arr;
  for (int worker = 0; worker < workers.size(); worker++) {
    for (int bike = 0; bike < bikes.size(); bike++) {
      int distance = findDistance(workers[worker], bikes[bike]);
      arr.push_back({distance, worker, bike});
    }
  }

  sort(arr.begin(), arr.end());

  vector<bool> bikeVisited(bikes.size(), false);
  vector<int> worker2bike(workers.size(), -1);

  int choosen = 0;
  for (auto [dist, worker, bike] : arr) {
    if (worker2bike[worker] == -1 && !bikeVisited[bike]) {
      bikeVisited[bike] = true;
      worker2bike[worker] = bike;
      choosen++;

      if (choosen == workers.size()) {
        return worker2bike;
      }
    }
  }

  return worker2bike;
}
```

## 고생한 점
