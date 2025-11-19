# A - Too Many Requests

[링크](https://atcoder.jp/contests/abc429/tasks/abc429_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 수를 N이라 하자.

순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

```cpp
vector<string> solution(int n, int m) {
  vector<string> answer;

  for (int i = 0; i < n; i++) {
    if (i < m) {
      answer.push_back("OK");
    } else {
      answer.push_back("Too Many Requests");
    }
  }

  return answer;
}
```

## 고생한 점
