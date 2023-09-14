# 2840. Check if Strings Can be Made Equal With Operations II

[링크](https://leetcode.com/problems/check-if-strings-can-be-made-equal-with-operations-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 s1, s2의 길이를 N이라 하자.

각 문자를 변경 가능한 위치를 계산해보면 짝수, 홀수 index 끼리만 변경이 가능함을 알 수 있다.

따라서 이를 이용해 정답을 풀이할 수 있다.

만약 정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

문자 counting을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

문자를 생성 후 정렬할 경우 O(N)의 공간 복잡도를 사용한다.

카운팅을 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 카운팅

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      44      |    O(N)     |    O(1)     |

문제의 조건에 따라 문자열을 변경할 수 있는 index는 짝수, 홀수 index끼리만 가능하다.

각 문자열의 짝수, 홀수 index에 위치한 문자의 개수를 카운팅한다.

이후 두 문자열의 카운팅한 값이 같은지 비교한다.

```cpp
pair<vector<int>, vector<int>> convert(string &s) {
  int size = s.size();
  vector<int> evens(26), odds(26);

  for (int i = 0; i < size; i++) {
    char &c = s[i];
    if (i % 2 == 0) {
      evens[c - 'a']++;
    } else {
      odds[c - 'a']++;
    }
  }

  return {evens, odds};
}

bool checkStrings(string s1, string s2) { return convert(s1) == convert(s2); }
```

## 고생한 점
