# C - Truck Driver

[링크](https://atcoder.jp/contests/abc430/tasks/abc430_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

문자열의 길이를 N이라 하자.

각 index를 시작점으로 하는 가능한 경우의 수를 구해야 한다.

이분 탐색을 이용해 만족하는 조건을 빠르게 구하는 경우 O(N \* log_2(N))의 시간 복잡도를 사용할 수 있다.

이 때 prefix sum을 이용해 구간합을 빠르게 구한다.

### 공간 복잡도

prefix sum에 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      25      | O(N \* log_2(N)) |    O(N)     |

다음과 같은 탐색을 진행한다.

현재 구간 left ~ right에 대해 탐색한다.

left를 왼쪽부터 탐색을 진행하며 가능한 right쌍들에 대해 정답에 더한다.

이 때 right구간은 다음과 같이 구할 수 있다.

- 현재 구간에서 'a'의 갯수가 A이상이 되는 최초 index
- 현재 구간에서 'b'의 갯수가 B이상이 되는 최초 index

이 때 두 index의 차이 만큼 가능한 right의 갯수가 된다.

이 때 각 구간에서 A, B의 갯수에 대한 index를 이분탐색으로 구한다.

```cpp
auto solution(int size, int a, int b, string& s) {
  vector<int> prefixSumA(size, 0);
  vector<int> prefixSumB(size, 0);

  if (s[0] == 'a') {
    prefixSumA[0] = 1;
  } else {
    prefixSumB[0] = 1;
  }
  for (int i = 1; i < size; i++) {
    prefixSumA[i] = prefixSumA[i - 1] + (s[i] == 'a');
    prefixSumB[i] = prefixSumB[i - 1] + (s[i] == 'b');
  }

  long long answer = 0;

  for (int left = 0; left < size; left++) {
    int needA = a;
    int needB = b;
    // add prefix of 0 ~ (left-1)
    if (left > 0) {
      needA += prefixSumA[left - 1];
      needB += prefixSumB[left - 1];
    }

    // find left ~ right
    // that right part remain 'a'
    // [] is right part
    // xxxxxxb[aaaa...]
    int idx1 = lower_bound(prefixSumA.begin(), prefixSumA.end(), needA) -
               prefixSumA.begin();
    int idx2 = lower_bound(prefixSumB.begin(), prefixSumB.end(), needB) -
               prefixSumB.begin();

    // count idx1 ~ idx2 cases
    if (idx1 < idx2) {
      answer += (idx2 - idx1);
    }
  }

  return answer;
}
```

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(1)     |

위 방법을 사용해 left를 고정한 후

a의 갯수가 A이상인 최초 인덱스인 rightA와 b의 갯수가 B이상인 최초 인덱스인 rightB를 투 포인터로 구한다.

이후 유요한 경우 rightB - rightA 만큼 정답에 더한다.

```cpp
auto solution(int size, int a, int b, string& s) {
  long long answer = 0;

  int left = -1, rightA = -1, rightB = -1;
  int aCount = 0;
  int bCount = 0;

  for (; left < size; left++) {
    if (left >= 0) {
      if (s[left] == 'a') {
        aCount--;
      } else {
        bCount--;
      }
    }

    while (rightA < size && aCount < a) {
      if (s[rightA + 1] == 'a') {
        aCount++;
      }
      rightA++;
    }
    while (rightB < size && bCount < b) {
      if (s[rightB + 1] == 'b') {
        bCount++;
      }
      rightB++;
    }

    if (rightB > rightA) {
      answer += rightB - rightA;
    }
  }

  return answer;
}
```

## 고생한 점
