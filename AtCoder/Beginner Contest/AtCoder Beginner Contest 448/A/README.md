# A - chmin

[링크](https://atcoder.jp/contests/abc448/tasks/abc448_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자. 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

```cpp
auto solution(int size, int x, vector<int>& nums) {
  vector<int> answer;

  for (int& num : nums) {
    if (num < x) {
      x = num;
      answer.push_back(1);
    } else {
      answer.push_back(0);
    }
  }

  return answer;
}
```

## 고생한 점
