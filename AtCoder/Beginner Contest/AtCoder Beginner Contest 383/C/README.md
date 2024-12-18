# C - Perfect Standings

[링크](https://atcoder.jp/contests/abc384/tasks/abc384_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

각 문제를 풀이한 경우의 수는 2^5 이다.

모든 경우를 탐색하며 정렬할 경우 O(2^5 \* log_2(2^5))의 시간 복잡도가 필요하다.

### 공간 복잡도

정답의 공간에 O(2^5)의 공간 복잡도가 필요하다.

### 완전 탐색 & 정렬

|     시간 복잡도      | 공간 복잡도 |
| :------------------: | :---------: |
| O(2^5 \* log_2(2^5)) |   O(2^5)    |

5가지 문제에 대해서 합/불의 모든 경우를 탐색하며 점수를 저장한 뒤 이를 내림차순으로 정렬한다.

이후 정렬된 순서대로 이름으로 정답을 만들어 반환한다.

```cpp
struct Rank {
  string name;
  int score;
};

vector<string> solution(vector<int> &score) {
  vector<string> answer;

  vector<Rank> ranks;
  function<void(string &, int)> dfs = [&](string &name, int index) {
    if (index == 5) {
      if (name.size() == 0) return;
      int cur = 0;
      for (char &c : name) {
        cur += score[c - 'A'];
      }
      ranks.push_back({name, cur});
      return;
    }

    name += ('A' + index);
    dfs(name, index + 1);
    name.pop_back();
    dfs(name, index + 1);
  };

  string name = "";
  dfs(name, 0);

  sort(ranks.begin(), ranks.end(), [](Rank &a, Rank &b) {
    if (a.score == b.score) {
      return a.name < b.name;
    }
    return a.score > b.score;
  });

  for (Rank &r : ranks) {
    answer.push_back(r.name);
  }

  return answer;
}
```

## 고생한 점
