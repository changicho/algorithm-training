# B - Ranking with Ties

[링크](https://atcoder.jp/contests/abc399/tasks/abc399_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 점수마다의 랭크를 구하기 위해 정렬을 사용해야 한다.

이에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간이 필요하다.

각 점수마다 갯수를 세는데 O(N)의 공간이 필요하다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      1       | O(N \* log_2(N)) |    O(N)     |

각 점수를 센뒤 유니크한 점수들을 내림차순으로 정렬한다.

이후 점수에 대해 순회하며 현재 부여하는 랭크를 부여한다.

```cpp
vector<int> solution(int size, vector<int> &scores) {
  unordered_map<int, int> count;
  set<int> unique_scores;
  for (int &score : scores) {
    count[score]++;
    unique_scores.insert(score);
  }

  unordered_map<int, int> rank;
  int r = 1;
  for (auto it = unique_scores.rbegin(); it != unique_scores.rend(); it++) {
    rank[*it] = r;
    r += count[*it];
  }

  vector<int> answer;
  for (int &score : scores) {
    answer.push_back(rank[score]);
  }

  return answer;
}
```

## 고생한 점
