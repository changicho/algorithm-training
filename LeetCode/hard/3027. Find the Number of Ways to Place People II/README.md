# 3027. Find the Number of Ways to Place People II

[링크](https://leetcode.com/problems/find-the-number-of-ways-to-place-people-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

배열 points의 크기를 N이라 하자.

정렬 후 이중 순회에 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     122      |   O(N^2)    |    O(N)     |

`3025. Find the Number of Ways to Place People I` 와 같은 문제 (N의 크기만 다름)

모든 point들을 아래와 같은 조건으로 정렬한다.

- y가 작은순으로
- x가 큰순으로

이후 왼쪽부터 순회하며 현재 index를 선택하고 아래 연산을 수행한다.

- index + 1 부터 오른쪽으로 순회한다.
- 순회하며 현재 y좌표가 이전에 선택한 y좌표보다 작은지 판별한다.
- 만약 작은 경우 현재 y좌표를 선택하며 정답을 증가시킨다.

현재 index의 점을 선택했을 때, 정렬된 다른 점들을 순회하며 이전에 선택한 점들보다 y가 작은 순으로 선택해 두 점 사이에 다른 점이 없도록 순회한다.

```cpp
int numberOfPairs(vector<vector<int>> &points) {
  int size = points.size();

  sort(points.begin(), points.end(), [](vector<int> &a, vector<int> &b) {
    if (a[0] == b[0]) return a[1] < b[1];
    return a[0] > b[0];
  });

  int answer = 0;
  for (int i = 0; i < size; i++) {
    int x = points[i][0];
    int y = points[i][1];

    int minY = INT_MAX;
    for (int j = i + 1; j < size; j++) {
      int nx = points[j][0];
      int ny = points[j][1];

      if (ny >= minY || ny < y) continue;
      answer++;
      minY = ny;
    }
  }
  return answer;
}
```

## 고생한 점
