# Problem A2: Consecutive Cuts - Chapter 2

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/A2)

| 난이도 |
| :----: |
| 16 pt  |

## 설계

### 시간 복잡도

A, B에서 중복되는 원소가 생겼다.

A와 B는 서로의 순열이다. 따라서 KMP알고리즘을 이용해 패턴을 찾고 이를 이용해 정답을 구할 수 있다.

이 경우 패턴 검색에 O(N)의 시간 복잡도를 사용한다.

이후 패턴의 시작 index들을 순회하는데 최대 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

KMP 알고리즘에 O(N)의 공간 복잡도를 사용한다.

### KMP 알고리즘

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

A, B는 서로의 순열이다.

A에서 B를 생성해야 하며 즉 B에서 A의 시작점들의 후보를 찾아야한다.

이를 위해 KMP알고리즘을 사용한다.

B를 복제해 B뒤에 이어붙인다. 이는 카드를 섞는 행위가 원형 큐의 형태와 같기 때문에 2배로 복제하는 경우 B에서 A를 찾을 수 있다.

이후 KMP알고리즘을 이용해 B에서 A의 시작점들을 검색한다.

이후 각 시작점과 k에 대해서 정답으로 생성가능한지 판별한다.

- 만약 k가 0인 경우 A, B는 같아야 한다.
- 만약 k가 1인 경우 A와 B는 달라야 한다.
- 만약 N이 2인 경우는 k의 종류에 따라 다르다.
  - k가 짝수 : A == B (순서는 동일)
  - k가 홀수 : A != B (순서는 동일)
- 그 외의 경우는 가능하다.

이를 이용해 구현한다.

```cpp
bool check(vector<int> &cards, vector<int> &toBe, int start, int k) {
  int size = cards.size();
  if (k == 0 && start != 0) {
    return false;
  }
  if (k == 1 && start == 0) {
    return false;
  }
  if (size == 2) {
    if (start == 1 && k % 2 == 1) {
      return true;
    }
    if (start == 0 && k % 2 == 0) {
      return true;
    }
    return false;
  }
  return true;
}

bool solution(int size, int k, vector<int> &cards, vector<int> &toBe) {
  for (int i = 0; i < size; i++) {
    toBe.push_back(toBe[i]);
  }

  // use KMP
  vector<int> patternIndexArr(size, 0);
  for (int curIdx = 1, patternIdx = 0; curIdx < size; curIdx++) {
    while (patternIdx > 0 && cards[curIdx] != cards[patternIdx]) {
      patternIdx = patternIndexArr[patternIdx - 1];
    }
    if (cards[curIdx] == cards[patternIdx]) {
      patternIdx++;
      patternIndexArr[curIdx] = patternIdx;
    }
  }

  vector<int> starts;
  for (int lineIdx = 0, patternIdx = 0; lineIdx < 2 * size; lineIdx++) {
    while (patternIdx > 0 && toBe[lineIdx] != cards[patternIdx]) {
      patternIdx = patternIndexArr[patternIdx - 1];
    }

    if (toBe[lineIdx] == cards[patternIdx]) {
      if (patternIdx == size - 1) {
        starts.push_back(lineIdx - size + 1);

        patternIdx = patternIndexArr[patternIdx];
      } else {
        patternIdx++;
      }
    }
  }

  // 1 ~ N-1
  for (int &start : starts) {
    if (start >= size) continue;
    bool ret = check(cards, toBe, start, k);

    if (!ret) continue;
    return true;
  }

  return false;
}
```

## 고생한 점
