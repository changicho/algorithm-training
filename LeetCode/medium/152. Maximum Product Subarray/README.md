# 152. Maximum Product Subarray

[링크](https://leetcode.com/problems/maximum-product-subarray/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

모든 경우를 탐색할 경우 left, right의 범위를 모두 탐색하는 데 O(N^2)만큼의 시간 복잡도가 소요된다.

이후 하나의 range에서 subArray의 모든 곱을 구하는데 O(N)의 시간 복잡도가 소요되므로 필요한 시간 복잡도는 O(N^3)이 된다.

이는 제한시간 내에 불가능하다.

따라서 동적 계획법을 이용해 O(N)의 시간 복잡도로 순회해 문제를 해결한다.

### 공간 복잡도

각 index별로 가질 수 있는 최대 값을 설정하는 데 O(N)의 공간 복잡도가 필요하다.

혹은 prefix, suffix를 한번에 구할 경우 별도의 공간이 필요하지 않고 O(1)의 공간 복잡도로 해결이 가능하다.

### 동적 계획법 (prefix suffix)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      7       |    O(N)     |    O(1)     |

sub array의 모든 원소의 곱을 구해야 한다.

만약 값으로 0이 나오는 경우는 기존까지의 값이 모두 초기화 된다. 따라서 해당 경우에는 값을 초기화 해줘야 한다.

음수가 두번 나오는 경우는 양수가 되며 이 값이 최대값이 될 수도 있다.

따라서 음수를 포함하는 경우마다 별도의 탐색을 진행하지 않고, 왼쪽에서부터 오른쪽에서 부터 탐색을 진행해 sub array들을 구한다.

0이 나올 때마다 sub array들의 곱의 값이 초기화된다.

따라서 0을 기준으로 큰 단위로 나눌 수 있다.

sub array 내부에서 음수가 한번 나오는 경우에 대해서 생각해보자.

```javascript
// 음수인 수를 minus라고 하자
[...left, minus, ...right];
```

해당 경우에서 가장 큰 product는 left혹은 right가 된다.

음수가 홀수번 나오는 경우 또한 마찬가지이다. (음수끼리 곱하면 양수가 되므로 결국 하나를 기준점으로 왼쪽 오른쪽이 나뉨)

음수가 짝수번 나오는 경우는 음수들을 곱하면 짝수가 되므로 sub array의 product가 정답의 후보가 될 수 있다.

따라서 left, right중 하나인 답을 구하기 위해서 정방향으로, 역방향으로 두번 순회해 정답을 구한다.

```cpp
int maxProduct(vector<int> &nums) {
  int size = nums.size();
  // 초기값 설정
  int answer = nums.front();
  int left = 0, right = 0;

  for (int i = 0; i < size; i++) {
    left = (left == 0 ? 1 : left) * nums[i];
    right = (right == 0 ? 1 : right) * nums[size - 1 - i];

    answer = max(answer, max(left, right));
  }
  return answer;
}
```

## 고생한 점
