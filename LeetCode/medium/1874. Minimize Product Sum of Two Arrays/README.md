# 1874. Minimize Product Sum of Two Arrays

[링크](https://leetcode.com/problems/minimize-product-sum-of-two-arrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 N이라 하자.

정렬을 사용해 곱의 최소합을 구할 수 있다. 이 경우 시간 복잡도는 O(N \* log_2(N))이다.

카운팅 정렬을 사용할 경우 O(N + 100) = O(N)의 시간 복잡도를 가진다.

### 공간 복잡도

카운팅 정렬에 필요한 공간은 O(100) = O(1)이다.

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      69      |    O(N)     |    O(1)     |

두 수의 각 숫자의 곱의 합을 최소화 하기 위해서는 한 배열의 가장 큰 수와 다른 배열의 가장 작은 수를 곱하는 방식으로 진행해야 한다.

nums1의 원소를 임의로 순서를 변경할 수 있으므로 카운팅 정렬을 사용해 각 배열의 빈도 수를 저장한 뒤, nums1은 오름차순, nums2는 내림차순으로 곱의 합을 구한다.

```cpp
int minProductSum(vector<int>& nums1, vector<int>& nums2) {
  int count1[101] = {
      0,
  };
  int count2[101] = {
      0,
  };

  for (int& num : nums1) {
    count1[num]++;
  }
  for (int& num : nums2) {
    count2[num]++;
  }

  int size = nums1.size();
  int num1 = 0, num2 = 100;

  int sum = 0;
  for (int i = 0; i < size; i++) {
    while (count1[num1] == 0) {
      num1++;
    }
    count1[num1]--;

    while (count2[num2] == 0) {
      num2--;
    }
    count2[num2]--;

    sum += num1 * num2;
  }
  return sum;
}
```

## 고생한 점
