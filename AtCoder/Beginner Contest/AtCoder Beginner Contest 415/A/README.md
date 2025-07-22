# A - Unsupported Type

[링크](https://atcoder.jp/contests/abc415/tasks/abc415_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회를 이용해 원소를 확인하는데 O(N)의 시간이 걸린다.

### 공간 복잡도

O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

```cpp
bool solution(int size, vector<int> &arr, int x) {
  for (int &num : arr) {
    if (num == x) return true;
  }

  return false;
}
```

## 고생한 점
