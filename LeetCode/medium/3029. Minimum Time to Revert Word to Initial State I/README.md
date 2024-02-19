# 3029. Minimum Time to Revert Word to Initial State I

[링크](https://leetcode.com/problems/minimum-time-to-revert-word-to-initial-state-i/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 word의 길이를 N이라 하자.

각 단계별로 앞에서부터 k개의 문자를 삭제했을 때 word를 직접 만들 수 있는지 직접 구할 경우 O(N^2)의 시간 복잡도를 사용한다.

이 때 유효한 경우만 탐색할 경우 O(N^2 / K)의 시간 복잡도가 소요된다.

KMP 알고리즘을 사용해 두 문자열을 비교할 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

직접 완전 탐색할 경우 O(N)의 공간 복잡도가 필요하다.

KMP 알고리즘을 사용할 경우 O(N)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      2       | O(N^2 / K)  |    O(N)     |

x번 앞에서 k개의 문자를 삭제했을 때 남은 문자열과 word의 앞자리부분이 같은지 검사한다.

```cpp
int minimumTimeToInitialState(string word, int k) {
  int size = word.size();

  for (int i = 1; i <= size / k; i++) {
    if (word.substr(k * i) == word.substr(0, word.length() - k * i)) {
      return i;
    }
  }

  return ceil(size / (double)k);  // (size - pI + k - 1) / k;
}
```

### KMP

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

KMP 알고리즘을 사용해 pattern index 배열을 만든다.

이후 pattern index 배열을 이용해 최소한의 문자를 삭제해야 하는 경우를 구할 수 있다.

```cpp
int minimumTimeToInitialState(string word, int k) {
  int size = word.size();
  vector<int> patternIndexes(size, 0);

  int pI = 0;
  for (int i = 1; i < size; i++) {
    while (pI > 0 && word[i] != word[pI]) {
      pI = patternIndexes[pI - 1];
    }

    if (word[i] == word[pI]) {
      pI++;
      patternIndexes[i] = pI;
    }
  }

  while (pI > 0 && (size - pI) % k > 0) {
    pI = patternIndexes[pI - 1];
  }

  return ceil((size - pI) / (double)k);  // (size - pI + k - 1) / k;
}
```

## 고생한 점
