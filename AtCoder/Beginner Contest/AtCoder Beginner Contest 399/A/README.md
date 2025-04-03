# A - Hamming Distance

[링크](https://atcoder.jp/contests/abc399/tasks/abc399_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 문자열의 길이를 N이라 하자.

각 문자열을 순회하며 Hamming Distance를 구하는데 O(N)의 시간이 걸린다.

### 공간 복잡도

다른 문자의 수를 세는 데 O(1)의 공간이 필요하다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

```cpp
int solution(int n, string &s, string &t) {
  int answer = 0;

  for (int i = 0; i < n; i++) {
    if (s[i] != t[i]) {
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
