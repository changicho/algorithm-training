# C - Rotate and Sum Query

[링크](https://atcoder.jp/contests/abc425/tasks/abc425_c)

| 난이도 |
| :----: |
|  350   |

## 설계

### 시간 복잡도

배열의 크기를 N, 쿼리의 갯수를 Q라 하자.

모든 경우마다 순환 및 합을 을 직접 구할 경우 O(N \* Q)의 시간 복잡도를 가지게 된다. 이는 제한시간 내에 불가능하다.

prefix sum과 index 이동을 사용할 경우 O(N + Q)의 시간 복잡도로 해결 가능하다.

### 공간 복잡도

prefix sum에 O(N)의 공간 복잡도를 사용한다.

### prefix sum & index shift

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      58      |  O(N + Q)   |    O(N)     |

배열의 순환을 직접 이동하지 않고 원래 첫번째 index부터 몇칸 이동했는지 index변수로 관리한다.

이후 각 구간합을 빠르게 구하기 위해 prefix sum을 미리 구해둔다.

이후 쿼리를 순회하며 순환과 구간합을 계산한다.

```cpp
auto solution(int size, vector<int> &nums, int qSize, vector<vector<int>> &queries) {
  vector<long long> answer;

  vector<long long> sums(size + 1, 0);
  for (int i = 0; i < size; i++) {
    sums[i + 1] = sums[i] + nums[i];
  }

  int index = 0;

  for (vector<int> &query : queries) {
    int type = query[0];

    if (type == 1) {
      int x = query[1];
      index = (index + x) % size;
    } else if (type == 2) {
      int l = (query[1] + index - 1 + size) % size;
      int r = (query[2] + index + 1 - 1 + size) % size;

      long long sum = 0;

      if (l < r) {
        sum = sums[r] - sums[l];
      } else {
        sum = (sums[size] - sums[l]) + (sums[r] - sums[0]);
      }

      answer.push_back(sum);
    }
  }

  return answer;
}
```

## 고생한 점
