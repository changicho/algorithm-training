# 135. Candy

[링크](https://leetcode.com/problems/candy/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

ratings의 갯수를 N이라 하자.

각 index는 양옆의 rating에 따라 값이 정해진다.

rating이 적은 index부터 순회하며 정답을 구할 수 있으며, 이 경우 heap을 사용해 O(N \* log_2(N))의 시간 복잡도를 사용한다.

두개의 배열을 이용해 정답을 구할 수 있다. 이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

힙을 사용하는 경우 O(N)의 공간 복잡도를 사용한다.

두개의 배열을 사용하는 경우 모두 O(N)의 공간 복잡도를 사용한다.

### heap

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     104      | O(N \* log_2(N)) |    O(N)     |

각 rating은 양옆의 rating에 따라서 캔디의 수를 정해야 한다.

우선순위가 낮은 경우부터 비교해 값을 완성하고 (캔디의 수), 이후 영향을 받는 rating이 높은 값들을 채워넣는다.

이를 구현하면 다음과 같다.

```cpp
struct Data {
  int index, rating;

  bool operator<(const Data &b) const { return rating > b.rating; }
};

int candy(vector<int> &ratings) {
  int size = ratings.size();
  vector<int> candies(size, 1);

  priority_queue<Data> pq;

  for (int i = 0; i < size; i++) {
    pq.push({i, ratings[i]});
  }

  while (!pq.empty()) {
    Data cur = pq.top();
    pq.pop();

    int left = cur.index - 1, right = cur.index + 1;

    if (0 <= left) {
      if (ratings[left] < cur.rating && candies[left] >= candies[cur.index]) {
        candies[cur.index] = candies[left] + 1;
      }
    }
    if (right < size) {
      if (ratings[right] < cur.rating &&
          candies[right] >= candies[cur.index]) {
        candies[cur.index] = candies[right] + 1;
      }
    }
  }

  int count = 0;
  for (int &c : candies) {
    count += c;
  }

  return count;
}
```

### two array

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(N)     |    O(N)     |

각 rating은 양옆의 rating에 따라서 캔디의 수를 정해야 한다.

따라서 모든 index에 대해서 왼쪽에서 봤을때의 캔디의 수, 오른쪽에서 봤을때의 캔디의 수를 배열에 저장한다.

이후 두 배열을 이용해서, 두 조건을 만족하기 위해선 같은 index일때 더 큰 값을 골라야 한다.

이를 더해 정답을 구한다.

```cpp
int candy(vector<int> &ratings) {
  int size = ratings.size();

  vector<int> fromLeft(size, 1), fromRight(size, 1);
  for (int i = 0; i < size; i++) {
    int rIdx = size - 1 - i;

    if (0 <= i - 1 && ratings[i - 1] < ratings[i]) {
      fromLeft[i] = fromLeft[i - 1] + 1;
    }
    if (rIdx + 1 < size && ratings[rIdx] > ratings[rIdx + 1]) {
      fromRight[rIdx] = fromRight[rIdx + 1] + 1;
    }
  }

  int count = 0;
  for (int i = 0; i < size; i++) {
    count += max(fromLeft[i], fromRight[i]);
  }
  return count;
}
```

## 고생한 점
