# 2374. Node With Highest Edge Score

[링크](https://leetcode.com/problems/node-with-highest-edge-score/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

edges의 크기를 N이라 하자.

노드의 갯수는 N개이며, 각 edge마다 끝 노드에 현재 index를 더한다.

이 경우 각 edge를 순회할 때 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 노드마다의 score를 저장하는 데 O(N)의 공간 복잡도를 사용한다.

### two pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     253      |    O(N)     |    O(N)     |

각 edge를 순회하며 끝점에 현재 index를 더한다.

이후 갱신된 점수 중 가장 큰 값의 index를 반환한다.

```cpp
int edgeScore(vector<int>& edges) {
  int size = edges.size();

  vector<long long> scores(size, 0);

  for (int i = 0; i < size; i++) {
    scores[edges[i]] += i;
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (scores[answer] < scores[i]) {
      answer = i;
    }
  }

  return answer;
}
```

## 고생한 점
