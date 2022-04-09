# 2225. Find Players With Zero or One Losses

[링크](https://leetcode.com/problems/find-players-with-zero-or-one-losses/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

matches의 크기를 N이라 하자.

플레이어의 수는 최대 2N까지 될 수 있으며 이를 M이라 하자.

각 match를 순회하며 승패를 기록해야한다. 이에 O(N)의 시간복잡도를 사용한다.

이후 각 인원들을 순회하며 정답인 경우를 찾는다. 이에 O(M)의 시간 복잡도를 사용한다.

이후 이를 한꺼번에 정렬한다. 이 경우 O(M \* log_2(M))의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

승패를 기록할 map이 필요하며 이는 O(N)의 공간 복잡도를 사용한다.

### BST map

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     608      | O(N \* log_2(N)) |    O(N)     |

각 match를 순회하며 승패를 기록한다.

각 인원마다의 승패를 기록하기 위해 map, hash map을 사용할 수 있다.

정답의 인원은 오름차순으로 정렬되어있어야 하므로 map을 이용해 기존에 정렬된 상태로 유지한다.

이후 map에 승패를 기록하고, 이후 0패, 1패인 인원을 각 배열에 삽입후 반환한다.

```cpp
vector<vector<int>> findWinners(vector<vector<int>>& matches) {
  map<int, int> loseCount;

  for (vector<int>& match : matches) {
    int winner = match[0], loser = match[1];

    if (loseCount.count(winner) == 0) {
      loseCount[winner] = 0;
    }
    loseCount[loser]++;
  }

  vector<int> notLostPlayers;
  vector<int> oneLostPlayers;
  for (auto& [p, c] : loseCount) {
    if (c == 0) {
      notLostPlayers.push_back(p);
    } else if (c == 1) {
      oneLostPlayers.push_back(p);
    }
  }

  return {notLostPlayers, oneLostPlayers};
}
```

## 고생한 점
