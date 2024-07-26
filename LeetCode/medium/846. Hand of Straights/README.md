# 846. Hand of Straights

[링크](https://leetcode.com/problems/hand-of-straights/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 hands의 크기를 N이라 하자.

카드의 갯수를 hash map등에 저장하고, 이후 순회를 통해 각 카드의 갯수를 확인한다.

이 때 가장 작거나 큰 카드부터 선택해야 하므로 정렬을 수행해야 한다.

정렬을 수행하는데 O(N \* log_2(N))의 시간 복잡도가 소요되며, 이후 순회를 통해 각 카드의 갯수를 확인하는데 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

카드의 갯수를 저장할 hash map이 필요하다. 이는 O(N)의 공간 복잡도가 필요하다.

### 정렬 & one pass

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      39      | O(N \* log_2(N)) |    O(N)     |

각 group을 만들기 위해 현재 선택 가능한 가장 작은 값을 매번 선택해야 한다.

이를 위해 정렬을 수행한다.

이후 각 상태마다 최소값을 시작으로 groupSize만큼의 카드를 선택하며, 이를 반복한다.

이 때 카드의 선택을 빠르게 하기 위해 hash map을 이용하며, 총 순회마다 group을 만드는 데 O(N)의 시간 복잡도를 사용한다.

- 그룹의 갯수 : N / groupSize
- 그룹의 크기 : groupSize
- 모든 순회에서 그룹을 만들기 위해 O(N / groupSize * groupSize) = O(N)의 시간 복잡도가 소요된다.

이를 구현하면 다음과 같다.

```cpp
bool isNStraightHand(vector<int> &hand, int groupSize) {
  int size = hand.size();

  if (size % groupSize != 0) return false;

  sort(hand.begin(), hand.end());
  unordered_map<int, int> counts;
  for (int &num : hand) {
    counts[num]++;
  }

  for (int &num : hand) {
    if (counts[num] == 0) continue;

    for (int i = 0; i < groupSize; i++) {
      if (counts[num + i] == 0) return false;
      counts[num + i]--;
    }
  }

  return true;
}
```

## 고생한 점
