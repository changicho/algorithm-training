# C. Train and Queries

[링크](https://codeforces.com/contest/1702/problem/C)

| 난이도 |
| :----: |
| \*1100 |

## 설계

### 시간 복잡도

배열 U의 크기를 N, 쿼리의 크기를 K라 하자.

배열을 순회해 각 값마다 가장 처음에 나타난 index, 나중에 나타난 index를 저장한다.

이후 각 쿼리별로 순회하며 정답을 반환한다.

이 경우 순회에 시간 복잡도는 O(N + K)가 소요된다.

index를 저장하기 위해 BST map을 사용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

hash map을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

내부적으로 모든 index를 저장할 때 vector를 사용할 경우 O(1)의 시간 복잡도로 저장 가능하다.

따라서 시간 복잡도는 O(N + K)이다.

### 공간 복잡도

각 index들을 저장하는데 map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### index저장 (BST map)

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     468      | O(N \* log_2(N) + K) |    O(N)     |

(hash map을 사용하는 것보다 빠름)

각 index의 첫번째 나타난 위치와 마지막 나타난 위치가 필요하다.

이는 두 값 A, B를 입력받았을 때 A의 index가 B의 index보다 앞서있는지만 판단하면 되기 때문이다.

여기서 필요한 값은 맨 앞과 맨 뒤 index이므로 중간에 나온 위치들은 무시한다.

배열을 순회해 index들을 저장하고 쿼리를 순회하며 정답을 찾는다.

```cpp
void solution(int N, int K, vector<int> U, vector<pair<int, int>> queries) {
  map<int, vector<int>> indexes;
  for (int i = 0; i < N; i++) {
    int val = U[i];
    if (indexes[val].size() >= 2) indexes[val].pop_back();
    indexes[val].push_back(i);
  }

  for (int i = 0; i < K; i++) {
    cin >> queries[i].first >> queries[i].second;
    int a = queries[i].first, b = queries[i].second;

    if (indexes.count(a) == 0 || indexes.count(b) == 0) {
      cout << "NO\n";
      continue;
    }

    int findAnswer = false;
    findAnswer = indexes[b].back() > indexes[a].front();

    if (findAnswer) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
```

## 고생한 점
