# k largest elements

[링크](https://practice.geeksforgeeks.org/problems/k-largest-elements4206/1/)

| 난이도 |
| :----: |
| Basic  |

## 설계

### 시간 복잡도

배열의 크기는 최대 10^5 이다.

정렬을 사용할 경우 O(N \* log(N)) 이내에 풀이가 가능하다.

우선순위 큐를 이용할 경우 최악의 경우 N = K 일 때, O(N \* log_2(N)) 이내에 풀이가 가능하다.

### 공간 복잡도

정렬의 경우 기존 배열을 이용하면 되므로 별도의 공간이 필요하지 않다.

우선순위 큐의 경우 큐에 최대 N개의 숫자가 들어갈 수 있으므로 O(N)의 공간이 필요하다.

### 정렬

|  시간 복잡도   | 공간 복잡도 |
| :------------: | :---------: |
| O(N \* log(N)) |    O(1)     |

입력받은 배열을 내림차순으로 정렬 후 앞에서부터 k개의 배열을 반환한다.

```cpp
vector<int> kLargest(int arr[], int n, int k) {
  sort(arr, arr + n, greater<int>());
  vector<int> ret;
  for (int i = 0; i < k; i++) {
    ret.push_back(arr[i]);
  }

  return ret;
}
```

### 우선순위 큐

|  시간 복잡도   | 공간 복잡도 |
| :------------: | :---------: |
| O(N \* log(N)) |    O(N)     |

가장 작은 값이 top인 우선순위 큐를 선언한다.

먼저 앞에서부터 순서대로 k개의 숫자를 힙에 넣는다.

이후 k+1번째 숫자부터 순회하며 힙의 top보다 큰 경우 top을 제거하고 힙에 숫자를 넣는다.

자동으로 힙의 top은 그 숫자들 중에서 가장 작은 값이므로 대소 관계가 유지된다.

이후 큐에 담긴 숫자의 역순으로 vector에 담아 반환한다.

```cpp
vector<int> kLargest(int arr[], int n, int k) {
  vector<int> res;

  priority_queue<int, vector<int>, greater<int>> pq;

  for (int i = 0; i < k; i++) {
    pq.push(arr[i]);
  }

  for (int i = k; i < n; i++) {
    if (pq.top() < arr[i]) {
      pq.pop();
      pq.push(arr[i]);
    }
  }

  while (!pq.empty()) {
    res.push_back(pq.top());
    pq.pop();
  }

  reverse(res.begin(), res.end());

  return res;
}
```
