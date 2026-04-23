# D - (xx)

[링크](https://atcoder.jp/contests/abc454/tasks/abc454_d)

| 난이도 |
| :----: |
|  425   |

## 설계

### 시간 복잡도

입력받은 두 문자열의 크기를 N, M이라 하자.

각 문자열에서 최대한 괄호쌍을 제거 후 둘이 같은지 비교할 수 있다.

이 경우 괄호쌍을 제거하는데 O(N + M)의 시간 복잡도를 사용한다.

### 공간 복잡도

괄호쌍을 제거하는데 stack을 사용할 경우 O(N + M)의 공간 복잡도를 사용한다.

### stack (괄호 쌍)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     102      |  O(N + M)   |  O(N + M)   |

각 문자열에서 조건에 맞춰 괄호 쌍을 최대한 제거한다.

만약 두 문자열이 같다면 문자열 A를 B로 변환할 수 있다.

문바열의 변화를 위해 stack을 사용하며, 괄호를 제거 가능한 조건은 `(xx)` 를 `xx`로 변환하는것이므로 매번 직전 3개의 값과 현재 값을 비교한다.

```cpp
string convert(string& s) {
  string ret = "";

  for (char& c : s) {
    int size = ret.size();
    if (size >= 3) {
      if (c == ')' && ret[size - 1] == 'x' && ret[size - 2] == 'x' &&
          ret[size - 3] == '(') {
        ret.pop_back();
        ret.pop_back();
        ret.pop_back();
        ret.push_back('x');
        ret.push_back('x');

        continue;
      }
    }

    ret.push_back(c);
  }
  return ret;
}

bool solution(string& a, string& b) {
  string ac = convert(a);
  string bc = convert(b);

  bool answer = ac == bc;

  return answer;
}
```

## 고생한 점
