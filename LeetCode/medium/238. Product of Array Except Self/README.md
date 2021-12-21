# 238. Product of Array Except Self

[링크](https://leetcode.com/problems/product-of-array-except-self/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

브루트 포스로 매 경우마다 문제를 풀이할 경우 순회에 O(N), i번째를 빼고 곱을 구하는데 O(N)의 시간 복잡도를 사용하므로 O(N^2)의 시간 복잡도를 사용한다.

동적 계획법을 이용해 i번째의 곱을 구할 때 0 ~ (i-1), (i+1) ~ (size-1) 두 부분의 곱으로 나눠서 구할 경우 O(1)의 시간 복잡도로 구할 수 있다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

연속된 왼쪽 부분의 곱, 오른쪽 부분의 곱을 사용한다.

이 두 배열을 만들 경우 O(N)의 공간 복잡도를 사용한다.

혹은 한번의 순회로 해당 곱을 연이어 사용할 경우 O(1)의 공간 복잡도를 사용한다.

### 동적 계획법

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(N)     |

해당 index의 num을 제외한 곱을 다음과 같이 생각해 볼 수 있다.

- 0 ~ (index-1)까지의 곱
- (index+1) ~ (size-1) 까지의 곱

위 두 숫자를 곱한 값이 index를 제외한 num의 곱이 된다.

여기서 모든 숫자의 곱에서 index에 해당하는 숫자를 나누는 값이 될 수 없는 이유는 중간에 0이 포함되기 때문이다. (0을 곱해버리면 모든 숫자가 0이되며, 이를 0으로 나눠도 원본 숫자가 나오지 않음)

따라서 왼쪽 부분의 곱, 오른쪽 부분의 곱을 각 index마다 dp배열에 저장후 사용한다.

```cpp
vector<int> fromLefts; // i-1번째 까지의 왼쪽에서부터 곱
vector<int> fromRights; // i+1번째 까지의 오른쪽에서부터 곱
```

이를 이용할 경우 다음과 같다.

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
  int size = nums.size();
  vector<int> answer(size, 1);

  vector<int> fromLefts(size, 1);
  vector<int> fromRights(size, 1);

  for (int i = 1; i < size; i++) {
    int reversed = size - 1 - i;

    fromLefts[i] = fromLefts[i - 1] * nums[i - 1];
    fromRights[reversed] = fromRights[reversed + 1] * nums[reversed + 1];
  }

  for (int i = 0; i < size; i++) {
    answer[i] = fromLefts[i] * fromRights[i];
  }

  return answer;
}
```

### 동적 계획법 (space optimize)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(1)     |

위 방법에서 직전의 값만을 사용하므로 이를 공간복잡도에 대해 최적화 할 수 있다.

fromLeft, fromRight 두 변수를 생성하고 현재 index와 reversed에 대해서 순회할 때마다 이를 업데이트해나간다.

```cpp
vector<int> productExceptSelf(vector<int>& nums) {
  int size = nums.size();
  vector<int> answer(size, 1);

  int fromLeft = 1, fromRight = 1;

  for (int i = 0; i < size; i++) {
    int reversed = size - 1 - i;

    answer[i] *= fromLeft;
    answer[reversed] *= fromRight;
    fromLeft *= nums[i];
    fromRight *= nums[reversed];
  }

  return answer;
}
```

## 고생한 점
