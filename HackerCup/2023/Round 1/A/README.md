# Problem A: Here Comes Santa Claus

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2023/round-1/problems/A)

| 난이도 |
| :----: |
| 10 pt  |

## 설계

### 시간 복잡도

요정의 수를 N이라 하자. 입력받은 요정의 위치를 정렬 한 뒤 짝을 탐욕적으로 지을 수 있다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

요정의 위치는 최대 10^9 까지이다. 이는 int형으로 충분하다.

정렬에 별도의 공간 복잡도를 사용하지 않을 경우 O(1)의 공간 복잡도로 충분하다.

### 정렬 & 탐욕 알고리즘

|   시간 복잡도    | 공간 복잡도 |
| :--------------: | :---------: |
| O(N \* log_2(N)) |    O(1)     |

산타는 맨 왼쪽부터 맨 오른쪽 까지 순회한다고 하자.

이 때 맨 왼쪽 요정 집합과 맨 오른쪽 요정 집합의 위치를 알고 있을 경우, 나머지 요정들은 어느 위치에서 만나던 산타의 총 이동거리는 변하지 않는다.

따라서 맨 왼쪽 요정 집합, 맨 오른쪽 요정 집합 두 집합을 구하고, 이 두 집합의 각각 만나는 위치를 이용해 산타의 이동거리를 구할 수 있다.

이 때 각 집합에서 만나는 점은 다음과 같다.

- 각 요정들이 모이는 위치까지의 거리중 최대값
- 따라서 가장 양 끝단에 위치한 요정들의 중앙위치

여기서 요정은 꼭 쌍을 이루어야 하며 가장 이동 위치가 짧은 곳에서 만나야 한다.

N이 6이상인 경우는 맨 왼쪽 집합, 오른쪽 집합 이외에도 중간에 집합이 존재한다.

N이 4인 경우는 두 집합만 존재하며 각 집합의 요정은 2명이다.

N이 5인 경우 가운데 위치한 요정은 두 집합중 한곳에 포함되어야 한다.

이 때 총 이동거리가 최소인 집합에 포함한 뒤 정답을 계산한다.

```cpp
double mean(vector<int> nums) {
  double sum = 0;
  for (int i = 0; i < nums.size(); i++) {
    sum += nums[i];
  }
  return sum / nums.size();
}

double getCost(vector<int> nums) {
  double meanVal = mean(nums);
  double cost = 0;
  for (int i = 0; i < nums.size(); i++) {
    cost += abs(nums[i] - meanVal);
  }
  return cost;
}

double solution(vector<int> &positions) {
  sort(positions.begin(), positions.end());
  int size = positions.size();
  // do something

  if (size == 5) {
    double leftTwoCost = getCost({positions[2], positions[3], positions[4]}) +
                         getCost({positions[0], positions[1]});
    double leftThreeCost = getCost({positions[3], positions[4]}) +
                           getCost({positions[0], positions[1], positions[2]});

    double leftTwo =
        mean({positions[2], positions[4]}) - mean({positions[0], positions[1]});
    double leftThree =
        mean({positions[3], positions[4]}) - mean({positions[0], positions[2]});

    if (leftTwoCost < leftThreeCost) {
      return leftTwo;
    }
    if (leftTwoCost > leftThreeCost) {
      return leftThree;
    }
    return min(leftTwo, leftThree);
  }

  return mean({positions[size - 2], positions[size - 1]}) -
         mean({positions[0], positions[1]});
}
```

## 고생한 점
