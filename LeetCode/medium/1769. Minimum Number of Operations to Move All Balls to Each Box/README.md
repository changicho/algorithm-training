# 1769. Minimum Number of Operations to Move All Balls to Each Box

[링크](https://leetcode.com/problems/minimum-number-of-operations-to-move-all-balls-to-each-box/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 boxes의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N^2)이다.

prefix sum을 이용해 각 경우에 대한 연산을 구할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답에 O(N)의 공간이 필요하다.

prefix sum을 이용할 경우 별도의 공간이 필요하다. 이는 O(N)이다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

0 ~ i번째 까지의 1의 count와 해당 index sum에 대해 prefix sum을 구한다.

이후 현재 index의 왼쪽 부분, 오른쪽 부분에 대해서 1의 갯수와 1의 index들의 합을 prefix sum을 이용해 구할 수 있다.

이후 아래 식을 이용해 1의 index들과 index들의 거리를 구한다.

- abs(indexSum - i \* indexCount)

각 index와 현재 index의 차이를 현재 합에서 빼서 구한다.

이를 모든 index에 대해 반복한다.

```cpp
vector<int> minOperations(string boxes) {
  int size = boxes.size();
  vector<int> answer(size, 0);

  vector<pair<int, int>> prefixes(size + 1);
  // count, index sum
  pair<int, int> cur;
  for (int i = 0; i < size; i++) {
    if (boxes[i] == '1') {
      cur.first++;
      cur.second += i;
    }
    prefixes[i + 1] = cur;
  }

  for (int i = 0; i < size; i++) {
    pair<int, int> left = prefixes[i];
    pair<int, int> right = prefixes[size];
    right.first -= prefixes[i + 1].first;
    right.second -= prefixes[i + 1].second;

    int cur = abs(left.second - i * left.first) +
              abs(right.second - i * right.first);

    answer[i] = cur;
  }
  return answer;
}
```

## 고생한 점
