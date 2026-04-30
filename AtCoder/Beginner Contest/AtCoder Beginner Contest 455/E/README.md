# E - Unbalanced ABC Substrings

[링크](https://atcoder.jp/contests/abc455/tasks/abc455_e)

| 난이도 |
| :----: |
|  450   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

조합론을 사용해 각 경우를 구하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

두 문자가 같은 수를 구하기 위해 hash map에 O(N)의 공간 복잡도를 사용한다.

### 조합론 & hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      41      |    O(N)     |    O(N)     |

정답에서 구해야 하는 경우의 수는 A, B, C 각각의 수가 다른 substring의 갯수이다.

이는 반대로 전체 경우의 수에서 (A,B), (B,C), (C,A), (A,B,C)가 같은 경우의 수들을 구하고 이를 조합해 구할 수 있다.

- `전체경우의수 - (A,B) - (B,C) - (C,A) + 2 * (A,B,C)`
- 여기서 (A,B,C)를 2번 더해주는 이유는 중복제거된 부분을 추가로 더해줘 보정하기 때문이다.

벤다이어그램으로 생각할때 각 (A,B), (B,C), (C,A)에서 겹치는 부분이 존재함

여기서 각각 경우의 수를 구할 때 2개를 비교하는 경우 diff를 이용해, 3개를 비교하는경우 그중 2개의 diff를 이용해 이전에 해당 diff들이 나타난 갯수를 정답에 더한다.

```cpp
long long countTreeSame(int size, string& s) {
  long long ret = 0;
  int countA = 0, countB = 0, countC = 0;

  function<long long(int, int)> getKey = [](int a, int b) {
    return a * 1e6 + b;
  };

  unordered_map<long long, int> count;
  count[getKey(0, 0)] = 1;

  for (char& c : s) {
    if (c == 'A') {
      countA++;
    } else if (c == 'B') {
      countB++;
    } else if (c == 'C') {
      countC++;
    }

    int AB = countA - countB;
    int BC = countB - countC;

    long long key = getKey(AB, BC);
    ret += count[key];
    count[key]++;
  }
  return ret;
}

long long countTwoSame(int size, string& s, char first, char second) {
  long long ret = 0;
  unordered_map<int, int> count;
  count[0] = 1;
  int countFirst = 0;
  int countSecond = 0;
  for (char& c : s) {
    if (c == first) {
      countFirst++;
    } else if (c == second) {
      countSecond++;
    }

    int diff = countFirst - countSecond;
    ret += count[diff];

    count[diff]++;
  }
  return ret;
}

long long solution(int size, string& s) {
  long long allCase = 1LL * (size) * (size + 1) / 2;
  // A==B || B==C || C==A
  long long sameCase = countTwoSame(size, s, 'A', 'B') +
                       countTwoSame(size, s, 'B', 'C') +
                       countTwoSame(size, s, 'C', 'A');
  long long allSameCase = countTreeSame(size, s);

  return allCase - (sameCase - 2 * allSameCase);
}
```

## 고생한 점
