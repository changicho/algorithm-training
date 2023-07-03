# 1601. Maximum Number of Achievable Transfer Requests

[링크](https://leetcode.com/problems/maximum-number-of-achievable-transfer-requests/description/)

| 난이도 |
| :----: |
|  Hard  |

## 설계

### 시간 복잡도

노드의 수를 N, 이동하고자 하는 간선의 수를 M이라 하자. (N <= 20, M <= 16)

각 간선마다 해당 간선을 적용할수도 안할수도 있다. 모든 경우를 탐색할 경우 O(2^M)의 시간 복잡도를 사용한다.

이후 마지막 과정마다 유효한 정답인지 판단하는데 각 노드에서 들어오고 빠져나가는 간선의 수를 세서 판단할 수 있다.

이를 직접 판단할 경우 O(N)의 시간 복잡도를 사용한다.

각 이동시마다 노드의 들어오고 빠져나가는 수가 같은지 갱신할 경우 O(1)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(2^M)이다.

### 공간 복잡도

DFS를 이용해 모든 경우를 탐색할 경우 O(M)의 공간 복잡도를 사용한다.

각 노드별로 들어오고 빠져나가는 간선의 수를 세는 경우 O(N)의 공간 복잡도를 사용한다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|    O(2^M)    |   O(2^M)    |  O(N + M)   |

각 request에 대해 해당 request를 수행할지 말지 결정하는 모든 경우를 탐색한다.

이 때 최종적으로 모든 노드에 대해 유효한지 판단하기 위해 각 노드별로 빠져나간 인원과 들어온 인원을 count한다.

각 request 조합에 대해서 각 노드별로 들어온, 빠져나간 인원의 차가 모두 0인지를 판단한다. 모두 0 인경우 유효한 경우이며 정답을 갱신한다.

노드의 수가 20개까지이므로 비트마스크를 이용해 각 노드별로 들어온, 빠져나간 인원의 차가 0인지를 판단할 수 있다.

이를 구현하면 다음과 같다.

```cpp
vector<vector<int>> requests;
int inDegrees[21] = {
    0,
};

int answer = 0;

int updateBits(int bits, int node) {
  if (inDegrees[node] == 0) {
    bits &= ~(1 << node);
  } else {
    bits |= (1 << node);
  }
  return bits;
}

void recursive(int n, int index, int reqCount, int bits) {
  if (index == requests.size()) {
    if (bits != 0) return;

    answer = max(answer, reqCount);
    return;
  }

  int from = requests[index][0], to = requests[index][1];

  // use request case
  inDegrees[from]--;
  inDegrees[to]++;

  bits = updateBits(bits, from);
  bits = updateBits(bits, to);

  recursive(n, index + 1, reqCount + 1, bits);
  inDegrees[from]++;
  inDegrees[to]--;

  bits = updateBits(bits, from);
  bits = updateBits(bits, to);

  // ignore request case
  recursive(n, index + 1, reqCount, bits);
}

int maximumRequests(int n, vector<vector<int>>& requests) {
  this->requests = requests;
  int bits = 0;
  recursive(n, 0, 0, bits);

  return answer;
}
```

## 고생한 점
