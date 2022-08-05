# A. Everyone Loves to Sleep

[링크](https://codeforces.com/contest/1714/problem/A)

| 난이도 |
| :----: |
| \*900  |

## 설계

### 시간 복잡도

입력받은 시간의 갯수를 N이라 하자.

N개의 시간을 정렬하고, 순회하며 잠에드는 시간과 비교한다. 이 때 맨 처음 시간에 24시간을 더한 값과도 비교한다.

이 경우 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이후 순회에 O(N)의 시간 복잡도를 사용한다.

이 때 lower_bound를 사용할 경우 O(log_2(N))의 시간 복잡도로 탐색 가능하다.

### 공간 복잡도

시간을 저장할 공간에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      15      | O(N \* log_2(N)) |    O(N)     |

입력받은 시간을 모두 분으로 변경하고 이를 정렬한다.

이후 맨 처음시간에 24시간만큼의 시간을 더한 값을 추가한다.

현재 시간 이상인 최소값을 lower_bound로 탐색하고 차이를 구한뒤 다시 시, 분으로 변환한다.

```cpp
sort(times.begin(), times.end());
times.push_back(times.front() + (24 * 60));

int target = *lower_bound(times.begin(), times.end(), sleepTime);

int diff = target - sleepTime;

int hour = diff / 60;
int minute = diff % 60;
```

## 고생한 점
