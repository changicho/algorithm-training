# C - C Stands for Center

[링크](https://atcoder.jp/contests/abc458/tasks/abc458_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

순회를 이용해 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       |    O(N)     |    O(1)     |

문제 조건에 따라 i번째 문자가 C인 경우 해당 문자를 기준으로 왼쪽 문자의 갯수를 L 오른쪽 문자의 갯수를 R이라 하자.

두 값중 작은 값의 갯수만큼 i를 중앙으로 하는 문자열을 만들 수 있다.

```cpp
ll solution(string& s) {
  int size = s.size();

  ll answer = 0;
  ll left = 0, right = size - 1;
  for (int i = 0; i < size; i++) {
    if (s[i] == 'C') {
      answer += min(left, right) + 1LL;
    }
    left++;
    right--;
  }

  return answer;
}
```

## 고생한 점
