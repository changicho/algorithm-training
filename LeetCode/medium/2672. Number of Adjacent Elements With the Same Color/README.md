# 2672. Number of Adjacent Elements With the Same Color

[링크](https://leetcode.com/problems/number-of-adjacent-elements-with-the-same-color/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

원소의 갯수를 N, 쿼리의 갯수를 N라 하자. (두 값은 동일)

각 쿼리를 순회하며 특정 원소의 색을 변경해야 한다.

색이 변경될 때 마다 현재 원소와 인접한 원소들의 색을 비교해야 한다.

이를 이용해 count를 변경할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

색을 칠할 공간이 필요하므로 O(N)의 공간 복잡도를 사용한다.

### one pass, 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     570      |    O(N)     |    O(N)     |

문제 설명이 부족해 이해가 잘 되지 않았다.

단순하게 각 index마다 색을 칠했을 때 양 옆의 색과 연결될 때 count를 증가시키고, 연결이 끊길 때 count를 감소시킨다.

```cpp
vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
  vector<int> colors(n, 0);

  int count = 0;
  vector<int> answer;
  for (vector<int>& q : queries) {
    int index = q[0], color = q[1];

    int left = (index - 1 >= 0) ? colors[index - 1] : 0;
    int right = (index + 1 < n) ? colors[index + 1] : 0;

    if (left != 0 && left == colors[index]) count--;
    if (right != 0 && right == colors[index]) count--;
    colors[index] = color;
    if (left != 0 && left == colors[index]) count++;
    if (right != 0 && right == colors[index]) count++;

    answer.emplace_back(count);
  }
  return answer;
}
```

## 고생한 점
