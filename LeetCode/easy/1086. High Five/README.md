# 1086. High Five

[링크](https://leetcode.com/problems/high-five/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 id마다의 큰 순으로 5개를 정렬을 이용해 찾을 수 있다.

이 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      4       | O(N \* log_2(N)) |    O(N)     |

각 item들을 id별로 모은 뒤 값을 정렬 후 큰 순으로 5개의 평균을 구한다.

이후 id별로 이를 정답에 더한다.

```cpp
vector<vector<int>> highFive(vector<vector<int>>& items) {
  int size = items.size();

  sort(items.begin(), items.end(), [](vector<int>& a, vector<int>& b) {
    if (a[0] != b[0]) return a[0] < b[0];
    return a[1] > b[1];
  });

  vector<vector<int>> answer;

  for (int i = 0; i < size; i++) {
    int id = items[i][0];

    int sum = 0;
    for (int j = 0; j < 5; j++) {
      sum += items[i + j][1];
    }

    answer.push_back({id, sum / 5});

    while (i + 1 < size && items[i][0] == items[i + 1][0]) {
      i++;
    }
  }

  return answer;
}
```

## 고생한 점
