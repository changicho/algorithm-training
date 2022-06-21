# E. Binary Deque

[링크](https://codeforces.com/contest/1692/problem/E)

| 난이도 |
| :----: |
| \*1200 |

time limit per test : 2 seconds
memory limit per test : 256 megabytes

## 설계

### 시간 복잡도

주어진 배열의 크기 N과 남길 1의 갯수 S는 최대 2 \* 10^5 이다.

이는 O(N^2)의 시간 복잡도로 풀이할 경우 시간 초과가 발생한다.

따라서 O(N \* log_2(N))의 시간 복잡도로 풀이한다.

prefix sum을 사용할 경우 index가 증가함에 따라 선형으로 값이 증가하게 된다.

따라서 left를 0부터 N-1까지 탐색하며, 나머지 right를 이분 탐색으로 찾을 수 있다.

이 경우 prefix sum을 생성하는데 O(N), 이분 탐색을 수행하는 데 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

prefix sum을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### prefix sum + 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      62      | O(N \* log_2(N)) |    O(N)     |

nums의 prefix sum을 미리 구한다.

이 경우 prefix sum은 다음 규칙을 만족한다.

```cpp
prefixSums[i] <= prefixSums[i+1];
```

따라서 원하는 수를 찾기 위해 이분 탐색을 수행할 수 있다.

삭제 연산을 수행하고 남은 배열의 index를 left ~ right라고 하자

left를 1부터 size까지 변화시켰을 때, (left - 1) 까지의 합을 제외하고 남은 배열의 1의 합이 s가 되는 right를 이분탐색으로 구한다.

이는 다음조건을 만족하기 때문이다.

`prefixes[size] - prefixes[i] = s`

정답이 생성 불가능한 경우, 아무것도 지우지 않아도 되는 경우를 위해 s가 prefixSum의 합보다 큰지, 같은지를 검사한다.

이를 구현하면 다음과 같다.

```cpp
int solution(vector<int> &nums, int s) {
  int size = nums.size();
  vector<int> prefixes(size + 1, 0);
  for (int i = 0; i < size; i++) {
    int n = nums[i];

    prefixes[i + 1] = prefixes[i] + n;
  }

  if (prefixes.back() < s) return -1;
  if (prefixes.back() == s) return 0;

  int answer = size;

  for (int left = 0; left <= size; left++) {
    // prefixes[size] - prefixes[i] = s
    int target = s + prefixes[left];

    // (left + 1) ~ right
    int right = upper_bound(prefixes.begin(), prefixes.end(), target) -
                prefixes.begin() - 1;

    int length = right - (left + 1) + 1;
    answer = min(answer, size - length);
  }

  return answer;
}
```

## 입출력

### input

```text
7
3 1
1 0 0
3 1
1 1 0
9 3
0 1 0 1 1 1 0 0 1
6 4
1 1 1 1 1 1
5 1
0 0 1 1 0
16 2
1 1 0 0 1 0 0 1 1 0 0 0 0 0 1 1
6 3
1 0 1 0 0 0
```

### output

```text
0
1
3
2
2
7
-1
```

## 고생한 점

prefix sum을 이용하는 부분까지는 생각났으나 이분 탐색을 사용 가능한지 몰랐다.
