# Problem A1: Consecutive Cuts - Chapter 1

[링크](https://www.facebook.com/codingcompetitions/hacker-cup/2022/round-1/problems/A1)

| 난이도 |
| :----: |
| 10 pt  |

## 설계

### 시간 복잡도

A, B의 크기를 N이라 하자.

각 배열의 원소는 유일하므로, A 원소의 시작점을 B에서 찾고 순서가 맞는지 판단하면 된다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

순서를 판단하는데 별도의 vector를 사용하지 않는다.

따라서 공간 복잡도는 O(1)이다.

### 시작점 찾기

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(1)     |

카드뭉치에서 카드를 자르고 섞는 행위는 원형 큐와 동일하다.

따라서 기존 카드의 순서가 어긋날 수 없다.

만약 k가 0인 경우 A, B는 같아야 한다.

만약 k가 1인 경우 A와 B는 달라야 한다.

만약 N이 2인 경우는 k의 종류에 따라 다르다.

- k가 짝수 : A == B (순서는 동일)
- k가 홀수 : A != B (순서는 동일)

그 외의 경우는 N이 1인 경우는 순서를 변경하는 것이 불가능하다.

(문제에서 1 ~ (N-1)개의 카드를 섞을 수 있다.)

N이 3 이상인 경우 k개 2 이상일 때 원래 순서로 돌아갈 수 있다.

- sum(k1 + k2 ...) % N = N으로 구성하면 된다.

이를 구현하면 다음과 같다.

```cpp
int findIdx(vector<int> &a, int target) {
  for (int i = 0; i < a.size(); i++) {
    if (a[i] == target) return i;
  }
  return -1;
}

bool solution(int size, int k, vector<int> &cards, vector<int> &toBe) {
  if (k == 0) {
    for (int i = 0; i < size; i++) {
      if (cards[i] != toBe[i]) return false;
    }
    return true;
  }

  // 1 ~ N-1
  int starts = findIdx(toBe, cards.front());
  if (k == 0 && starts != 0) {
    return false;
  }
  if (k == 1 && starts == 0) {
    return false;
  }
  if (size == 2) {
    if (starts == 1 && k % 2 == 1) {
      return true;
    }
    if (starts == 0 && k % 2 == 0) {
      return true;
    }
    return false;
  }
  for (int i = 0; i < size; i++) {
    int j = (starts + i) % size;
    if (cards[i] != toBe[j]) return false;
  }

  return true;
}
```

## 고생한 점
