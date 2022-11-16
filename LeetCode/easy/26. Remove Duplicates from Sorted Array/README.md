# 26. Remove Duplicates from Sorted Array

[링크](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받는 배열의 크기는 3 \* 10^4 까지이다.

배열을 탐색하며 unique한 것을 판단하는데 시간 복잡도는 O(N)이다.

카운팅 정렬을 이용할 경우는 범위에 영향을 받으며 범위는 200이므로 O(1) 이다.

따라서 총 시간 복잡도는 O(N)이다.

### 공간 복잡도

입력받는 수의 범위는 -100 ~ +100 까지 이다.

별도의 공간을 사용할 경우 O(N)의 공간을 사용한다.

기존 배열에 정렬할 경우 별도의 공간 복잡도를 필요로 하지 않는다.

### 카운팅 정렬을 이용

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      15      |    O(N)     |    O(N)     |

수의 범위가 매우 작으므로 카운팅 정렬을 이용한다.

이후 nums를 초기화하고 다시 할당해준다.

```cpp
int removeDuplicates(vector<int>& nums) {
  bool counts[201] = {
      false,
  };

  for (int num : nums) {
    counts[num + 100] = true;
  }

  nums.clear();
  nums.resize(0);
  for (int i = 0; i <= 200; i++) {
    if (counts[i]) {
      nums.push_back(i - 100);
    }
  }

  return nums.size();
}
```

### unique 함수 이용

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(N)     |    O(N)     |

이미 정렬된 배열이 주어지므로 unique를 이용해 바로 유일한 배열쌍을 만들 수 있다.

```cpp
int removeDuplicates(vector<int>& nums) {
  nums.erase(unique(nums.begin(), nums.end()), nums.end());

  return nums.size();
}
```

실제로 unique함수는 아래 투포인터를 이용한 방법과 유사하다.

```cpp
template <class ForwardIterator>
  ForwardIterator unique (ForwardIterator first, ForwardIterator last) {
  if (first==last) {
    return last;
  }

  ForwardIterator result = first;
  while (++first != last) {
    if (!(*result == *first)) {
      // or: if (!pred(*result,*first)) for version (2)
      *(++result)=*first;
    }
  }

  return ++result;
}
```

### 투포인터 이용

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      23      |    O(N)     |    O(N)     |

문제에서 요구하는 nums의 갱신은, return한 length길이까지만 unique한 값이 있으면 된다는 것이다.

따라서 새로 배열을 생성할 필요 없이 length와 length까지만 유니크한 값을 넣으면 된다.

```cpp
int removeDuplicates(vector<int>& nums) {
  int size = nums.size();
  int insertIndex = 1;
  for (int i = 1; i < size; i++) {
    if (nums[i - 1] != nums[i]) {
      nums[insertIndex] = nums[i];
      insertIndex++;
    }
  }
  return insertIndex;
}
```

## 고생한 점
