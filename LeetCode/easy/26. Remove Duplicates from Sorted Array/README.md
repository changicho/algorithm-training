# 26. Remove Duplicates from Sorted Array

[링크](https://leetcode.com/problems/remove-duplicates-from-sorted-array/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

입력받는 배열의 크기는 3 \* 10^4 까지이다.

배열을 탐색하며 unique한 것을 판단하는데 시간 복잡도는 O(N)이다.

카운팅 정렬을 이용할 경우는 범위에 영향을 받으며 이는 2 \* 10^4 이다.

### 공간 복잡도

입력받는 수의 범위는 -10^4 ~ 10^4 이다.

이는 int형으로 충분하다.

### 카운팅 정렬을 이용

> 16ms

수의 범위가 매우 작으므로 카운팅 정렬을 이용한다.

이후 nums를 초기화하고 다시 할당해준다.

```cpp
bool counts[20001] = {
    false,
};

for (int num : nums) {
  counts[num + 1000] = true;
}

int answer = 0;
nums.clear();
nums.resize(0);
for (int i = 0; i <= 20000; i++) {
  if (counts[i]) {
    answer += 1;
    nums.push_back(i - 1000);
  }
}

return answer;
```

### unique 함수 이용

이미 정렬된 배열이 주어지므로 unique를 이용해 바로 유일한 배열쌍을 만들 수 있다.

```cpp
nums.erase(unique(nums.begin(), nums.end()), nums.end());

return nums.size();
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

문제에서 요구하는 nums의 갱신은, return한 length길이까지만 unique한 값이 있으면 된다는 것이다.

따라서 새로 배열을 생성할 필요 없이 length와 length까지만 유니크한 값을 넣으면 된다.

```cpp
if(nums.empty()) return 0;
int i = 0;

for(int j=1; j<nums.size(); j++){
    if(nums[j] != nums[i]) {
        i++;
        nums[i] = nums[j];
    }
}

return i+1;
```

## 정리

| 내 코드 (ms) |
| :----------: |
|              |

## 고생한 점
