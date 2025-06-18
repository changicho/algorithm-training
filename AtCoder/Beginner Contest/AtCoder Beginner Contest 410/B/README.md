# B - Reverse Proxy

[링크](https://atcoder.jp/contests/abc410/tasks/abc410_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 수를 N, 쿼리의 수를 Q라 하자.

각 쿼리마다 최소 빈도의 최소값을 찾는데 BST map을 사용할 경우 O((log_2(N))^2)의 시간 복잡도를 사용한다.

쿼리의 수가 Q이므로 전체 시간 복잡도는 O(Q \* (log_2(N))^2)이 된다.

### 공간 복잡도

각 쿼리마다 정답을 저장하는데 O(Q)의 공간 복잡도를 사용한다.

각 숫자를 저장하는데 O(N)의 공간 복잡도를 사용한다.

### BST map

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|      1       | O(Q \* (log_2(N))^2) |  O(N + Q)   |

각 쿼리마다 box중에서 갯수가 가장 적으며 그 중에서 가장 작은 값을 찾아야 한다.

BST map을 이용해 가장 빈도가 낮은 box들을 찾고 그 중 가장 작은 값을 찾는다.

```cpp
vector<int> solution(int n, int size, vector<int> &queries) {
  vector<int> answer;

  int count[101] = {
      0,
  };
  map<int, set<int>> mp;
  for (int i = 1; i <= n; i++) {
    mp[0].insert(i);
  }

  for (int &q : queries) {
    int ret = 0;
    int target = 0;

    if (q == 0) {
      auto it = mp.begin();
      target = *it->second.begin();
    } else {
      target = q;
    }

    ret = target;

    mp[count[target]].erase(target);
    if (mp[count[target]].empty()) {
      mp.erase(count[target]);
    }
    count[target]++;
    mp[count[target]].insert(target);

    answer.push_back(ret);
  }

  return answer;
}
```

## 고생한 점
