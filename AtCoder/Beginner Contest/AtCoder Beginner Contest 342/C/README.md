# C - Many Replacement

[링크](https://atcoder.jp/contests/abc342/tasks/abc342_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

문자열 S의 길이를 L, 쿼리의 갯수를 Q라 하자.

모든 경우를 직접 수행할 경우 O(Q \* L)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

따라서 각 문자별로 최종적으로 바뀌는 문자를 저장하고, 이를 이용해 쿼리를 수행한다.

이 경우 문자의 종류는 26가지 이므로 O(1)의 시간 복잡도로 수행이 가능하며 이를 모든 쿼리에 대해 수행할 경우 O(Q)의 시간 복잡도가 소요된다.

이를 이용해 S를 변경하는 데 O(L)의 시간 복잡도가 소요된다.

### 공간 복잡도

문자열 S를 재사용할 경우 O(1)의 공간 복잡도를 사용하며, 이를 복사할 경우 O(L)의 공간 복잡도가 필요하다.

### 문자 테이블

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |  O(L + Q)   |    O(L)     |

각 문자별로 변환 테이블을 구성할 경우, 추후에 사이클이 존재할 수 있다.

따라서 쿼리를 수행하며 테이블을 순회하며 변경할 문자들을 한꺼번에 변경해준다.

최종적으로 변환된 테이블을 이용해 정답 문자열을 반환한다.

```cpp
string solution(string &s, vector<vector<char>> &queries) {
  string table = "";
  for (char c = 'a'; c <= 'z'; c++) {
    table += c;
  }

  for (vector<char> &q : queries) {
    char from = q[0], to = q[1];

    for (int i = 0; i < table.size(); i++) {
      if (table[i] == from) {
        table[i] = to;
      }
    }
  }

  for (char &c : s) {
    c = table[c - 'a'];
  }

  return s;
}
```

## 고생한 점
