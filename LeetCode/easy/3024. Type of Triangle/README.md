# 3024. Type of Triangle

[링크](https://leetcode.com/problems/type-of-triangle/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

숫자 3개가 주어진다.

해당 수를 비교해 삼각형이 불가능한지, 가능하면 어떠한 유형인지 판단한다.

이에 O(1)의 시간 복잡도로 해결할 수 있다.

### 공간 복잡도

비교에 O(1)의 공간 복잡도를 사용한다.

### 수학

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(1)     |    O(1)     |

가장 큰 변의 길이가 나머지 변들의 합 이상인 경우 삼각형을 만들 수 없다.

그 외의 경우 이등변 삼각형인지, 정삼각형인지, 일반 삼각형인지 판단한다.

```cpp
string triangleType(vector<int>& nums) {
  int maximum = *max_element(nums.begin(), nums.end());
  int sum = accumulate(nums.begin(), nums.end(), 0);

  if (sum - maximum <= maximum) return "none";
  if (nums[0] == nums[1] && nums[1] == nums[2] && nums[2] == nums[0]) {
    return "equilateral";
  }
  if (nums[0] == nums[1] || nums[1] == nums[2] || nums[2] == nums[0]) {
    return "isosceles";
  }

  return "scalene";
}
```

## 고생한 점
