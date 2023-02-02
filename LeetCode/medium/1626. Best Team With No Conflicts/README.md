# 1626. Best Team With No Conflicts

[링크](https://leetcode.com/problems/best-team-with-no-conflicts/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 player의 수를 N이라 하자.

각 player를 나이와 점수에 따라 정렬 후 동적 계획법을 사용할 수 있다.

정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

이 경우 현재까지 방문 한 인원에 대해 갱신할 때 O(N)의 시간 복잡도를 사용한다.

이후 각 index의 갱신에 O(N)의 시간 복잡도를 사용하므로 총 O(N^2)의 시간 복잡도를 사용한다.

### 공간 복잡도

동적 계획법을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     203      |   O(N^2)    |    O(N)     |

각 인원을 나이와 점수에 대해 오름차순으로 정렬한다고 하자.

이 경우 현재 선수의 앞에 있는 선수들에 대해

- 나이가 어리다
- 나이가 같은경우 점수가 더 낮다

위 식을 만족한다.

이를 이용해 현재 인원까지 방문했을 때 점수를 다음과 같이 갱신할 수 있다.

- 현재 선수보다 점수가 낮은경우 다 더할 때의 최대값 + 현재 점수

여기서 이전 선수까지 방문했을 때의 최대값을 미리 구해놓는 경우 이전 최대값을 이후 갱신에 재사용할 수 있다.

이를 구현하면 다음과 같다.

```cpp
struct Player {
  int age, score;
};

int bestTeamScore(vector<int>& scores, vector<int>& ages) {
  int size = scores.size();

  vector<Player> players;
  for (int i = 0; i < size; i++) {
    players.push_back({ages[i], scores[i]});
  }

  sort(players.begin(), players.end(), [](Player& a, Player& b) {
    if (a.age != b.age) return a.age < b.age;
    return a.score < b.score;
  });


  vector<int> dp(size);
  for (int i = 0; i < size; i++) {
    dp[i] = players[i].score;
  }

  for (int i = 0; i < size; i++) {
    for (int j = i - 1; j >= 0; j--) {
      if (players[i].score >= players[j].score) {
        dp[i] = max(dp[i], players[i].score + dp[j]);
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    answer = max(answer, dp[i]);
  }

  return answer;
}
```

## 고생한 점
