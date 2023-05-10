# 2670. Find the Distinct Difference Array

[링크](https://leetcode.com/problems/find-the-distinct-difference-array/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

nums의 원소의 갯수를 N이라 하자.

정답으로 반환할 배열의 각 값은, 해당 index까지의 prefix와 index+1까지의 suffix의 값의 갯수의 차이이다.

이를 위해 hash map을 이용해 각 경우마다의 prefix, suffix를 구한다.

순회와 동시에 연속된 값들을 갱신할 수 있다.

이 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map에 총 O(N)의 공간 복잡도를 사용한다.

### hash map & one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      83      |    O(N)     |    O(N)     |

문제에서 index번째 값은 해당 index까지의 prefix와 index+1까지의 suffix의 값의 갯수의 차이이다.

이를 위해 모든 수를 포함하는 suffix hash map에 값을 모두 카운트한다.

이후 index를 0번째 부터 증가시키며 prefix에 값을 추가하고, 현재 값을 suffix에서 뺀다.

suffix의 해당 값의 갯수가 0인 경우 삭제한다.

두 값의 차이를 정답에 추가한다.

```cpp
vector<int> distinctDifferenceArray(vector<int>& nums) {
  int size = nums.size();

  unordered_map<int, int> suffix, prefix;
  for (int i = 0; i < size; i++) {
    suffix[nums[i]]++;
  }

  vector<int> answer(size);

  for (int i = 0; i < size; i++) {
    int num = nums[i];

    prefix[num]++;
    suffix[num]--;

    if (suffix[num] == 0) suffix.erase(num);

    answer[i] = (prefix.size() - suffix.size());
  }

  return answer;
}
```

## 고생한 점
