# 2657. Find the Prefix Common Array of Two Arrays

[링크](https://leetcode.com/problems/find-the-prefix-common-array-of-two-arrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 A, B의 크기를 N이라 하자.

각 원소는 unique 하므로 순회하며 count를 이용해 풀이할 수 있다.

배열에 count하는 경우 각 경우마다 O(1)의 시간 복잡도가 필요하다.

비트 마스킹을 사용하는 경우 O(log_2(50)) = O(1)의 시간 복잡도가 필요하다.

이 경우 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 수마다 count하는 배열을 만드는 경우 O(N)의 공간 복잡도를 사용한다.

비트 마스크를 이용해 count할 경우 O(1)의 공간 복잡도가 필요하다.

### 카운트

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

왼쪽부터 각 index를 순회하며 배열에 현재까지 나온 수들을 count한다.

이 때 현재 count한 숫자가 2가 되는 경우 common을 증가시킨다.

```cpp
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
  int size = A.size();

  int count[51] = {
      0,
  };

  vector<int> answer(size);
  int common = 0;
  long long aMask = 0, bMask = 0;
  for (int i = 0; i < size; i++) {
    count[A[i]]++;
    if (count[A[i]] == 2) common++;

    count[B[i]]++;
    if (count[B[i]] == 2) common++;

    answer[i] = common;
  }
  return answer;
}
```

### 카운트 & 비트마스크

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

위 방법에서 방문한 수를 비트마스크로 표현한다.

이후 두 마스크의 교집합을 구하고, 이를 이용해 현재까지 나온 수의 개수를 구할 수 있다.

```cpp
vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
  int size = A.size();

  vector<int> answer(size);
  long long aMask = 0, bMask = 0;
  for (int i = 0; i < size; i++) {
    aMask |= (1LL << A[i]);
    bMask |= (1LL << B[i]);

    long long common = aMask & bMask;

    answer[i] = __builtin_popcountll(common);
  }
  return answer;
}
```

## 고생한 점
