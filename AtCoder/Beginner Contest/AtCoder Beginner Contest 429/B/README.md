# B - N - 1

[링크](https://atcoder.jp/contests/abc429/tasks/abc429_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 O(N)이라 하자.

모든 원소의 합을 구하는 데 O(N)의 시간 복잡도를 사용한다.

이후 합에서 M을 뺀 값이 존재하는지 확인하는데 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

합만 저장하는 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(1)     |

```cpp
auto solution(int size, int m, vector<int>& nums) {
  int sum = 0;
  for (int& num : nums) {
    sum += num;
  }

  for (int& num : nums) {
    if (sum - num == m) return true;
  }
  return false;
}
```

## 고생한 점
