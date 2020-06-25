# 14889. 스타트와 링크

[링크](https://www.acmicpc.net/problem/14889)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Silver III |  ilver III  |

## 설계

### 시간 복잡도

N은 최대 20이며, 모든 경우를 탐색한다고 했을 때, 대략 2^20 = 1,048,576 번 가량 소요된다.

이는 제한시간 2초 내에 충분하다.

### 공간 복잡도

각 능력치는 100 이하이다.

팀의 능력치가 극단적으로 배분되는 경우 2,000‬ 대 0 으로 배분된다.

따라서 정답의 범위는 int형으로 충분하다.

각 능력치를 저장하기 위해 2차원 배열을 사용한다.

### DFS

두 팀으로 인원을 나누기 위해 DFS를 이용해 탐색한다.

양 팀에 배정한 인원을 저장하고, 인원수가 초과하는지 아닌지에 따라 탐색 여부를 결정한다.

이 방법으로 한쪽 팀의 인원이 절반을 초과하는것을 막는다.

각 팀에대한 정보를 저장하는 struct를 선언해 인자로 넘길 때 사용한다.

```cpp
struct team {
  int total;
  vector<int> list;
};
```

```cpp
void dfs(int index, team team1, team team2) {
  if (index == N) {
    answer = min(answer, abs(team1.total - team2.total));
    return;
  }

  // backtracking
  if (answer == 0) {
    return;
  }

  team new_team1 = team1;
  team new_team2 = team2;
  // 현재 인원이 team1에 오는 경우
  if (team1.list.size() != N / 2) {
    for (int i : new_team1.list) {
      new_team1.total += table[i][index];
      new_team1.total += table[index][i];
    }
    new_team1.list.push_back(index);
    dfs(index + 1, new_team1, team2);
  }

  // 현재 인원이 team2에 오는 경우
  if (team2.list.size() != N / 2) {
    for (int i : new_team2.list) {
      new_team2.total += table[i][index];
      new_team2.total += table[index][i];
    }
    new_team2.list.push_back(index);
    dfs(index + 1, team1, new_team2);
  }
}
```

### Backtracking

양 팀의 차이가 0이 발생하는 경우가 나오는 경우, 그 경우가 정답이므로 더이상의 탐색을 중지한다.

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      20      |       0        |

## 고생한 점
