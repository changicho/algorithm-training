# 2799. Count Complete Subarrays in an Array

[링크](https://leetcode.com/problems/count-complete-subarrays-in-an-array/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

각 sub array의 범위를 모두 탐색하며 정답을 구할 경우 O(N^2)의 시간 복잡도로 풀이가 가능하다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 풀이가 가능하다.

### 공간 복잡도

unique한 숫자의 갯수를 구하는 데 O(N)의 공간 복잡도를 사용한다.

hash set을 이용해 중복을 제거할 경우 O(N)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      31      |    O(N)     |    O(N)     |

정답에 영향을 주는 가장 짧은 sub array가 존재한다고 하자.

이 경우 해당 sub array의 범위를 left ~ right 라고 하자.

이 때 left ~ right를 포함하는 모든 sub array는 정답이다.

이를 이용해 슬라이딩 윈도우를 이용해 풀이할 수 있다.

right를 증가시키며 탐색하며, 각 경우마다의 최대의 left를 구한다. (정답에 영향을 주는 가장 짧은 sub array를 구함)

이 경우 right에서 끝나는 정답인 sub array의 갯수는 0~right 부터 left~right까지 이다.

따라서 정답에 left를 더해준다.

```cpp
int countCompleteSubarrays(vector<int>& nums) {
  int size = nums.size();
  int needNums = unordered_set<int>(nums.begin(), nums.end()).size();

  int answer = 0, left = 0;
  unordered_map<int, int> count;
  for (int right = 0; right < size; ++right) {
    count[nums[right]]++;
    if (count[nums[right]] == 1) {
      needNums--;
    }

    while (needNums == 0) {
      count[nums[left]]--;
      if (count[nums[left]] == 0) {
        needNums++;
      }
      left++;
    }
    answer += left;
  }
  return answer;
}
```

## 고생한 점
