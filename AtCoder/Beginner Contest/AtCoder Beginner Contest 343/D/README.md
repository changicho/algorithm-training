# D - Diversity of Scores

[링크](https://atcoder.jp/contests/abc343/tasks/abc343_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

입력받은 인원의 수를 N, 시간을 T라 하자.

각 시간마다 인원의 점수를 변화시키며 변화된 점수의 종류를 구해야 한다.

이를 직접 탐색할 경우 O(N \* T)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

hash map, map 등을 이용해 점수를 관리할 수 있다. 이 경우 O(T)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

hash map에 O(T)의 공간 복잡도를 사용한다.

각 인원마다 점수를 저장할 배열을 만들 경우 O(N)의 공간 복잡도가 필요하다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      77      |    O(T)     |  O(N + T)   |

각 인원마다 점수를 저장하는 배열과, 각 점수의 갯수를 저장하는 hash map을 이용한다.

```cpp
vector<int> solution(int &n, vector<vector<int>> &ab) {
  vector<int> answer;

  vector<long long> arr(n + 1, 0);
  unordered_map<long long, int> um;

  um[0] = n;

  for (vector<int> &change : ab) {
    int from = change[0];
    long long diff = change[1];

    um[arr[from]]--;
    if (um[arr[from]] == 0) {
      um.erase(arr[from]);
    }

    arr[from] += diff;
    um[arr[from]]++;

    answer.push_back(um.size());
  }

  return answer;
}
```

## 고생한 점

hash map의 key의 범위가 int를 초과할 수 있음을 인지하자.
