# B - Trifecta

[링크](https://atcoder.jp/contests/abc440/tasks/abc440_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

정렬을 이용하는 데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)만큼의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      1       | O(N \* log_2(N)) |    O(N)     |

```cpp
vector<int> solution(int size, vector<int>& times) {
  vector<int> answer;

  vector<pair<int, int>> indexedTimes;
  for (int i = 0; i < size; i++) {
    indexedTimes.push_back({times[i], i + 1});
  }
  sort(indexedTimes.begin(), indexedTimes.end());

  for (int i = 0; i < 3; i++) {
    answer.push_back(indexedTimes[i].second);
  }

  return answer;
}
```

## 고생한 점
