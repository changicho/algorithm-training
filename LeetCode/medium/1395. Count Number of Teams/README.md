# 1395. Count Number of Teams

[링크](https://leetcode.com/problems/count-number-of-teams/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 rating의 크기를 N이라 하자.

완전 탐색을 이용할 경우 O(N^3)의 시간 복잡도를 사용한다.

현재 index보다 왼쪽 값들 중 크고 작은 값들의 개수를 구할 수 있다.

이를 모두 구하는데 O(N^2)의 시간 복잡도를 사용한다.

이를 이용해 정답을 구할 경우 O(N^2)의 시간 복잡도가 소요된다.

### 공간 복잡도

각 index마다 왼쪽에 있는 큰 값의 개수, 작은 값의 개수를 저장해야 한다.

이에 O(N)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |   O(N^2)    |    O(N)     |

각 index마다 0~index-1 까지의 index들을 순회하며 현재 index보다 작은 값의 개수, 큰 값의 개수를 구한다.

이를 모두 구한 경우 다음과 같이 정답을 구할 수 있다.

- 현재 index를 i, index 왼쪽을 j라 하자.
- i, j가 문제의 조건을 만족하는 경우 j에 존재하는 값의 갯수 만큼 정답을 증가시킨다.

이를 구현하면 다음과 같다.

```cpp
int numTeams(vector<int>& rating) {
  int size = rating.size();

  vector<int> lowers(size, 0), uppers(size, 0);

  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (rating[j] < rating[i]) {
        lowers[i]++;
      }
      if (rating[j] > rating[i]) {
        uppers[i]++;
      }
    }
  }

  int answer = 0;
  for (int i = 0; i < size; i++) {
    for (int j = 0; j < i; j++) {
      if (rating[j] < rating[i]) {
        answer += lowers[j];
      }
      if (rating[j] > rating[i]) {
        answer += uppers[j];
      }
    }
  }
  return answer;
}
```

## 고생한 점
