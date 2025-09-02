# A - Misdelivery

[링크](https://atcoder.jp/contests/abc421/tasks/abc421_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

방의 갯수를 N이라 하자. 배열을 저장하는데 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

배열에 O(N)의 공간 복잡도를 사용한다.

### 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

```cpp
auto solution(int size, vector<string> &rooms, int x, string &y) {
  return rooms[x - 1] == y;
}
```

## 고생한 점
