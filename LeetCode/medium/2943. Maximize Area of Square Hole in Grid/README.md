# 2943. Maximize Area of Square Hole in Grid

[링크](https://leetcode.com/problems/maximize-area-of-square-hole-in-grid/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 배열의 크기를 각각 N, M이라 하자.

각 배열에 존재하는 수를 제거할 수 있으며 이 중 연속된 범위중 최대값을 각각 구한다.

이를 위해 정렬을 사용할 경우 O(N \* log_2(N) + M \* log_2(M))의 시간 복잡도를 사용한다.

이후 두 값중 작은 값을 제곱하여 반환한다.

따라서 전체 시간 복잡도는 O(N \* log_2(N) + M \* log_2(M))이 된다.

### 공간 복잡도

정렬에 O(N + M)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |           시간 복잡도            | 공간 복잡도 |
| :----------: | :------------------------------: | :---------: |
|      0       | O(N \* log_2(N) + M \* log_2(M)) |  O(N + M)   |

hBars, vBars의 수를 모두 제거한다고 하자.

이 때 연속된 수들이 제거될 수 있으며 해당 연속된 수들 중 최대 갯수가 해당 축에서 만들 수 있는 가장 큰 정사각형의 한 변의 길이가 된다.

x, y축에 대해 이를 각각 수행하며 두 값중 작은 값이 가장 큰 정사각형의 한 변의 길이가 된다.

이 값을 제곱하며 반환한다.

```cpp
int calc(vector<int>& nums) {
  int ret = 1;

  sort(nums.begin(), nums.end());
  int before = -100;
  int count = 0;
  for (int i = 0; i < nums.size(); i++) {
    if (nums[i] == before + 1) {
      count++;
      before = nums[i];
    } else {
      count = 1;
      before = nums[i];
    }

    ret = max(ret, count + 1);
  }
  return ret;
}

int maximizeSquareHoleArea(int n, int m, vector<int>& hBars, vector<int>& vBars) {
  int hMax = calc(hBars);
  int vMax = calc(vBars);

  int length = min(hMax, vMax);

  return length * length;
}
```

## 고생한 점
