# 2391. Minimum Amount of Time to Collect Garbage

[링크](https://leetcode.com/problems/minimum-amount-of-time-to-collect-garbage/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

garbage의 크기를 N이라 하자. travel은 N-1 의 크기를 가진다.

i번째 garbage의 크기는 최대 10이다.

쓰래기의 종류는 3가지이며, 시뮬레이션을 이용해 쓰레기가 남아있는 곳 까지 쓰레기를 제거하러 간다.

이 경우 garbage의 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

미리 각 garbage마다 쓰레기를 저장해 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     342      |    O(N)     |    O(N)     |

미리 3가지 종류의 쓰레기 중 해당 종류의 마지막 쓰레기가 위치하는 곳을 탐색한다.

이는 마지막 쓰레기를 정리한 경우 쓰레기차를 더 이동시킬 필요가 없기 때문이다.

각 쓰레기 종류별로 청소 -> 이동 -> 청소 를 반복하며 남은 쓰레기가 없을 떄 까지 이를 진행한다.

이를 구현하면 다음과 같다.

```cpp
struct House {
  int metal, paper, glass;
};

int garbageCollection(vector<string>& garbage, vector<int>& travel) {
  int size = garbage.size();
  travel.push_back(0);

  vector<House> houses(size);

  House limitIdx = {0, 0, 0};
  for (int i = 0; i < size; i++) {
    House house = {0, 0, 0};

    for (char& c : garbage[i]) {
      if (c == 'M') {
        house.metal++;
      } else if (c == 'G') {
        house.glass++;
      } else if (c == 'P') {
        house.paper++;
      }
    }

    houses[i] = house;
    if (house.metal > 0) limitIdx.metal = i;
    if (house.paper > 0) limitIdx.paper = i;
    if (house.glass > 0) limitIdx.glass = i;
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    answer += houses[i].metal;
    answer += houses[i].paper;
    answer += houses[i].glass;

    if (limitIdx.metal > i) {
      answer += travel[i];
    }
    if (limitIdx.paper > i) {
      answer += travel[i];
    }
    if (limitIdx.glass > i) {
      answer += travel[i];
    }
  }

  return answer;
}
```

## 고생한 점
