# B. Polycarp Writes a String from Memory

[링크](https://codeforces.com/contest/1702/problem/B)

| 난이도 |
| :----: |
|        |

## 설계

### 시간 복잡도

문자열 S의 길이를 L이라 하자.

S를 순회하며 hash set을 이용해 2글자로만 구성할 수 있는 가장 큰 subString들을 찾는다.

이 경우 O(L)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set을 이용해 현재 subString의 문자의 종류를 저장한다.

이 경우 O(1)의 공간 복잡도를 사용한다.

### 문자 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(L)     |    O(1)     |

각 문자를 순회하며 hash set에 현재 문자를 저장한다.

이후 hash set의 크기가 3이 되는 경우 days를 증가시키고 hash set을 초기화한다.

이를 모든 문자를 방문하며 반복한다.

```cpp
int solution(string &s) {
  unordered_set<char> us;
  int days = 1;
  for (char &c : s) {
    us.insert(c);
    if (us.size() > 3) {
      days++;
      us.clear();
      us.insert(c);
    }
  }
  return days;
}
```

## 고생한 점
