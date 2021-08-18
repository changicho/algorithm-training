# 268. Missing Number

[링크](https://leetcode.com/problems/missing-number/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 원소의 개수를 N 이라 하자.

0부터 N까지 순회하며 나타나지 않은 수를 찾을 수 있다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

0부터 N까지의 방문 배열을 이용할 경우 O(N)의 공간 복잡도가 필요하다.

XOR연산을 이용할 경우 O(1)의 공간 복잡도로 풀이가 가능하다.

### XOR

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

0부터 N까지 수를 모두 xor 연산한 bit를 만든다.

이 bit에 nums의 모든 수를 xor연산한다.

이는 xor은 다음 법칙이 만족하기 때문이다.

```cpp
x^x = 0;
0^x = x;
```

따라서 missing number의 경우 한번만 나타나므로 bit는 해당 숫자가 된다.

```cpp
int missingNumber(vector<int>& nums) {
  int size = nums.size();

  int bit = 0;
  for (int num : nums) {
    bit ^= num;
  }

  for (int i = 0; i <= size; i++) {
    bit ^= i;
  }
  return bit;
}
```

## 고생한 점
