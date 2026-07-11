# 3532. Path Existence Queries in a Graph I

[링크](https://leetcode.com/problems/path-existence-queries-in-a-graph-i/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

전체 노드의 수를 N이라 하자.

유니온 파인드를 이용해 노드들의 연결을 관리할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

유니온 파인드에 O(N)의 공간 복잡도를 사용한다.

### 유니온 파인드

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(N)     |

각 노드들의 숫자는 오름차순으로 정렬되어있다.

따라서 연속된 두 노드끼리만 연결 가능한지 판단하면 된다.

연속된 노드들 끼리 연결 가능한 지 판단 후 가능하면 연결한다.

이후 각 쿼리마다 두 노드에 연결된 루트노드가 무엇인지 판단한다.

이 때 각 노드마다 순회하며 연결하므로 연결된 그룹들마다 색으로 표현할수도있다.

```cpp
vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
  vector<int> parents(n);
  int color = 1;
  parents[0] = 1;
  for (int i = 0; i < n - 1; i++) {
    if (abs(nums[i] - nums[i + 1]) > maxDiff) {
      color++;
    }

    parents[i + 1] = color;
  }

  vector<bool> answer;
  for (vector<int>& q : queries) {
    bool cur = parents[q[0]] == parents[q[1]];

    answer.push_back(cur);
  }
  return answer;
}
```

## 고생한 점
