# C - Uniqueness

[링크](https://atcoder.jp/contests/abc398/tasks/abc398_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

사람의 수를 N이라 하자.

각 사람마다 중복되지 않은 수 중 가장 큰 수의 index를 찾아야 한다.

hash map을 사용해 count한 경우 O(N)의 시간 복잡도가 소요된다.

이후 순회하며 중복되지 않은 수 중 가장 큰 수의 index를 찾는데 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

hash map에 O(N)의 공간 복잡도가 필요하다.

### counting

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      68      |    O(N)     |    O(N)     |

각 사람이 가진 숫자를 count한다.

이후 왼쪽부터 순회하며 중복되지 않은 수 중 가장 큰 수의 index를 찾는다.

```cpp
int solution(int size, vector<int> &people) {
  unordered_map<int, int> count;

  for (int &num : people) {
    count[num]++;
  }

  int answer = -1;
  int answerTarget = -1;

  for (int i = 0; i < size; i++) {
    if (count[people[i]] == 1) {
      if (answerTarget < people[i]) {
        answerTarget = people[i];
        answer = i + 1;
      }
    }
  }

  return answer;
}
```

## 고생한 점
