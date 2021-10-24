# 1870. Minimum Speed to Arrive on Time

[링크](https://leetcode.com/problems/minimum-speed-to-arrive-on-time/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

dist 배열의 크기를 N, 가능한 정답의 최대값을 M (10000000)이라 하자.

현재 speed에 대해서 가능한지 여부를 검사하는데 O(N)의 시간 복잡도를 사용한다.

이를 정답이 될 수 있는 값들에 대해서 모두 검사할 경우 O(M)이므로 시간 초과가 발생한다.

따라서 이분 탐색을 이용해 speed의 탐색을 O(log_2(M))으로 완료한다.

따라서 시간 복잡도는 O(N \* log_2(M))이다.

### 공간 복잡도

이분 탐색을 사용할 때 별도의 공간 복잡도가 필요하지 않다.

따라서 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     279      | O(N \* log_2(M)) |    O(1)     |

정답이 불가능한 경우는 다음과 같을 것이다.

- 각 거리마다 최소 1시간씩 걸린다고 할 때 애초에 불가능한 시간이 주어지는 경우
- 이 때 맨 마지막 거리의 경우는 1시간 이하가 될 수 있음에 유의한다.

dist 배열과 현재 speed가 주어졌을 때 가능한지 여부는 올림연산을 이용해 구현할 수 있다.

거리를 속도로 나눈 값을 올린 값을 더하고, 이 때 맨 마지막 값은 올림처리 하지 않는다.

(맨 마지막 거리를 이동한 다음은 도착점이므로, 이후 이동하기까지 기다릴 이유가 없으므로)

탐색할 범위의 초기 상한값은 정답의 상한으로 정한다.

만약 상한값을 거리중의 최대값으로 정할 경우는 다음 규칙을 따라야한다.

- 시간은 소숫점 2번째 자리까지 주어지므로, 범위의 상한은 거리의 상한의 최대 100배까지 될 수 있다.

```javascript
[1, 1, 100000];
2.01;
```

이를 이용해 구현할 경우 다음과 같다.

```cpp
double estimateHour(vector<int>& dist, int speed) {
  double hour = 0;
  int size = dist.size();

  for (int i = 0; i < size - 1; i++) {
    int d = dist[i];
    hour += ceil((double)d / (double)speed);
  }

  hour += (double)dist.back() / (double)speed;

  return hour;
}

int minSpeedOnTime(vector<int>& dist, double hour) {
  int size = dist.size();
  // impossible case
  if (hour + 1 < size) return -1;

  int left = 0, right = 10000000;

  int answer = INT_MAX;
  // use binary search
  while (left <= right) {
    int mid = left + (right - left) / 2;

    double estimate = estimateHour(dist, mid);
    if (estimate <= hour) {
      // pick left part
      right = mid - 1;
      answer = min(answer, mid);
    } else {
      // pick right part
      left = mid + 1;
    }
  }

  if (answer == INT_MAX) return -1;
  return answer;
}
```

## 고생한 점
