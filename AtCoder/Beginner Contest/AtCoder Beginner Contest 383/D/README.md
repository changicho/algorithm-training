# D - Repeated Sequence

[링크](https://atcoder.jp/contests/abc384/tasks/abc384_d)

| 난이도 |
| :----: |
|  400   |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

무한정 배열이 반복되므로 반복되는 부분은 제거하고 풀이하지 않는 경우 제한시간 내에 불가능하다.

prefix sum을 이용할 경우 O(N)의 시간 복잡도로 해결이 가능하다.

### 공간 복잡도

prefix sum을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

합은 long long 범위이다.

### prefix sum

| 시간 복잡도 | 공간 복잡도 |
| :---------: | :---------: |
|    O(N)     |    O(N)     |

정답은 다음과 같이 나타낼 수 있다.

모든 수의 합 : S
정답의 범위의 왼쪽 부분 : L
정답의 범위의 오른쪽 부분 : R

```text
answer = [L + S + S + ... + S + R];
```

즉 정답에서 반복되는 S를 제거하고 L + R을 구해야 한다.

이 때 L과 R은 각각 S의 부분 연속 배열이다. 따라서 특정 범위가 중복해서 들어갈 수 있다.

이를 위해서 nums의 값을 2번 반복해 prefix sum을 만들고 해당 prefix sum을 이용해 L + R을 만족하는 값이 있는지 확인한다.

```cpp
bool solution(int size, long long target, vector<int> &nums) {
  long long allSum = accumulate(nums.begin(), nums.end(), 0LL);
  target %= allSum;

  long long prefixSum = 0;
  unordered_set<long long> prefixSums;
  for (int i = 0; i < size * 2; i++) {
    prefixSum += nums[i % size];

    prefixSums.insert(prefixSum);
  }

  for (long long sum : prefixSums) {
    if (prefixSums.find(sum + target) != prefixSums.end()) {
      return true;
    }
  }

  return false;
}
```

## 고생한 점
