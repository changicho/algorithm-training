# A - Adjacent Product

[링크](https://atcoder.jp/contests/abc346/tasks/abc346_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

연이은 값의 곱을 구하는 데 순회를 사용하면 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정답 배열을 생성하는 데 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

입력받은 배열 중 연이은 원소의 곱을 구한다.

```cpp
vector<int> solution(vector<int> &arr) {
  int size = arr.size();

  vector<int> ret;
  for (int i = 0; i < size - 1; i++) {
    ret.push_back(arr[i] * arr[i + 1]);
  }
  return ret;
}
```

## 고생한 점
