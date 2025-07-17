# 2410. Maximum Matching of Players With Trainers

[링크](https://leetcode.com/problems/maximum-matching-of-players-with-trainers/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

멀티셋을 사용할 경우 정렬 및 순회 하는데 O(M \* log_2(M) + N)의 시간 복잡도를 사용한다.

정렬 및 투 포인터를 사용할 경우 정렬에 O(N \* log_2(N) + M \* log_2(M))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N + M)의 공간 복잡도를 사용한다.

멀티셋에 O(M)의 공간 복잡도를 사용한다.

### 정렬 & 투 포인터

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      28      | O(N \* log_2(N) + M \* log_2(M)) |  O(N + M)   |

두 배열을 오름차순으로 정렬하며, 각 player를 순회하며 현재 값 이상의 가장 작은 trainer를 찾는다.

```cpp
int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
  int size = trainers.size();

  sort(players.begin(), players.end());
  sort(trainers.begin(), trainers.end());

  int answer = 0;
  int i = 0;
  for (int& p : players) {
    while (i < size && p > trainers[i]) {
      i++;
    }

    if (i == size) break;
    answer++;
    i++;
  }
  return answer;
}
```

## 고생한 점
