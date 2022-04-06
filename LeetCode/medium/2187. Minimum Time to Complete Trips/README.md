# 2187. Minimum Time to Complete Trips

[링크](https://leetcode.com/problems/minimum-time-to-complete-trips/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

times의 크기를 N, 가능한 정답의 범위를 M이라 하자.

M은 최대 10^14까지가 된다. (모든 시간이 1이고 totalTrip이 10^7인 경우)

특정 값에 대해 trip이 가능한지 판단하기 위해 모든 time을 순회해야 한다. 이 경우 O(N)의 시간 복잡도를 사용한다.

가능한 time의 범위를 모두 탐색할 경우 매우 커지므로 이분 탐색을 이용한다.

이 경우 시간 복잡도는 O(log_2(M))을 소요한다.

따라서 총 시간 복잡도는 O(N \* log_2(M))이다.

### 공간 복잡도

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

그 외에 별도의 공간 복잡도를 사용하지 않는다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     245      | O(N \* log_2(M)) |    O(1)     |

현재값으로 totalTrips를 만족할 수 있는지는 다음과 같이 판단한다.

- 현재 값을 각 time으로 나눈 몫의 합이 totalTrips 이상인지 여부

이는 해당 시간(값)까지 왕복을 포함한 각 버스들의 도착 횟수가 총 몇번인지 판단하기 위함이다.

따라서 (총 시간) / (버스 시간)으로 나눈 값의 몫으로 판단한다.

정답의 범위는 1 이상 10^14 이하이다.

이는 최악의 경우 모든 버스가 1초만에 도착지에 도달하고, 버스의 갯수가 10^7개인 경우의 정답이기 때문이다.

이를 구현하면 다음과 같다.

```cpp
bool isPossible(vector<int> &time, long long cur, long long totalTrips) {
  long long count = 0;
  for (int &t : time) {
    count += (long long)cur / t;

    if (count >= totalTrips) return true;
  }

  return false;
}

long long minimumTime(vector<int> &time, int totalTrips) {
  long long answer = -1;
  long long left = 0, right = (long long)time.front() * totalTrips + 1;

  while (left < right) {
    long long mid = left + (right - left) / 2;

    if (isPossible(time, mid, totalTrips)) {
      answer = mid;
      right = mid;
    } else {
      left = mid + 1;
    }
  }
  return answer;
}
```

## 고생한 점
