# 1552. Magnetic Force Between Two Balls

[링크](https://leetcode.com/problems/magnetic-force-between-two-balls/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 position의 크기를 N, 최대값을 K이라 하자.

특정 거리에 대해 공들을 M개 놓을 수 있는지 여부를 판단해야 한다.

이는 position이 정렬되어 있는 경우 O(N)의 시간 복잡도로 해결할 수 있다. 따라서 정렬에 O(N \* log_2(N))의 시간 복잡도가 필요하다.

거리를 탐색하는데 이분 탐색을 사용할 수 있으므로 이 경우 시간 복잡도는 O(N \* log_2(K))이다.

총 시간 복잡도는 O(N \* log_2(N) + N \* log_2(K))이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도가 필요하다.

### 정렬 & 이분탐색

| 내 코드 (ms) |         시간 복잡도          | 공간 복잡도 |
| :----------: | :--------------------------: | :---------: |
|     136      | O(N * (log_2(N) + log_2(K))) |    O(N)     |

position들이 정렬되어 있을경우 M개의 공을 놓을 수 있는지 판단은 아래와 같이 할 수 있다.

- 공끼리 떨어져야 하는 최소 길이를 D라 하자.
- 이전에 공을 놓은 위치와 현재 위치의 차이가 D이상인 경우 공을 놓는다.
- position을 순회하며 공을 놓는 갯수를 센 뒤 M 이상인지 판별한다.

여기서 거리 D를 이분 탐색으로 찾을 수 있다.

```cpp
bool check(vector<int> &position, int m, int dist) {
  int before = position[0];

  int count = 1;
  for (int &pos : position) {
    if (pos - before >= dist) {
      count++;
      before = pos;
    }
  }

  return count >= m;
}

int maxDistance(vector<int> &position, int m) {
  sort(position.begin(), position.end());
  int left = 0, right = *max_element(position.begin(), position.end());

  int answer = 0;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (check(position, m, mid)) {
      answer = max(answer, mid);
      left = mid + 1;
    } else {
      right = mid;
    }
  }
  return answer;
}
```

## 고생한 점
