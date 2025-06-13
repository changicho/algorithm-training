# 3577. Count the Number of Computer Unlocking Permutations

[링크](https://leetcode.com/problems/count-the-number-of-computer-unlocking-permutations/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 complexity의 크기를 N이라 하자.

각 permutation에 대해 모두 탐색할 경우 O(N!)의 시간 복잡도를 가지게 된다.

이는 제한시간 내에 불가능하다.

문제 조건에 따라 탐욕 알고리즘을 사용한 뒤 팩토리얼을 이용해 경우의 수를 구할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

팩토리얼을 구하는데 O(1)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘 & 팩토리얼

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

조건을 만족하지 않는 permutation이 생성되는 경우는 다음과 같다.

첫번째 값으로 다른 컴퓨터를 해킹하지 못하는 경우

- 첫번째 값보다 작은 값이 있는 경우
- 첫번째 값과 같은 값이 있는 경우

(각 컴퓨터를 특정 순서로 해킹할 때) 첫번째 컴퓨터를 이용해 다른 컴퓨터를 해킹할 수 있으면 된다. 이를 이용해 모든 permutation을 생성할 수 있다.

따라서 첫번째 컴퓨터로 해킹 불가능한 경우가 있는지 우선 판단한다.

이후 남은 N-1 개의 컴퓨터를 이용해 permutation을 생성하는 경우의 수는 (N-1)! 이다.

```cpp
int countPermutations(vector<int>& complexity) {
  const int MOD = 1e9 + 7;

  int size = complexity.size();

  int first = complexity[0];

  long long answer = 1;
  for (int i = 1; i < size; i++) {
    int num = complexity[i];

    if (num <= first) return 0;

    answer *= i;
    answer %= MOD;
  }

  return answer;
}
```

## 고생한 점
