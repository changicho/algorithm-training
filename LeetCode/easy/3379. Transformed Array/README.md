# 3379. Transformed Array

[링크](https://leetcode.com/problems/transformed-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

순회를 이용해 풀 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정답에 추가 공간을 생성할 경우 O(N)의 공간 복잡도를 사용한다.

입력받은 배열을 수정할 경우 O(1)의 공간 복잡도를 사용한다.

### 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(N)     |

```cpp
vector<int> constructTransformedArray(vector<int>& nums) {
  int size = nums.size();

  vector<int> answer(size);

  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    int next = (i + cur % size + size) % size;
    answer[i] = nums[next];
  }
  return answer;
}
```

### in place

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      9       |    O(N)     |    O(1)     |

배열의 값을 수정하면 다른 값에 영향을 줄 수 있다.

따라서 자리수를 분리해 변화된 값과 원본 값을 같이 관리하며, 음수를 양수로 변환해 인덱스를 계산한다.

```cpp
vector<int> constructTransformedArray(vector<int>& nums) {
  int size = nums.size();

  for (int i = 0; i < size; i++) {
    nums[i] += 100;
  }

  for (int i = 0; i < size; i++) {
    int cur = nums[i] % 1000;

    int next = (i + (cur - 100) % size + size) % size;
    nums[i] += (nums[next] % 1000) * 1000;
  }

  for (int i = 0; i < size; i++) {
    nums[i] /= 1000;
    nums[i] -= 100;
  }
  return nums;
}
```

## 고생한 점
