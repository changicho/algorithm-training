# C - Variety

[링크](https://atcoder.jp/contests/abc461/tasks/abc461_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

배열을 정렬 후 필요한 최소 색상의 갯수에서 가장 큰 값을 고르고 남은 값들 중 최대값들을 고른다.

정렬에 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      40      | O(N \* log_2(N)) |    O(N)     |

각 gem을 value에 따라 내림차순으로 정렬한다.

이 중 M개의 다른 색상 중 가장 큰 값들을 선택한다.

이후 남은 값들 중 큰 값 순서대로 총 (K - M)개 선택해 정답에 더한다.

```cpp
using ll = long long;

struct Gem {
  int color, value;
};

ll solution(int size, int k, int m, vector<int>& colors, vector<int>& values) {
  ll answer = 0;

  vector<Gem> arr;
  for (int i = 0; i < size; i++) {
    int c = colors[i], v = values[i];

    arr.push_back({c, v});
  }

  sort(arr.begin(), arr.end(),
       [](Gem& a, Gem& b) { return a.value > b.value; });

  unordered_set<int> used;
  vector<int> remains;
  for (Gem& cur : arr) {
    if (used.count(cur.color) == 0 && m > 0) {
      answer += cur.value;
      k--;
      m--;
      used.insert(cur.color);
    } else {
      remains.push_back(cur.value);
    }
  }

  for (int i = 0; i < k; i++) {
    answer += remains[i];
  }

  return answer;
}
```

## 고생한 점
