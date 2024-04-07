# E - Set Add Query

[링크](https://atcoder.jp/contests/abc347/tasks/abc347_e)

| 난이도 |
| :----: |
|  500   |

## 설계

### 시간 복잡도

입력받은 수를 N, 쿼리의 수를 Q라 하자.

각 쿼리마다 모든 수를 순회할 경우 O(N \* Q)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 각 쿼리마다 set에서 삭제될 때 정답에 더하는 방법을 사용한다.

이 때 정답에 더하는 수는 현재까지 쿼리를 수행했을 때 set의 갯수의 합이다.

이 경우 hash set을 사용할 때 값의 갱신에 O(1)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N + Q)이다.

### 공간 복잡도

각 수의 상태를 관리할 hash set에 O(N), 각 수마다 sum을 보정하는데 O(N)의 공간 복잡도가 필요하다.

### hash set & sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      60      |    O(N)     |    O(1)     |

각 쿼리마다 매번 set에 존재하는 index에 set.size를 더하지 않고 set에서 삭제될 때 더해준다.

이를 위해 현재까지의 set.size의 합을 계속 저장하고 있어야한다.

또한 set에 저장되기 전의 합은 더하면 안되므로 이를 보정해야한다.

```cpp
vector<long long> solution(int size, vector<int> &queries) {
  vector<long long> answer(size, 0);
  unordered_set<int> s;
  unordered_map<int, long long> startSums;

  long long sum = 0;

  for (int &query : queries) {
    int target = query - 1;

    if (s.count(target) == 0) {
      startSums[target] = sum;
      s.insert(target);
    } else {
      s.erase(target);
      answer[target] += sum - startSums[target];
      startSums.erase(target);
    }
    sum += s.size();
  }

  for (int target : s) {
    answer[target] += sum - startSums[target];
  }

  return answer;
}
```

## 고생한 점
