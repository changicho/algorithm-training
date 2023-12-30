# 1561. Maximum Number of Coins You Can Get

[링크](https://leetcode.com/problems/maximum-number-of-coins-you-can-get/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 piles의 크기를 N이라 하자.

3명이 동전을 고를 때 점수에 포함되는 동전은 2번째에 선택된다.

따라서 각 상황마다 최선의 값을 선택하기 위해 정렬을 수행한다. 이 때 O(N \* log_2(N))의 시간 복잡도를 사용한다.

각 과정에서 우선순위가 높은 값을 선택하기 위해 데크를 사용할 수 있다. 이후 순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

데크를 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 정렬 & 데크

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     104      | O(N \* log_2(N)) |    O(N)     |

3개의 수를 선택할 때 앨리스는 가장 큰 값을 선택하고, 우리는 그 다음으로 큰 값을 선택한다.

밥은 가장 나중 값을 선택한다.

따라서 밥에게는 가장 작은 값들을 몰아주고, 우리에게는 선택 가능한 가장 큰 값들을 몰아준다.

이 때 최대값들은 앨리스가 가져가므로 선택하지 못한다.

정렬을 수행 후에 값들을 순서대로 데크에 저장한다.

각 과정에서 앨리스와 우리는 큰 값들을, 밥은 작은 값들을 선택한다.

이를 반복한다.

```cpp
int maxCoins(vector<int>& piles) {
  sort(piles.begin(), piles.end());

  deque<int> queue(piles.begin(), piles.end());

  int answer = 0;
  while (!queue.empty()) {
    queue.pop_back();        // alice
    answer += queue.back();  // us
    queue.pop_back();
    queue.pop_front();  // bob
  }

  return answer;
}
```

## 고생한 점
