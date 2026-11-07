# 2747. Count Zero Request Servers

[링크](https://leetcode.com/problems/count-zero-request-servers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

logs의 크기를 N, queries의 크기를 M이라 하자.

각 값들을 정렬 후 슬라이딩 윈도우를 이용해 원하는 범위를 탐색할 수 있다.

이에 O(N \* log_2(N) + M \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N + M)의 공간 복잡도를 사용한다.

### 정렬 & 슬라이딩 윈도우

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|     120      | O(N \* log_2(N) + M \* log_2(M)) |  O(N + M)   |

logs를 시간 순으로 정렬한다. 이후 쿼리를 시간순으로 순회하며 슬라이딩 윈도우를 사용해 현재 유효한 로그를 순회한다.

이 떄 유요한 log의 유니크한 id를 관리해 각 쿼리마다 정답을 구한다.

```cpp
vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
  int size = queries.size();
  int logSize = logs.size();

  sort(logs.begin(), logs.end(),
        [](auto& a, auto& b) { return a[1] < b[1]; });

  vector<vector<int>> q;
  for (int i = 0; i < size; i++) {
    q.push_back({queries[i], i});
  }
  sort(q.begin(), q.end());

  vector<int> answer(size);

  int leftI = 0, rightI = 0;

  vector<int> count(n + 1);
  int uniqueSize = 0;

  for (vector<int>& query : q) {
    while (rightI < logSize && logs[rightI][1] <= query[0]) {
      count[logs[rightI][0]]++;
      if (count[logs[rightI][0]] == 1) {
        uniqueSize++;
      }
      rightI++;
    }

    while (leftI < logSize && logs[leftI][1] < query[0] - x) {
      count[logs[leftI][0]]--;
      if (count[logs[leftI][0]] == 0) {
        uniqueSize--;
      }
      leftI++;
    }

    answer[query[1]] = n - uniqueSize;
  }
  return answer;
}
```

## 고생한 점
