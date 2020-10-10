# 10999. 구간 합 구하기 2

[링크](https://www.acmicpc.net/problem/10999)

|   난이도    | 정답률(\_%) |
| :---------: | :---------: |
| Platinum IV |   32.086    |

## 설계

### 시간 복잡도

세그먼트 트리를 사용하되, 매번 업데이트를 직접 해주는 경우 시간초과가 발생한다.

따라서 업데이트를 할 때 lazy propagation을 이용해야한다.

[lazy propagation](https://www.acmicpc.net/blog/view/26)

### 공간 복잡도

모든 수의 형태는 int형을 초과할 수 있으므로 long long 형으로 선언한다.

### 느리게 갱신되는 세그먼트 트리

다음 lazy 배열을 만들고, 함수를 다음과 같이 선언한다.

```cpp
vector<long long> lazy;

void update_lazy(int node, int start, int end) {
  if (lazy[node] == 0) return;

  tree[node] += (end - start + 1) * lazy[node];
  if (start != end) {
    lazy[node * 2] += lazy[node];
    lazy[node * 2 + 1] += lazy[node];
  }
  lazy[node] = 0;
}
```

구간의 업데이트가 필요한 경우에는 꼭 필요할 때가 오기 전까지 업데이트를 미뤄둘 수 있다.

그리고 update와 query를 수행할 때 각 update_lazy를 호출한다.

```cpp
void update(int node, int left, int right, int start, int end, long long value) {
    update_lazy(node, start, end);
// ...
}

long long query(int node, int left, int right, int start, int end) {
    update_lazy(node, start, end);
  // ...
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|     192      |       16       |

## 고생한 점
