# 2094. Finding 3-Digit Even Numbers

[링크](https://leetcode.com/problems/finding-3-digit-even-numbers/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열 digits의 크기를 N이라 하자.

각 수의 자리수를 세고 100 ~ 999의 수를 만들 수 있는지 판단한다.

이에 따라 O(N)으로 해결할 수 있다.

### 공간 복잡도

각 자리수와 정답에 O(1)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

100부터 999까지의 수를 만들 수 있는지 판단한다.

각 자리수를 digits를 이용해 만들 수 있는지 판단한다.

```cpp
vector<int> findEvenNumbers(vector<int>& digits) {
  int size = digits.size();

  int counts[10] = {
      0,
  };
  for (int& d : digits) {
    counts[d]++;
  }
  vector<int> answer;

  for (int i = 1; i <= 9; i++) {
    if (counts[i] - 1 < 0) continue;
    counts[i]--;

    for (int j = 0; j <= 9; j++) {
      if (counts[j] - 1 < 0) continue;
      counts[j]--;

      for (int k = 0; k <= 9; k += 2) {
        if (counts[k] - 1 < 0) continue;
        counts[k]--;

        int cur = i * 100 + j * 10 + k;
        answer.push_back(cur);

        counts[k]++;
      }
      counts[j]++;
    }
    counts[i]++;
  }

  return answer;
}
```

## 고생한 점
