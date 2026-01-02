# 1244. Design A Leaderboard

[링크](https://leetcode.com/problems/design-a-leaderboard/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

player의 수를 N이라 하자.

bst map을 사용해 점수별로 정렬을 유지한 뒤 K개의 top 점수를 구할 경우 O(N)의 시간 복잡도를 사용한다.

각 인원의 점수를 저장하는데 O(log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

점수를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### BST map

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(N)     |

각 인원마다 점수변동이 있으므로 hash map을 이용해 점수를 저장한다.

그리고 각 점수별로 인원을 BST map을 이용해 저장한다.

top K 점수를 구할 때는 BST map을 역순으로 순회하며 K개의 점수를 더해 반환한다.

```cpp
class Leaderboard {
 private:
  unordered_map<int, int> scores;
  map<int, int> scoreMap;

 public:
  Leaderboard() {}

  void addScore(int playerId, int score) {
    int beforeScore = 0;
    if (scores.count(playerId)) {
      beforeScore = scores[playerId];

      scoreMap[beforeScore]--;
    }
    int newScore = beforeScore + score;
    scores[playerId] = newScore;
    scoreMap[newScore]++;
  }

  int top(int K) {
    int sum = 0;
    int left = K;

    for (auto it = scoreMap.rbegin(); it != scoreMap.rend() && left > 0; it++) {
      int count = it->second;
      int score = it->first;
      int use = min(count, left);

      sum += use * score;
      left -= use;
    }

    return sum;
  }

  void reset(int playerId) {
    if (scores.count(playerId)) {
      int beforeScore = scores[playerId];

      scoreMap[beforeScore]--;
    }
    scores[playerId] = 0;
  }
};
```

## 고생한 점
