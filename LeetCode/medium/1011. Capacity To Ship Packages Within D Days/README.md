# 1011. Capacity To Ship Packages Within D Days

[링크](https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

무게의 갯수를 N, 무게의 총 합을 W라 하자.

현재 capacity에 대해서 주어진 day안에 운반할 수 있는지 판단하는 데 O(N)의 시간 복잡도를 사용한다.

이 capacity를 이분탐색으로 찾을 경우 O(log_2(W))의 시간 복잡도로 탐색할 수 있다.

따라서 시간 복잡도는 O(log_2(W) \* N)이다.

### 공간 복잡도

capacity안에 운반 가능한지 판단하는데 별도의 공간 복잡도를 사용하지 않는다.

따라서 공간 복잡도는 O(1)이다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      36      | O(log_2(W) \* N) |    O(1)     |

days는 최소 1이다. 이는 capacity가 모든 무게의 합인 경우 하루만에 운반이 가능함을 의미한다.

또한 capacity의 최소값은 무게중 가장 큰 값이다.

이는 특정 무게가 capacity를 넘어설 경우 운반이 불가능하기 때문이다.

따라서 탐색해야할 capacity의 범위는 주어진 문제에 한정시킬 수 있다.

이분 탐색에서 왼쪽, 오른쪽으로 탐색을 이어나가는 경우는 다음과 같다.

- 왼쪽 : 현재 무게로 운반이 가능
- 오른쪽 : 현재 무게로 운반이 불가

운반이 가능한지 판단은 다음과 같다.

```cpp
bool canShip(vector<int>& weights, int days, int capacity) {
  int curW = 0, spent = 1;
  for (int& w : weights) {
    if (w > capacity) return false;

    if (curW + w > capacity) {
      spent += 1;
      curW = 0;
    }

    curW += w;
  }

  if (spent <= days) return true;
  return false;
}
```

이를 이용해 구현하면 다음과 같다.

```cpp
int shipWithinDays(vector<int>& weights, int days) {
  int sum = 0, maxW = 0;
  for (int& w : weights) {
    sum += w;
    maxW = max(w, maxW);
  }

  int left = maxW, right = sum;

  int answer = sum;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (canShip(weights, days, mid)) {
      // pick left
      answer = mid;
      right = mid;
    } else {
      // pick right
      left = mid + 1;
    }
  }

  return answer;  // return right;
}
```

## 고생한 점
