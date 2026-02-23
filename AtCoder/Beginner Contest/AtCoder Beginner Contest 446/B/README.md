# B - Greedy Draft

[링크](https://atcoder.jp/contests/abc446/tasks/abc446_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

사람의 수를 N, 음료수의 종류를 M, 각 사람마다 선호하는 음료수의 총합을 L이라 하자.

hash set을 이용해 각 사람마다 선호하는 음료들 중 남은 음료를 찾는데 O(M + L)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(M)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |  O(M + L)   |    O(M)     |

hash set에 남은 음료수의 종류를 저장한 뒤 각 사람마다 선호하는 음료수들 중 남은 음료수가 있는지 확인한다.

```cpp
vector<int> solution(int n, int m, vector<vector<int>>& x) {
  vector<int> answer;

  unordered_set<int> us;
  for (int i = 1; i <= m; i++) {
    us.insert(i);
  }

  for (vector<int>& fav : x) {
    int target = 0;
    for (int& f : fav) {
      if (us.count(f)) {
        target = f;
        us.erase(f);
        break;
      }
    }

    answer.push_back(target);
  }

  return answer;
}
```

## 고생한 점
