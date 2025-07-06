# 3307. Find the K-th Character in String Game II

[링크](https://leetcode.com/problems/find-the-k-th-character-in-string-game-ii/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

입력받은 수를 K, 연산의 갯수를 N이라 하자.

문자열의 길이는 연산 별로 2배씩 증가한다.

각 단계별로 영향을 주는 문자와 변하는 값을 순회를 이용해 구할 경우 O(log_2(K))의 시간 복잡도를 가진다.

### 공간 복잡도

순회에 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(K)) |    O(1)     |

각 연산에 따라 문자열의 길이는 2배씩 늘어나며, 증가하는 문자들이 1씩 증가하는 경우와 그렇지 않은 경우가 존재한다.

현재 K번째 문자에 영향을 주는 문자를 순회하며 찾고, 해당 문자가 얼마나 변했는 지를 계산한다.

```cpp
char kthCharacter(long long k, vector<int>& operations) {
  int diff = 0;

  while (k > 1) {
    int step = log2(k);

    long long half = 1LL << step;
    if (half == k) {
      half /= 2;
      step--;
    }

    k -= half;
    if (operations[step]) {
      diff++;
    }
  }

  return 'a' + (diff % 26);
}
```

## 고생한 점
