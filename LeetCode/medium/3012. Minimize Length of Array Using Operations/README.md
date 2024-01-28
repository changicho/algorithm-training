# 3012. Minimize Length of Array Using Operations

[링크](https://leetcode.com/problems/minimize-length-of-array-using-operations/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 길이를 N이라 하자.

모든 경우를 탐색할 경우 순서를 고르는 데만 N! 이상의 경우의 수가 생기므로 제한시간 내에 불가능하다.

연산을 수행하면 두 수 중 큰 쪽을 감소시키게 된다.

따라서 배열의 최소값과 비교를 수행할 수 있다. 이 경우 한번의 순회로 풀이가 가능하므로 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

최소값을 지정하는데 O(1)의 공간 복잡도가 필요하다.

### 최소값 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     113      |    O(N)     |    O(1)     |

nums의 최소값을 M이라 하자.

배열의 다른 수들은 M과 gcd를 구할 경우 M 이하의 수로 변형이 가능하며 이 값들은 모두 하나의 숫자로 압축이 가능하다.

만약 다른 수들이 모두 M으로 떨어지는 경우는 gcd연산 이후 0이 되며 이 값은 제거할 수 없다.

따라서 모든 수가 M을 gcd로 가지는 경우에는 (N+1) / 2 개의 0이 남게된다.

```cpp
int minimumArrayLength(vector<int>& nums) {
  int minimum = *min_element(nums.begin(), nums.end());
  for (int& num : nums) {
    if (num % minimum > 0) {
      return 1;
    }
  }

  int minCount = count(nums.begin(), nums.end(), minimum);
  return (minCount + 1) / 2;
}
```

## 고생한 점
