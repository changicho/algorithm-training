# 283. Move Zeroes

[링크](https://leetcode.com/problems/move-zeroes/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 원소의 개수를 N이라 하자.

한번의 순회를 통해 0들의 개수를 세거나, 이동시킬 수 있다.

이 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

새로운 배열을 생성하는 경우 O(N)의 공간 복잡도가 필요하다.

값을 바꾸는 방법을 사용할 경우 O(1)의 공간 복잡도가 필요하다.

### 새로운 배열 생성

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

새로운 배열을 생성해 0을 뒤로 옮긴다.

```cpp
void moveZeroes(vector<int>& nums) {
  vector<int> temp;

  int count = 0;
  for (int num : nums) {
    if (num == 0) {
      count += 1;
    } else {
      temp.emplace_back(num);
    }
  }

  for (int i = 0; i < count; i++) {
    temp.emplace_back(0);
  }

  nums = temp;
}
```

### index swap

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

0을 발견한 경우 0을 옮긴다. 그 후 다음에 0을 채워넣을 index를 이동한다.

이후 맨 뒤에서부터 0을 채워넣어야 하는 공간엔 쓰래기값들이 존재하므로 이 값들을 전부 0으로 바꿔준다.

```cpp
void moveZeroes(vector<int>& nums) {
  int index = 0;

  for (int num : nums) {
    if (num != 0) {
      nums[index] = num;
      index++;
    }
  }

  for (int i = index; i < nums.size(); i++) {
    nums[i] = 0;
  }
}
```

혹은 swap을 이용해 한번에 0을 이동시킬 수 있다.

```cpp
void moveZeroes(vector<int>& nums) {
  int index = 0;
  for (int& num : nums) {
    if (num != 0) {
      swap(nums[index], num);
      index++;
    }
  }
}
```

## 고생한 점
