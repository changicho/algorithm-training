# C - Keys

[링크](https://atcoder.jp/contests/abc356/tasks/abc356_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

키의 숫자를 N, 테스트의 숫자를 M, 각 테스트마다 키의 총 갯수를 C라 하자.

키가 유효한지 아닌지에 2^N가지의 경우의 수가 존재한다.

각 경우의 수 마다 모든 테스트가 valid한지 검사하는 데 O(2^N \* C)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 상수크기의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      34      | O(2^N \* C) |    O(1)     |

각 키마다 valid, invalid한 경우가 존재한다.

모든 경우를 비트 연산으로 탐색하며, 각 과정마다 test를 직접 수행해보고 결과와 맞는지 확인한다.

```cpp
struct Test {
  vector<int> inserted;
  char result;
};

int solution(int n, int k, vector<Test> &tests) {
  // do something
  int answer = 0;

  for (int bit = 0; bit < (1 << n); bit++) {
    bool isPossible = true;

    for (Test &test : tests) {
      int inserted = 0;

      for (int &key : test.inserted) {
        if (bit & (1 << (key - 1))) {
          inserted++;
        }
      }

      if (inserted >= k && test.result == 'o') {
        continue;
      } else if (inserted < k && test.result == 'x') {
        continue;
      } else {
        isPossible = false;
        break;
      }
    }

    if (isPossible) {
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
