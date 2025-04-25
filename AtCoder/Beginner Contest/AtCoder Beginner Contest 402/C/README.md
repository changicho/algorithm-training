# C - Dislike Foods

[링크](https://atcoder.jp/contests/abc402/tasks/abc402_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

총 재료의 갯수를 N, 요리의 수를 M, 요리의 모든 재료의 수를 K라 하자.

각 재료마다 추가되는 순서를 관리하며 최종적으로 요리마다 만들 수 있는 가능한 시점을 순회를 이용해 구할 수 있다.

이 경우 시간 복잡도는 O(N + M + K)이다.

### 공간 복잡도

각 재료마다 추가되는 시점을 저장하는데 O(N)만큼의 공간이 필요하다.

각 시점마다 가능한 요리의 수를 추가하는데 O(N)의 공간 복잡도를 사용한다.

### diff

| 내 코드 (ms) | 시간 복잡도  | 공간 복잡도 |
| :----------: | :----------: | :---------: |
|     107      | O(N + M + K) |    O(N)     |

각 재료마다 추가되는 시점을 저장한다.

이후 각 요리마다 재료 중 가장 마지막에 재료가 추가되는 시점을 찾고, 해당 시점에 만들 수 있는 요리의 수를 +1 올린다.

이후 각 시점마다 가능한 요리의 수를 정답에 추가한다.

```cpp
vector<int> solution(int size, int dishSize, vector<vector<int>> &dishes,
                     vector<int> &overcomes) {
  vector<int> answer;
  unordered_map<int, int> overcomeMap;
  for (int i = 0; i < size; i++) {
    overcomeMap[overcomes[i]] = i;
  }

  vector<int> diffs(size, 0);
  for (int i = 0; i < dishSize; i++) {
    int maximum = -1;
    for (int &dish : dishes[i]) {
      maximum = max(maximum, overcomeMap[dish]);
    }

    int endTime = maximum;
    diffs[endTime] += 1;
  }

  int temp = 0;
  for (int i = 0; i < size; i++) {
    temp += diffs[i];
    answer.push_back(temp);
  }

  return answer;
}
```

## 고생한 점
