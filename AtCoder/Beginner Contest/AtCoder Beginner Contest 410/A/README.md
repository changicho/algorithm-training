# A - G1

[링크](https://atcoder.jp/contests/abc410/tasks/abc410_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

배열의 길이를 N이라 하자.

순회를 이용해 k보다 큰 값을 찾는데 O(N) 시간이 걸린다.

### 공간 복잡도

O(1)로 상수 공간을 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

```cpp
int solution(int size, vector<int> &horses, int k) {
  int answer = 0;

  for (int &h : horses) {
    if (h >= k) {
      answer++;
    }
  }

  return answer;
}
```

## 고생한 점
