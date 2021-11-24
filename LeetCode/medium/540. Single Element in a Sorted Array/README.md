# 540. Single Element in a Sorted Array

[링크](https://leetcode.com/problems/single-element-in-a-sorted-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

모든 원소를 순회하며 하나뿐인 원소를 찾을 수 있다.

이 경우 시간 복잡도는 O(N)이다.

배열은 정렬되어 있으므로 이분 탐색을 이용할 수 있다.

이 경우 시간 복잡도는 O(log_2(N))이다.

### 공간 복잡도

hash map을 이용해서 count를 수행할 경우 O(N)의 공간 복잡도를 사용한다.

그 외에 순회나 이분 탐색을 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(1)     |

index를 순회하며 양쪽의 값과 다른 single element를 찾는다.

이 때 양 끝값의 경우 이웃한 값이 하나밖에 없으므로 조건에 유의해야한다.

singleElement의 경우 다음 조건을 만족한다.

- 왼쪽 값이 없거나 왼쪽 노드와 값이 다름.
- 오른쪽 값이 없거나 오른쪽 노드와 값이 다름.

이를 모든 index에 대해 순회할 경우 다음과 같이 표현 가능하다.

```cpp
int singleNonDuplicate(vector<int>& nums) {
  // we iterate all index of nums
  int size = nums.size();
  int answer = nums.front();

  // (int i=0; i<nums.size();i++)
  for (int i = 0; i < size; i++) {
    // we check the left part (even i-1 < 0)
    bool isLeftOk = i - 1 >= 0 ? nums[i - 1] == nums[i] : false;
    // we check the right part (even i+1 >= nums.size())
    bool isRightOk = i + 1 < size ? nums[i] == nums[i + 1] : false;
    // we have two boolean value leftOk, rightOk

    // if leftOk == false && rightOk == false
    if (!isLeftOk && !isRightOk) {
      // i is the answer's index
      answer = nums[i];
      break;
    }
    // else i is not a single element
  }

  // return answer
  return answer;
}
```

혹은 같은 원소가 2개씩만이므로 다음과 같이 2개씩 비교할 수 있다.

```cpp
int singleNonDuplicate(vector<int>& nums) {
  // first we start index = 0
  int index = 0;
  int size = nums.size();
  // and do while iteration until index < size - 1
  while (index < size - 1) {
    // we just compare index, index + 1 (is the same or not)
    if (nums[index] == nums[index + 1]) {
      // if same, we move index += 2
      index += 2;
    } else {
      // if not, index is the single element
      // and break
      break;
    }
  }
  // if the last element is the answer index == size - 1 and break the while
  // so index is the answer;
  return nums[index];
}
```

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       | O(log_2(N)) |    O(1)     |

현재 range에서 가운데 위치한 값에 대해서 다음 3가지 경우가 존재할 수 있다.

- 현재 값이 single element인 경우
- 정답이 left subArray에 있는 경우
- 정답이 right subArray에 있는 경우

가운데 위치한 값이 single element가 아닌 경우 해당 값과 중복된 값을 제거하고 생각한다.

이후 정답이 위치한 subArray는 원소의 개수가 홀수이다.

따라서 left, right subArray중 원소의 개수가 홀수인 쪽으로 이분 탐색을 수행한다.

```cpp
int singleNonDuplicate(vector<int>& nums) {
  int size = nums.size();
  int left = 0, right = size - 1;

  // compare leftSubarray, rightSubarray size is odd or not
  // if some subarray is odd that means there are answer in that subarray

  int answer = nums.front();
  while (left <= right) {
    int mid = left + (right - left) / 2;

    // check there are same value next each other
    bool isLeftSame = mid - 1 >= 0 && nums[mid] == nums[mid - 1];
    bool isRightSame = mid + 1 < size && nums[mid] == nums[mid + 1];

    // the case that current value is single
    if (!isLeftSame && !isRightSame) {
      answer = nums[mid];
      break;
    }

    // make next range's edge
    int nextRight = isLeftSame ? mid - 2 : mid - 1;
    int nextLeft = isLeftSame ? mid + 1 : mid + 2;

    // there are answer in left Part
    if ((nextRight - left + 1) % 2 == 1) {
      right = nextRight;
    } else {  // there are answer in right part
      left = nextLeft;
    }
  }

  return answer;
}
```

## 고생한 점
