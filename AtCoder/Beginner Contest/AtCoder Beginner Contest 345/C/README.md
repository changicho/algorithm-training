# C - One Time Swap

[링크](https://atcoder.jp/contests/abc345/tasks/abc345_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

입력받은 문자열 S의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용하며 제한시간 내에 불가능하다.

각 문자의 수를 count하고 두 문자를 swap하는 경우의 수를 구해야한다.

count에 순회를 사용할 경우 O(N)의 시간 복잡도를 사용하며 변경하는 문자의 경우 쌍은 알파벳 소문자들 이므로 O(26 \* 25)이므로 O(1)이다.

따라서 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

count에 O(1)의 공간 복잡도를 사용한다.

### count & 완전탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      10      |    O(N)     |    O(1)     |

다른 두 문자 A, B를 swap할 때 나타나는 경우의 수는 다음과 같다.

- count_a \* count_b

즉 A가 존재하던 위치에 B로 바꾸고 기존 B가 존재하던 위치에 A로 바꾸는 경우의 수이다.

이 때 특정 문자 A의 갯수가 2개 이상인 경우 변경 전 원본 문자열을 생성할 수 있으므로 정답에 1을 더한다.

```cpp
long long solution(string &s) {
  long long answer = 0;

  int size = s.size();
  unordered_map<char, int> counts;

  for (char &c : s) {
    counts[c]++;

    if (counts[c] >= 2) answer = 1;
  }

  for (char from = 'a'; from <= 'z'; from++) {
    for (char to = from + 1; to <= 'z'; to++) {
      long long cur = counts[from] * counts[to];

      answer += cur;
    }
  }

  return answer;
}
```

## 고생한 점
