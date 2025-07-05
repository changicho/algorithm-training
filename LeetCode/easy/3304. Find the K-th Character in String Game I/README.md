# 3304. Find the K-th Character in String Game I

[링크](https://leetcode.com/problems/find-the-k-th-character-in-string-game-i/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받은 수를 K라 하자.

시뮬레이션을 사용할 경우 O(K \* log_2(K))의 시간 복잡도를 가진다.

순회를 사용할 경우 O(log_2(K))의 시간 복잡도를 가진다.

### 공간 복잡도

직접 문자열을 생성할 경우 O(K)의 공간 복잡도를 가진다.

순회를 사용할 경우 O(1)의 공간 복잡도를 가진다.

### 완전 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      1       | O(K \* log_2(K)) |    O(K)     |

직접 문자열을 생성하며 K번째 문자를 찾는다.

```cpp
char kthCharacter(int k) {
  string cur = "a";

  while (cur.size() < k) {
    string next = cur;
    for (char &c : next) {
      c++;
      if (c > 'z') c = 'a';
    }
    cur = cur + next;
  }

  return cur[k - 1];
}
```

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       | O(log_2(K)) |    O(1)     |

각 단계마다 문자열의 길이는 2배씩 늘어난다.

K에 영향을 주는 문자는 제일 처음 문자열 "a"이다.

따라서 "a"가 K번째 문자열이 될 때 까지 문자열의 길이를 늘려가며 변화시킨다.

각 단계마다 문자열이 하나씩 증가하므로 이를 이용해 정답을 구한다.

```cpp
char kthCharacter(int k) {
  int diff = 0;

  while (k > 1) {
    int half = 1 << int(log2(k));
    if (half == k) {
      half /= 2;
    }

    k -= half;
    diff++;
  }
  return 'a' + diff;
}
```

## 고생한 점
