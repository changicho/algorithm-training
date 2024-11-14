# 2023 KAKAO BLIND RECRUITMENT - 택배 배달과 수거하기


[링크](https://school.programmers.co.kr/learn/courses/30/lessons/150369)

| 난이도 |
| :----: |
|  lv2   |

## 설계

### 시간 복잡도

입력받은 두 배열의 길이를 N이라 하자.

스택을 이용해 시뮬레이션을 수행할 수 있다. 이 때 cap의 최소값은 1, 배송할 박스의 갯수의 최대값은 50이다.

따라서 최악의 경우 시간 복잡도는 O(N \* 50)이다. 이는 O(N)이다.

### 공간 복잡도

별도의 스택을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

입력받은 배열을 그대로 사용할 경우 별도의 공간이 필요하지 않다.

### 스택 & 시뮬레이션

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

매 경우마다 집들 중 가장 마지막 집의 박스를 배송하고, 가장 마지막 집의 박스를 수거한다.

이를 반복하며 시뮬레이션을 수행한다.

이를 위해 가장 마지막 집의 택배와 수거할 박스 상황만 바라보면 되므로 스택을 이용한다.

각 스택의 top과 cap을 비교하며 시뮬레이션을 수행한다.

매 배달 마다 스택의 top을 감소시키며, 0이 되는 경우 pop한다.

```cpp
long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
  long long answer = 0;

  while (deliveries.size() || pickups.size()) {
    while (deliveries.size() && deliveries.back() == 0) {
      deliveries.pop_back();
    }
    while (pickups.size() && pickups.back() == 0) {
      pickups.pop_back();
    }

    int boxCount = cap;
    int emptyCount = cap;

    int dist = max(deliveries.size(), pickups.size());
    answer += dist * 2;
    while (!deliveries.empty() && boxCount > 0) {
      deliveries[deliveries.size() - 1] -= boxCount;
      boxCount = 0;
      if (deliveries[deliveries.size() - 1] < 0) {
        boxCount = abs(deliveries[deliveries.size() - 1]);
        deliveries.pop_back();
      }
    }

    while (!pickups.empty() && emptyCount > 0) {
      pickups[pickups.size() - 1] -= emptyCount;
      emptyCount = 0;

      if (pickups[pickups.size() - 1] < 0) {
        emptyCount = abs(pickups[pickups.size() - 1]);
        pickups.pop_back();
      }
    }
  }

  return answer;
}
```

## 고생한 점
