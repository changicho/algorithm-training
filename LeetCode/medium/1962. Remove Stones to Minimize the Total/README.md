# 1962. Remove Stones to Minimize the Total

[링크](https://leetcode.com/problems/remove-stones-to-minimize-the-total/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 piles의 크기를 N, 숫자를 K라 하자.

각 pile들 중에서 큰 값들만 절반씩 줄였을 때 총 합이 가장 작게 만들 수 있다.

따라서 heap을 이용해 각 상황별로 가장 큰 pile을 K번 절단 한다.

이 경우 O((N + K) \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

heap을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### heap

| 내 코드 (ms) |      시간 복잡도       | 공간 복잡도 |
| :----------: | :--------------------: | :---------: |
|     754      | O((N + K) \* log_2(N)) |    O(N)     |

모든 pile을 힙에 저장후 (max heap) 가장 큰 값을 절반으로 줄이고 힙에 저장하는 동작을 K번 수행한다.

이를 구현하면 다음과 같다.

```cpp
int minStoneSum(vector<int>& piles, int k) {
  priority_queue<int> pq;

  for (int& pile : piles) {
    pq.push(pile);
  }

  for (int i = 0; i < k; i++) {
    int cur = pq.top();
    pq.pop();

    cur = (cur + 1) / 2;
    pq.push(cur);
  }

  int answer = 0;
  while (!pq.empty()) {
    answer += pq.top();
    pq.pop();
  }
  return answer;
}
```

## 고생한 점
