# 4044. Count Good Cyclic Rotations

[링크](https://leetcode.com/problems/count-good-cyclic-rotations/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

완전 탐색으로 탐색할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다. (N은 최대 10^5)

shift 연산시 변하는 값만 갱신하며 슬라이딩 윈도우를 사용해 정답을 찾을 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

각 경우마다 값만 저장하는데 O(1)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      4       |    O(N)     |    O(1)     |

N/2 개의 원소들의 합을 저장 후 index를 이동시키며 추가, 삭제되는 값만 갱신한다.

이후 정답을 갱신한다.

이 때 두 합이 다르기만 하면 leftSum이 rightSum보다 작더라도 이후 shift연산에서 대소관계가 역전됨이 보장된다.

따라서 N/2번만 비교하면 된다.

```cpp
int countGoodRotations(vector<int>& nums) {
  int size = nums.size();

  int leftI = 0, rightI = size / 2;
  long long leftSum = 0, rightSum = 0;

  for (int i = 0; i < size / 2; i++) {
    leftSum += nums[i];
    rightSum += nums[size / 2 + i];
  }

  int answer = 0;

  for (int shift = 0; shift < size / 2; shift++) {
    if (leftSum > rightSum) answer++;

    leftSum -= nums[leftI];
    leftSum += nums[rightI];

    rightSum -= nums[rightI];
    rightSum += nums[leftI];

    leftI = (leftI + 1) % size;
    rightI = (rightI + 1) % size;
  }
  return answer;
}
```

## 고생한 점
