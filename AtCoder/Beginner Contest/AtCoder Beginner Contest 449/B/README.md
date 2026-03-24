# B - Deconstruct Chocolate

[링크](https://atcoder.jp/contests/abc449/tasks/abc449_b)

| 난이도 |
| :----: |
|  200   |

## 설계

### 시간 복잡도

입력받은 쿼리의 수를 Q라 하자.

각 쿼리를 순회하며 시뮬레이션을 수행한다.

길이에 대해 직접 값을 구하는 경우 O(1)의 시간 복잡도를 사용한다. 이를 쿼리에 대해 반복하는데 O(Q)의 시간 복잡도를 가진다.

### 공간 복잡도

정답에 O(Q)의 공간 복잡도를 가진다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      1       |    O(Q)     |    O(Q)     |

현재 직사각형의 너비와 높이가 존재할때, 각 쿼리마다 마지막 마디들을 삭제한다.

이에 O(1)의 시간 복잡도를 사용한다.

```cpp
vector<int> solution(int height, int width, int size,
                     vector<pair<int, int>>& queries) {
  vector<int> answer;

  for (pair<int, int>& q : queries) {
    int type = q.first;
    int index = q.second;

    if (type == 1) {
      // row

      int cur = width * index;
      answer.push_back(cur);

      height -= index;

    } else {
      // col

      int cur = height * index;
      answer.push_back(cur);

      width -= index;
    }
  }

  return answer;
}
```

## 고생한 점
