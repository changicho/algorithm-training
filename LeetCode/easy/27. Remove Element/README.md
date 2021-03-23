# 27. Remove Element

[링크](https://leetcode.com/problems/remove-element/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 길이는 최대 100이다. 원소의 크기는 0 ~ 50이다.

target 원소가 제거된 배열은 순서를 유지해야 하므로 배열을 순회하며 새로운 배열을 생성해야한다.

따라서 시간 복잡도는 O(N)이다.

### 공간 복잡도

원소의 크기는 0 ~ 50이며 target은 0 ~ 100 이다.

모두 int형이며 연산중에 int형을 벗어나지 않는다.

### 순회

> 4ms

새로운 벡터를 만들고, 모든 원소를 순회하며 target이 아닌경우 벡터에 집어넣는다.

시간 복잡도는 O(N);

```cpp
int removeElement(vector<int>& nums, int val) {
  vector<int> newArr;

  for (int num : nums) {
    if (num != val) {
      newArr.push_back(num);
    }
  }

  nums = newArr;

  return newArr.size();
}
```

### 투 포인터를 이용한 방법

> 4ms

원본 배열에서 length 까지의 순서만 일치하면 된다.

따라서 기존 벡터를 갱신하며 새로운 배열을 만든다.

새로운 배열을 채울 인덱스를 i로 두고, target과 현재 숫자가 같이 않은경우 넘긴다.

```cpp
int removeElement(vector<int>& nums, int val) {
  int i = 0;
  for (int j = 0; j < nums.size(); j++) {
    if (nums[j] != val) {
      nums[i] = nums[j];
      i++;
    }
  }
  return i;
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      4       |

## 고생한 점
