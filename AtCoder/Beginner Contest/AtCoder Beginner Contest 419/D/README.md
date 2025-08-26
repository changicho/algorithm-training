# D - Substr Swap

[링크](https://atcoder.jp/contests/abc419/tasks/abc419_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

두 문자열의 길이를 N, 쿼리의 수를 Q라 하자.

각 쿼리마다 모든 경우를 직접 수행할 경우 O(N \* Q)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

각 쿼리마다 영향을 주는 좌표를 기록해 두고 이를 마지막에 한 번에 처리할 경우 O(N + Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 index마다 영향을 주는 쿼리의 수를 기록할 경우 O(N)의 공간 복잡도를 사용한다.

### diff array

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      27      |  O(N + Q)   |    O(N)     |

문제에서 각 쿼리마다 영향을 주는 index를 아래와 같이 표현할 수 있다.

```plain_text
0 0 0 0 1 1 1 1 0 0
0 0 0 1 1 1 1 1 0 0
1 1 1 0 0 0 0 0 0 0
0 0 0 0 0 1 0 0 0 0
1 1 1 1 0 0 0 0 0 0
```

이 경우 각 index에 영향을 짝수번 주는 경우 정답에 A의 문자가 추가되며, 영향을 홀수번 주는 경우 정답에 B의 문자가 추가된다.

따라서 각 index마다 쿼리에 몇번 영향을 받는지 기록해둔다.

이 때 매번 쿼리마다 순회하며 기록할 경우 O(N \* Q)의 시간 복잡도를 사용하므로 제한시간 내에 불가능하다.

diff array를 이용해 각 쿼리마다 O(1)의 시간 복잡도로 기록한다.

이후 각 index마다 변화하는 값을 누적으로 구하며 현재 index에 몇개의 쿼리가 영향을 주는지 기록한다.

```cpp
struct Swap {
  int left, right;
};

auto solution(int length, int size, string &s, string &t, vector<Swap> &swaps) {
  vector<int> diffs(length + 1);

  for (Swap &swap : swaps) {
    diffs[swap.left]++;

    diffs[swap.right + 1]--;
  }

  string answer = "";
  for (int i = 0, temp = 0; i < length; i++) {
    temp += diffs[i];
    if (temp % 2 == 1) {
      answer += t[i];
    } else {
      answer += s[i];
    }
  }

  return answer;
}
```

## 고생한 점
