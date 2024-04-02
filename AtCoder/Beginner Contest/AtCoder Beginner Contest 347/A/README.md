# A - Divisible

[링크](https://atcoder.jp/contests/abc347/tasks/abc347_a)

| 난이도 |
| :----: |
|  100   |

## 설계

### 시간 복잡도

입력받은 배열의 크기를 N이라 하자.

배열의 수를 순회하며 나누어 떨어질 수 있는 경우 몫을 정답 배열에 추가한다.

순회에 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(N)     |    O(N)     |

배열의 수를 순회하며 나누어 떨어질 수 있는 경우 몫을 정답 배열에 추가한다.

```cpp
vector<int> solution(int k, vector<int> &nums) {
  vector<int> answer;

  for (int &num : nums) {
    if (num % k == 0) {
      answer.push_back(num / k);
    }
  }

  return answer;
}
```

## 고생한 점
