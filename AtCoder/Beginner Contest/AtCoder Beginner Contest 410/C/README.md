# C - Rotatable Array

[링크](https://atcoder.jp/contests/abc410/tasks/abc410_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 수를 Q라 하자.

초기 배열을 생성하는데 O(N)의 시간복잡도를 사용한다.

각 쿼리마다 배열의 원소를 변경하거나 shift를 수행해야 한다.

이 때 shift를 수행할 때 매번 수행할 경우 O(N)의 시간복잡도를 사용한다. 이는 제한시간 내에 불가능하다.

혹은 shift마다 index를 변경하는 방법을 사용할 경우 O(1)의 시간복잡도를 사용한다.

따라서 모든 쿼리를 수행하는 데 O(Q)의 시간복잡도를 사용한다.

### 공간 복잡도

배열에 O(N)의 공간복잡도를 사용한다.

### diff index

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      50      |  O(N + Q)   |    O(N)     |

shift연산을 수행할 때 시작점의 위치를 이동하는 방법을 사용한다.

이후 값을 변경하거나 찾을 때 해당 index에 shift된 만큼 보정하여 값을 변경하거나 찾는다.

이 때 shift 되더라고 index의 범위는 0~N-1로 유지되도록 한다.

```cpp
vector<int> solution(int n, int size, vector<vector<int>> &queries) {
  vector<int> answer;
  vector<int> arr(n);

  for (int i = 0; i < n; i++) {
    arr[i] = i + 1;
  }
  int diff = 0;
  for (vector<int> &q : queries) {
    int type = q[0];
    if (type == 1) {
      int p = q[1] - 1, x = q[2];

      int index = (p + diff + n) % n;

      arr[index] = x;

    } else if (type == 2) {
      int p = q[1] - 1;

      int index = (p + diff) % n;

      answer.push_back(arr[index]);
    } else {
      int k = q[1];
      diff += k;
      diff %= n;
    }
  }

  return answer;
}
```

## 고생한 점
