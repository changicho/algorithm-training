# A - Who Ate the Cake?

[링크](https://atcoder.jp/contests/abc355/tasks/abc355_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

주어진 2개의 숫자를 이용해 정답을 찾는데 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

상수크기의 공간복잡도를 사용하므로 O(1)의 공간 복잡도를 사용한다.

### 구현

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(1)     |    O(1)     |

입력받은 두 숫자가 같은 경우와 다른 경우를 구별해 구현한다.

```cpp
int solution(int a, int b) {
  if (a == b) return -1;

  unordered_set<int> us;
  us.insert(1);
  us.insert(2);
  us.insert(3);

  us.erase(a);
  us.erase(b);

  return *us.begin();
}
```

## 고생한 점
