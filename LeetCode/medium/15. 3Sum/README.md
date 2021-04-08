# 15. 3Sum

[링크](https://leetcode.com/problems/3sum/)

| 난이도 |
| :----: |
| Medium |

유사한 문제

- [백준.2473.세 용액](https://www.acmicpc.net/problem/2473)

## 설계

### 시간 복잡도

숫자 배열의 크기는 최대 3,000 이다. 브루트 포스 방법으로 풀이할 경우 세 숫자를 모두 탐색하므로 O(N^3)의 시간복잡도가 소요된다.

이는 제한시간 내에 불가능하다.

따라서 최소한 O(N^2) 이내에 풀이해야한다.

### 공간 복잡도

숫자의 범위는 -10^5 ~ 10^5 까지이다.

### 투 포인터

숫자 3개를 구해야한다.

하나의 숫자를 고정한 상태에서 나머지 2개의 숫자를 투 포인터를 이용해 검색해서 찾을 경우 정답은 O(N^2) 이내에 찾을 수 있다.

이 때 투포인터를 이용한 검색을 빠르게 하기 위해 숫자 배열을 우선 오름차순으로 정렬한다.

현재 고정할 숫자의 index를 설정한다.

index + 1을 시작점, 숫자 배열의 맨 마지막 인덱스를 끝점으로 설정한다.

- (고정한 숫자 + 시작점 + 끝점)이 0이 되는 경우엔 정답을 찾은것이므로 정답으로 설정한 뒤 범위를 줄인다. (시작점은 오른쪽, 끝점은 왼쪽으로)
- 0보다 작은 경우는 시작점의 절대값이 끝점의 절대값보다 큰 경우일 수 있으므로 (시작점 : 음수, 끝점 : 양수) 시작점을 오른쪽으로 이동한다.
- 반대의 경우는 끝점을 왼쪽으로 이동한다.

index를 다음으로 이동한다.

### 중복 숫자의 관리

> 56 ms

정답은 unique한 경우만 고려해야한다.

이때 중복됫 숫자들의 경우를 줄여야 한다.

다음 경우는 명확하다.

- 다음 시작점이 현재 시작점과 동일한 경우 skip
- 다음 끝점이 현재 끝점과 동일한 경우 skip

index의 경우는 현재 index의 값이 이전 index의 값과 같은 경우에 skip해야 한다.

이는 현재 index의 값과 중복된 값이 시작점과 같은 값인 경우에도 정답이 될 수 있어야 하기 때문이다.

```cpp
vector<vector<int>> threeSum(vector<int>& nums) {
  vector<vector<int>> answer;

  sort(nums.begin(), nums.end());
  int size = nums.size();

  for (int targetIdx = 0; targetIdx < size - 2; targetIdx++) {
    if (targetIdx > 0 && nums[targetIdx] == nums[targetIdx - 1]) continue;

    int target = nums[targetIdx];

    int start = targetIdx + 1;
    int end = size - 1;

    while (start < end) {
      int curSum = target + nums[start] + nums[end];
      if (curSum == 0) {
        answer.push_back({target, nums[start], nums[end]});

        while (start < end && nums[start] == nums[start + 1]) start++;
        start++;
        while (start < end && nums[end] == nums[end - 1]) end--;
        end--;
      } else if (curSum < 0) {
        start += 1;
      } else {
        end -= 1;
      }
    }
  }

  return answer;
}
```

### 불필요한 중복숫자 제거

> 52ms

숫자 배열에서 중복된 숫자가 3개 이상 나오는 경우에는 3개의 숫자만 필요하다. 따라서 3개의 숫자만 남기고 제거한다.

제거 하는데 들어가는 시간 복잡도는 O(N)이다.

```cpp
map<int, int> m;
for(int num : nums){
  m[num] += 1;
}

nums.clear();
nums.resize(0);
for(auto cur : m){
  int count = cur.second > 3 ? 3 : cur.second;
  for(int i = 0; i < count; i++){
    nums.push_back(cur.first);
  }
}
```

## 정리

| 내 코드 (ms) |
| :----------: |
|      52      |

## 고생한 점
