# B - Dentist Aoki

[링크](https://atcoder.jp/contests/abc350/tasks/abc350_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 수를 N, 쿼리의 수를 Q라 하자.

hash set을 사용할 경우 O(N + Q)의 시간 복잡도를 사용한다.

삭제된 수만 관리할 경우 O(Q)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set에 O(N)의 공간 복잡도를 사용한다.

### hash set (추가)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |  O(N + Q)   |    O(N)     |

hash set에 수를 저장하고, 쿼리에 따라 수를 삭제하고 추가한다.

```cpp
int solution(int size, vector<int> &queries) {
  unordered_set<int> us;
  for (int i = 1; i <= size; i++) {
    us.insert(i);
  }

  for (int &q : queries) {
    if (us.count(q)) {
      us.erase(q);
    } else {
      us.insert(q);
    }
  }

  return us.size();
}
```

### hash set (삭제)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(Q)     |    O(N)     |

hash set에 삭제된 수만 저장한다.

```cpp
int solution(int size, vector<int> &queries) {
  unordered_set<int> erased;

  for (int &q : queries) {
    if (erased.count(q)) {
      erased.erase(q);
    } else {
      erased.insert(q);
    }
  }

  return size - erased.size();
}
```

## 고생한 점
