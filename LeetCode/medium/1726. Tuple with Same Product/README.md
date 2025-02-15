# 1726. Tuple with Same Product

[링크](https://leetcode.com/problems/tuple-with-same-product/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^4)의 시간 복잡도가 필요하다. 이는 제한시간 내에 불가능하다.

두 수의 곱을 모두 구하고 이를 count해 순회하며 정답을 구할 경우 O(N^2)의 시간 복잡도가 필요하다.

### 공간 복잡도

두 수의 곱을 저장하는데 O(N^2)의 공간 복잡도가 필요하다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     298      |   O(N^2)    |   O(N^2)    |

nums의 모든 요소들은 unique하다.

두 수의 곱에 대한 갯수를 모두 센다.

이후 같은 곱을 구성하는 경우의 수는 두 수의 곱의 갯수가 된다.

따라서 두 수의 곱의 갯수가 2 이상인 경우에 대해서만 경우의 수를 구하며 정답에 더한다.

이 때 A \* B = C \* D 라고 할 때, A, B, C, D의 순서는 상관없으므로 경우의 수는 8가지가 된다.

또한 A \* B, C \* D는 다른 경우이므로 각 수의 곱의 갯수에서 2개의 수를 뽑는 경우의 수를 구해야 한다.

```cpp
int tupleSameProduct(vector<int>& nums) {
  int size = nums.size();

  unordered_map<int, int> counts;
  for (int i = 0; i < size; i++) {
    for (int j = i + 1; j < size; j++) {
      int cur = nums[i] * nums[j];

      counts[cur]++;
    }
  }

  int answer = 0;
  for (auto& [key, val] : counts) {
    if (val >= 2) {
      int combi = (val - 1) * val / 2;
      answer += combi * 2 * 2 * 2;
    }
  }
  return answer;
}
```

## 고생한 점
