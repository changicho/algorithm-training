# 3160. Find the Number of Distinct Colors Among the Balls

[링크](https://leetcode.com/problems/find-the-number-of-distinct-colors-among-the-balls/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

쿼리의 갯수를 N, 노드의 갯수를 M이라 하자. (N <= 10^5, M <= 10^9)

노드마다 색을 저장하는데 배열을 사용할 경우 O(M)의 시간 복잡도가 필요하다. 이는 제한시간 내에 불가능하다.

따라서 hash map을 이용하며 쿼리를 순회하며 노드를 갱신한다.

이 때 O(N)의 시간 복잡도가 필요하다.

### 공간 복잡도

각 노드를 저장할 때 색을 저장하는데 hash map을 이용한다.

이에 O(N)의 공간 복잡도가 필요하다.

### hash map count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      99      |    O(N)     |    O(N)     |

각 쿼리마다 노드에 색을 칠하며, 각 색마다의 갯수를 hash map에 저장한다.

이 때 이전 색의 count를 감소시키며 count가 0인 경우 hash map에서 제거해 현재 칠해진 색의 갯수를 바로 구한다.

limit의 수가 매우 크므로 hash map을 이용해 색이 변하는 노드만을 저장한다.

```cpp
vector<int> queryResults(int limit, vector<vector<int>>& queries) {
  unordered_map<int, int> balls;

  unordered_map<int, int> counts;
  vector<int> answer;
  for (vector<int>& q : queries) {
    int key = q[0], color = q[1];
    int before = balls[key];

    if (before != 0) {
      counts[before]--;
      if (counts[before] == 0) {
        counts.erase(before);
      }
    }

    balls[key] = color;
    counts[color]++;

    answer.push_back(counts.size());
  }

  return answer;
}
```

## 고생한 점
