# D - Match, Mod, Minimize 2

[링크](https://atcoder.jp/contests/abc416/tasks/abc416_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

두 바열의 크기를 N이라 하자.

그리디 알고리즘을 이용해 가장 유리한 값을 선택하는 방식으로 진행한다.

이 때 multiset을 사용해 이분 탐색을 사용할 경우 O(N \* log_2(N))으로 해결할 수 있다.

### 공간 복잡도

정렬과 multiset을 사용하는데 O(N) 공간 복잡도가 필요하다.

### multiset & lower_bound

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     239      | O(N \* log_2(N)) |    O(N)     |

b에 대해 순회하며 아래와 같은 방식으로 진행한다.

- 현재 배열 b의 원소를 B라 하자.
- 배열 a에서 특정 원소를 B와 더했을 때 m 이상인 가장 작은 원소 A를 찾는다.
- 만약 없는 경우 그냥 가장 작은 원소를 선택한다.

이는 m으로 나누어지는 쌍을 만들 수 없는 경우 더했을 때 m을 초과해 값을 최대한 사라지게 만들어야 하기 때문이다.

각 경우마다 원하는 값을 빠르게 찾기 위해 a의 원소들을 multiset에 저장하고, lower_bound를 사용해 원하는 값을 찾는다.

```cpp
long long solution(int n, int m, vector<int> &a, vector<int> &b) {
  long long answer = 0;

  multiset<int> ms(a.begin(), a.end());

  for (int &second : b) {
    long long target = ((second - m) % m) * -1;

    auto it = ms.lower_bound(target);
    if (it == ms.end()) {
      it = ms.begin();
    }

    answer += (second + *it) % m;
    ms.erase(it);
  }

  return answer;
}
```

## 고생한 점
