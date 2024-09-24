# 950. Reveal Cards In Increasing Order

[링크](https://leetcode.com/problems/reveal-cards-in-increasing-order/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 deck의 크기를 N이라 하자.

뽑는 순서가 오름차순으로 정렬되어야 하므로 정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

투 포인터를 사용해 정답 배열을 완성할 경우 O(N)의 시간 복잡도가 필요하다.

큐를 사용해 풀이할 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

큐에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 큐

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      0       | O(N \* log_2(N)) |    O(N)     |

deck을 정렬한다. 이는 뽑는 순서가 오름차순이 되도록 하기 위함이다.

이후 뽑는 순서에 해당하는 index들을 저장할 큐를 사용한다.

해당 큐에는 정답배열의 현재 뽑는 index들을 저장하며, 각 경우마다 큐의 front를 뽑아 index를 찾고 정답배열에 정렬된 수를 저장한다.

```cpp
vector<int> deckRevealedIncreasing(vector<int>& deck) {
  int size = deck.size();
  queue<int> q;

  for (int i = 0; i < size; i++) {
    q.push(i);
  }

  sort(deck.begin(), deck.end());

  vector<int> answer(size);
  for (int i = 0; i < size; i++) {
    answer[q.front()] = deck[i];
    q.pop();

    if (!q.empty()) {
      q.push(q.front());
      q.pop();
    }
  }

  return answer;
}
```

## 고생한 점
