# C - Vanish

[링크](https://atcoder.jp/contests/abc455/tasks/abc455_c)

| 난이도 |
| :----: |
|  300   |

## 설계

### 시간 복잡도

배열의 크기를 N, 입력받은 수를 K라 하자.

각 값마다의 합계를 저장 후 이중 큰 값 K개를 제거할 수 있다.

이를 위해 정렬을 수행할 경우 O(N \* log_2(N))의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      74      | O(N \* log_2(N)) |    O(N)     |

nums의 각 원소와 해당 원소들의 합을 저장한다.

이후 각 합들을 정렬 후 가장 큰 K개의 값을 뺀 나머지의 합을 구한다.

```cpp
long long solution(int size, int k, vector<int>& nums) {
  long long answer = 0;

  unordered_map<int, int> count;
  for (int& num : nums) {
    count[num]++;
  }

  vector<long long> arr;
  for (auto& [key, val] : count) {
    arr.push_back(1LL * key * val);
  }
  sort(arr.begin(), arr.end());

  while (k > 0 && !arr.empty()) {
    arr.pop_back();
    k--;
  }

  for (long long& sum : arr) {
    answer += sum;
  }

  return answer;
}
```

## 고생한 점
