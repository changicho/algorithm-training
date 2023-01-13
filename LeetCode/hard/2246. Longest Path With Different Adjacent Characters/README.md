# 2246. Longest Path With Different Adjacent Characters

[링크](https://leetcode.com/problems/longest-path-with-different-adjacent-characters/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

트리의 노드의 갯수를 N이라 하자. 간선의 갯수는 N-1개 이다.

각 노드를 DFS로 순회하며 방문한 자식노드들을 서브트리의 루트로 하는 최대길이 path를 반환받으며 계산할 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

DFS로 순회하는 데 최대 O(N)의 공간 복잡도를 사용한다.

입력받은 edge 정보를 그래프로 변환하는데 O(N)의 공간 복잡도를 사용한다.

### DFS

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     424      |    O(N)     |    O(N)     |

각 노도들을 루트에서부터 DFS로 방문한다.

이 때 각 호출의 반환값으로 현재 노드를 root로 하는 서브트리 중 한쪽 방향으로의 가장 긴 값을 반환하자.

현재 서브트리에서 만들 수 있는 정답의 경우는 다음 3가지이다. (자식 노드와 다른 char을 가지는 path의 수에 따라)

- 자식 노드에서 가능한 path가 2가지 이상 : 가장 긴 path 가지를 선택
  - leftPart + cur + rightPart 로 구성
- 자식 노드에서 가능한 path가 1가지 : 현재 노드 + path
- 자식 노드에서 가능한 path가 없음 : 현재 노드만 가능

여기서 첫번째 경우는 반환값으로 사용할 수 없으므로, 각 경우마다 방문하며 다음 세가지 경우에 대해 정답을 갱신한다.

이를 이용해 DFS로 모든 노드를 방문하며 정답을 갱신한다.

여기서 가장 큰 값 2가지만 필요하므로 자식 노드를 방문과 동시에 값을 갱신한다. 이 경우 별도의 정렬에 시간 복잡도를 사용하지 않는다.

```cpp
vector<vector<int>> children;
string s;
int answer = 1;

int recursive(int node) {
  // leftPath + cur + rightPath
  int first = 0, second = 0;
  for (int& child : children[node]) {
    int curLen = recursive(child);

    if (s[child] != s[node]) {
      if (curLen > first) {
        second = first;
        first = curLen;
      } else if (curLen > second) {
        second = curLen;
      }
    }
  }

  answer = max(answer, first + second + 1);

  return first + 1;
}

int longestPath(vector<int>& parent, string s) {
  int size = parent.size();

  this->s = s;

  children.resize(size);
  for (int n = 1; n < size; n++) {
    children[parent[n]].push_back(n);
  }

  recursive(0);

  return answer;
}
```

## 고생한 점
