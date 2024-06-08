# B - Piano 2

[링크](https://atcoder.jp/contests/abc355/tasks/abc355_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

두 배열의 길이를 각각 N, M이라 하자.

정렬 후 비교를 진행하며, 이는 O((N + M) \* log_2(N + M))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬에 O(N + M)의 공간 복잡도를 사용한다.

hash set에 O(N)의 공간 복잡도를 사용한다.

### 정렬 & hash set

| 내 코드 (ms) |        시간 복잡도         | 공간 복잡도 |
| :----------: | :------------------------: | :---------: |
|      1       | O((N + M) \* log_2(N + M)) |  O(N + M)   |

A의 원소를 모두 hash set에 넣고, A와 B를 합친 배열을 생성한 뒤 정렬한다.

이후 연이은 값이 A에 둘다 있는지 확인한다.

```cpp
bool solution(vector<int> &a, vector<int> &b) {
  unordered_set<int> us(a.begin(), a.end());

  vector<int> c;
  for (int &num : a) {
    c.push_back(num);
  }
  for (int &num : b) {
    c.push_back(num);
  }
  sort(c.begin(), c.end());

  for (int i = 0; i < c.size() - 1; i++) {
    if (us.count(c[i]) && us.count(c[i + 1])) {
      return true;
    }
  }

  return false;
}
```

## 고생한 점
