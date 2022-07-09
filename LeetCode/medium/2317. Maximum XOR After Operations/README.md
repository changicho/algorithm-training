# 2317. Maximum XOR After Operations

[링크](https://leetcode.com/problems/maximum-xor-after-operations/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

모든 원소를 순회하며 OR연산을 수행한 값을 찾는 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

모든 원소를 순회하며 OR연산한 값을 저장하는 데 O(1)의 공간 복잡도를 사용한다.

### OR

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     136      |    O(N)     |    O(1)     |

operation에서 AND연산 때문에 아래 식을 만족한다.

```cpp
nums[i] & (nums[i]^x) <= nums[i]
```

위 식에서 우리는 x를 임의의 값으로 설정할 수 있고 (0 ~ N-1까지) 필요없는 1 bit들을 0으로 바꿀 수 있다.

반대로 0인 비트들을 1로 바꾸는것은 불가능하다.

위 과정에서 우리는 모든 숫자들의 비트를 미리 조정하고, 이를 모두 연산해 OR연산하는것과 동일한 효과를 얻을 수 있다.

```cpp
int maximumXOR(vector<int>& nums) {
  int bit = 0;
  for (int& n : nums) {
    bit |= n;
  }
  return bit;
}
```

## 고생한 점
