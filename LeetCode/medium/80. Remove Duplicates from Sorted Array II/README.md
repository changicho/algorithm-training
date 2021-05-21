# 80. Remove Duplicates from Sorted Array II

[링크](https://leetcode.com/problems/remove-duplicates-from-sorted-array-ii/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

3개이상 중복된 수의 경우 2개씩만 나타내면 된다.

순회를 하며 중복된 수를 count하고, 이 중 2개까지 배열에 추가하면 되므로 한번의 순회, 배열 생성에 O(N)의 시간 복잡도가 소요된다.

index를 이동하며 직접 채우는 경우 또한 한번의 순회로 충분하다.

### 공간 복잡도

map을 이용해 count를 세는 경우 O(N)의 공간 복잡도가 필요하다.

index만을 이용하는 경우 별도의 공간 복잡도가 필요하지 않으므로 O(1)의 공간 복잡도가 필요하다.

### count

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

한번 순회하며 모든 수를 count한다.

이후 오름차순으로 key를 최대 2개 까지 채운다.

```cpp
int removeDuplicates(vector<int>& nums) {
  map<int, int> counts;

  for (int num : nums) {
    counts[num] += 1;
  }

  int index = 0;
  for (pair<int, int> cur : counts) {
    for (int i = 0; i < min(cur.second, 2); i++) {
      nums[index] = cur.first;
      index++;
    }
  }

  return index;
}
```

### index move

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

현재 index에서 index-2번째 값이 현재 값보다 큰 경우에 배열의 값을 바꾼다.

그 후 index를 증가시킨다.

이 방법을 이용할 경우 중복된 3번째 이상의 숫자가 나타날 경우 index가 증가하지 않는다.

따라서 새로운 값이 나타날 때 해당 index를 채우게 되므로 자동적으로 2개 까지만 중복된 숫자가 나타나게 된다.

```cpp
int removeDuplicates(vector<int>& nums) {
  int index = 0;
  for (int num : nums) {
    if (index < 2 || num > nums[index - 2]) {
      nums[index] = num;
      index++;
    }
  }

  return index;
}
```

## 고생한 점
