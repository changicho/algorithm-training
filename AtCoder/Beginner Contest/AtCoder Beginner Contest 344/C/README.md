# C - A+B+C

[링크](https://atcoder.jp/contests/abc344/tasks/abc344_c)

| 난이도 |
| :----: |
|  250   |

## 설계

### 시간 복잡도

배열 3개의 크기를 각각 N, M, L, 쿼리의 수를 Q라 하자.

각 경우마다 매번 배열을 순회하며 정답을 찾을 경우 O(N \* M \* L \* Q)의 시간 복잡도가 필요하다. 이는 제한시간 내에 불가능하다.

hash set을 이용해 배열 3개에서 각각 수를 하나씩 뽑아 만들 수 있는 모든 합을 저장한다.

이 경우 시간 복잡도는 O(N \* M \* L)이다. 이후 쿼리를 순회하며 정답을 찾는데 O(Q)의 시간 복잡도가 필요하다.

따라서 총 시간 복잡도는 O(N \* M \* L + Q)이다.

### 공간 복잡도

hash set에 O(N \* M \* L)의 공간 복잡도가 필요하다.

정답 배열에 O(Q)의 공간 복잡도가 필요하다.

### hash set

| 내 코드 (ms) |    시간 복잡도     |    공간 복잡도     |
| :----------: | :----------------: | :----------------: |
|     264      | O(N \* M \* L + Q) | O(N \* M \* L + Q) |

배열 A, B, C에서 하나씩 숫자를 뽑아 합이 되는 모든 경우를 hash set에 저장한다.

이후 쿼리를 순회하며 hash set에 존재하는지 확인한다.

```cpp
vector<bool> solution(vector<int> &a, vector<int> &b, vector<int> &c, vector<long long> &queries) {
  int size1 = a.size(), size2 = b.size(), size3 = c.size();

  vector<bool> answer;

  unordered_set<long long> us;

  for (int i1 = 0; i1 < size1; i1++) {
    for (int i2 = 0; i2 < size2; i2++) {
      for (int i3 = 0; i3 < size3; i3++) {
        long long sum = (long long)a[i1] + b[i2] + c[i3];

        us.insert(sum);
      }
    }
  }

  for (long long &q : queries) {
    if (us.find(q) != us.end()) {
      answer.push_back(true);
    } else {
      answer.push_back(false);
    }
  }

  return answer;
}
```

## 고생한 점
