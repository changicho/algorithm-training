# C - Long Sequence

[링크](https://atcoder.jp/contests/abc457/tasks/abc457_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

입력받은 배열의 갯수를 N, 각 배열의 내부 크기를 L, 순서를 K라 하자.

K를 직접 생성할 경우 제한시간 내에 불가능하다.

배열의 원소를 순회하며 순서를 찾을 경우 O(NL)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

K와 C의 원소가 매우 크므로 long long형을 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |    O(NL)    |    O(1)     |

남은 K가 있는 경우 배열을 순회하며 뒤에 덧붙이는 갯수 만큼 K를 빼준다.

만약 현재 배열에 정답이 존재하는 경우 이를 반환한다.

```cpp
auto solution(int n, ll k, vector<vector<int>>& a, vector<int>& c) {
  for (int i = 0; i < n; i++) {
    vector<int>& line = a[i];

    if (k <= (ll)c[i] * line.size()) {
      return line[(k - 1) % line.size()];
    }

    k -= (ll)c[i] * line.size();
  }

  return -1;
}
```

## 고생한 점
