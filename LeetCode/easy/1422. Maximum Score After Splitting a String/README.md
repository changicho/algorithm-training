# 1422. Maximum Score After Splitting a String

[링크](https://leetcode.com/problems/maximum-score-after-splitting-a-string/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 문자열 S의 길이를 N이라 하자.

모든 경우를 직접 수행할 경우 O(N^2)의 시간 복잡도를 사용한다.

미리 prefix sum을 계산해두고 사용할 경우 O(N)의 시간 복잡도를 사용한다.

순회를 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

순회하며 count를 갱신할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

s의 모든 1의 갯수를 one이라 하자.

index를 0부터 왼쪽부터 순회하며 0의 갯수를 갱신하며 1의 갯수 또한 감소시킨다.

각 경우마다 정답을 구한다.

```cpp
int maxScore(string s) {
  int size = s.size();

  int zero = 0, one = 0;
  for (int i = 0; i < size; i++) {
    one += s[i] == '1';
  }

  int answer = 0;
  for (int i = 0; i < size - 1; i++) {
    if (s[i] == '0') {
      zero++;
    } else {
      one--;
    }

    answer = max(answer, zero + one);
  }
  return answer;
}
```

## 고생한 점
