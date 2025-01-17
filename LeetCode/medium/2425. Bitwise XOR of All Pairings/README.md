# 2425. Bitwise XOR of All Pairings

[링크](https://leetcode.com/problems/bitwise-xor-of-all-pairings/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열 nums1, nums2의 크기를 각각 N, M이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* M)이다. 이는 제한시간 내에 불가능하다.

각 수 별로 XOR연산을 수행하는 횟수를 알 수 있으며 교환법칙을 이용해 정답을 구할 수 있다.

이 경우 순회에 O(N + M)의 시간 복잡도가 소요된다.

### 공간 복잡도

정답에 O(1)의 공간 복잡도가 필요하다.

### 교환 법칙

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |  O(N + M)   |    O(1)     |

XOR 연산에 교환법칙을 적용할 수 있다.

nums1의 크기를 N, nums2의 크기를 M이라 하자.

nums1의 원소는 M번 연산을 각각 수행하며, nums2의 원소는 N번 연산을 각각 수행한다.

여기서 N, M이 짝수인 경우 XOR연산을 수행할 때 0이 된다.

따라서 각 수에 대해 연산 횟수를 구하고, 홀수인 경우에만 XOR연산을 수행한다.

```cpp
int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
  int size1 = nums1.size(), size2 = nums2.size();

  int answer = 0;
  for (int& num : nums1) {
    if (size2 % 2 == 1) answer ^= num;
  }
  for (int& num : nums2) {
    if (size1 % 2 == 1) answer ^= num;
  }
  return answer;
}
```

## 고생한 점
