# 2537. Count the Number of Good Subarrays

[링크](https://leetcode.com/problems/count-the-number-of-good-subarrays/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^2)의 시간 복잡도를 사용하며 이는 제한시간 내에 불가능하다.

슬라이딩 윈도우를 사용할 경우 O(N)의 시간 복잡도로 해결할 수 있다.

### 공간 복잡도

슬라이딩 윈도우에 각 숫자마다의 count를 저장하기 위해 O(N)의 공간 복잡도를 사용한다.

### 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      79      |    O(N)     |    O(N)     |

특정 숫자가 현재 X개 존재할 때 해당 숫자를 1개 추가할 때 새로 추가되는 pair의 갯수는 X개 이다.

이를 이용해 슬라이딩 윈도우를 사용하며 pair가 k보다 작은 윈도우들을 찾을 수 있다.

윈도우의 left, right를 각각 시작과 끝으로 두고, right를 증가시키며 pair의 갯수를 세어준다.

이후 pair의 갯수가 k보다 작아질 때까지 left를 증가시킨다.

해당 윈도우의 왼쪽 부분에 원소들을 추가하는 경우의 수를 정답에 더한다.

```cpp
long long countGood(vector<int>& nums, int k) {
  int size = nums.size();

  long long answer = 0;
  unordered_map<int, int> count;
  int pairs = 0;
  for (int left = 0, right = 0; right < size; right++) {
    count[nums[right]]++;
    pairs += count[nums[right]] - 1;

    while (k <= pairs) {
      count[nums[left]]--;
      pairs -= count[nums[left]];
      left++;
    }

    answer += left;
  }
  return answer;
}
```

## 고생한 점
