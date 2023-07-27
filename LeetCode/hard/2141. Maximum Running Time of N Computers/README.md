# 2141. Maximum Running Time of N Computers

[링크](https://leetcode.com/problems/maximum-running-time-of-n-computers/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

batteries의 크기를 N, 최대 범위를 M이라 하자. (N <= 10^5, M <= 10^14)

정렬 후 이분탐색을 이용할 경우 정렬에 O(N \* log_2(N)), 이분 탐색에 O(M \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N)의 추가 공간을 사용할 수 있다.

이분 탐색에 O(1)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     114      | O(M \* log_2(N)) |    O(1)     |

현재 배터리 상태로 특정 시간 target동안 전원을 유지할 수 있는지 검사하는데 O(N)의 시간 복잡도를 사용해 판단할 수 있다.

목표로 하는 시간을 target이라 했을 때, 필요한 총 에너지 량은 target \* n 이다.

이 때 배터리들 중에서 target 이상의 값들은 target만큼밖에 사용할 수 없다. 따라서 배터리의 값을 더할 때 각 값이 target보다 많은 경우 target만큼만 더한다.

해당 합이 필요한 양보다 많은 경우 target시간 동안 유지가 가능하다.

이를 이용해 정답 범위에 대해 이분 탐색을 사용할 수 있다.

```cpp
bool check(int n, vector<int>& batteries, long long target) {
  long long extra = 0;
  for (int& b : batteries) {
    extra += min((long long)b, target);
  }

  return extra >= target * n;
}

long long maxRunTime(int n, vector<int>& batteries) {
  long long answer = 0;
  long long left = 0, right = 1e14 + 1;
  while (left < right) {
    long long mid = left + (right - left) / 2;

    if (check(n, batteries, mid)) {
      // pick right
      answer = mid;
      left = mid + 1;
    } else {
      // pick left;
      right = mid;
    }
  }

  return answer;
}
```

## 고생한 점
