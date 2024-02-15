# 2971. Find Polygon With the Largest Perimeter

[링크](https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 크기를 N이라 하자.

정렬 이후 최대한 많은 수들을 이용해 다각형을 만들어야 한다. 이를 위해 정렬을 수행해야 하며 이는 O(N \* log(N))의 시간 복잡도가 소요된다.

이후 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

정렬에 최대 O(N)의 공간 복잡도를 사용한다.

### 정렬

| 내 코드 (ms) |  시간 복잡도   | 공간 복잡도 |
| :----------: | :------------: | :---------: |
|     140      | O(N \* log(N)) |    O(N)     |

다각형에 값이 작은 숫자들을 채워넣는 편이 최대한 많은 수들을 이용해 다각형을 만들 수 있다.

이는 현재 수가 다른 모든 수의 합 미만이여야 하기 때문이다.

따라서 현재 수를 다각형에 넣었을 때, 현재 수가 다른 수들의 합보다 작은 경우에만 다각형을 만들 수 있다.

현재 수를 다각형에 계속 넣어보며 만들 수 있는 가장 큰 다각형을 찾는다.

이 때 현재 수가 가장 긴 변인 경우 현재 수가 다른 변들의 합과 같으면 불가능하지만, 가장 긴 변이 아닌 경우 가능함에 유의한다.

```cpp
long long largestPerimeter(vector<int>& nums) {
  int size = nums.size();

  sort(nums.begin(), nums.end());

  long long answer = -1;
  long long sum = 0;
  int count = 0;

  for (int& num : nums) {
    count++;
    if (count >= 3 && num < sum) {
      answer = max(answer, sum + num);
    }
    sum += num;
  }

  return answer;
}
```

## 고생한 점
