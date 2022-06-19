# 2305. Fair Distribution of Cookies

[링크](https://leetcode.com/problems/fair-distribution-of-cookies/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

cookies의 크기를 N, 입력받은 자식의 숫자를 K라고 하자.

모든 경우를 재귀호출 등으로 탐색할 경우 O(K^N)의 시간 복잡도를 사용한다.

이 과정에서 백트래킹을 이용해 이를 최적화 할 수 있다.

### 공간 복잡도

재귀호출로 탐색할 경우 O(N)의 call stack의 공간 복잡도를 사용한다.

각 children의 쿠키의 합을 저장하는 데 O(K)의 공간 복잡도를 사용한다.

따라서 총 공간 복잡도는 O(N + K)이다.

### 백트래킹

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |   O(K^N)    |  O(N + K)   |

각 cookie에 대해서 현재 cookie를 어느 자식에게 줄지에 대해 DFS로 모두 탐색한다.

이 경우 대략 K^N가지의 경우의 수가 발생한다.

맨 마지막 쿠키를 분배한 뒤에는 각 자식들이 받은 쿠키들 중에 제일 큰 값이 정답의 후보가 될 수 있다.

이 값이 이전 정답보다 작은 지 판단한다.

이 때 만약 현재 쿠키를 자식에게 줬을 때 해당 쿠키가 처음 나눠주는 쿠키인 경우, 해당 쿠키에 대한 탐색을 더이상 수행하지 않아도 된다.

이는 이 쿠키를 다른 자식(쿠키를 받은적이 없는)에게 넘겨주는 경우가 이미 탐색한 경우와 결과가 똑같기 때문이다.

이를 이용해 백트래킹을 수행한다.

```cpp
int answer = INT_MAX;

void recursive(vector<int> &cookies, int index, vector<int> &children) {
  int size = cookies.size();
  int k = children.size();

  if (size == index) {
    int maximum = children.front();

    for (int &n : children) {
      maximum = max(maximum, n);
    }

    answer = min(maximum, answer);
    return;
  }

  for (int i = 0; i < k; i++) {
    children[i] += cookies[index];

    recursive(cookies, index + 1, children);

    children[i] -= cookies[index];
    if (children[i] == 0) break;
  }
}

int distributeCookies(vector<int> &cookies, int k) {
  int size = cookies.size();

  int sum = 0;
  for (int &c : cookies) {
    sum += c;
  }

  vector<int> children(k, 0);

  recursive(cookies, 0, children);

  return answer;
}
```

## 고생한 점
