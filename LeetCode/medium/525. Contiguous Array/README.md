# 525. Contiguous Array

[링크](https://leetcode.com/problems/contiguous-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums의 크기를 N이라 하자.

완전 탐색을 이용할 경우 O(N^2)의 시간 복잡도를 사용한다. 이는 N이 최대 10^5이므로 제한시간 내에 불가능하다.

정답은 현재 index에서 끝나고 이전 i'번째 에서 시작하는 범위가 정답이다.

이를 위해 i'번째에 1과 0의 비율이 얼마나 되는지에 대해 hash map을 이용해 저장한다.

이 방법으로 왼쪽부터 순차적으로 순회 후 정답을 구할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash map을 이용할 경우 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     154      |    O(N)     |    O(N)     |

다음과 같은 hash map을 사용한다.

- key : 0과 1의 비율
- value : 해당 비율이 나타나는 첫번째 index

여기서 1과 0의 비율을 정수로 나타내기 위해서 다음 방법을 사용한다.

- 현재 range에서 1이 수만큼 +1, 0인 수만큼 -1을 수행한다.
- 이 경우 1과 0의 갯수가 같은 경우 0이된다.

이를 이용해 첫번째 값부터 i번째 값까지 비율을 hash map에 저장한다.

이 때 최장길이를 구해야 하므로 이미 존재하는 key인 경우 val을 업데이트 하지 않는다.

현재 비율이 0이 아닌 경우, 0에서 어긋난 만큼 만약 이전에 나타난 경우 해당 index까지 range에서 제거한다.

따라서 0에서 어긋난 만큼 이미 지나온 숫자에서 제거하므로 비율은 0이 된다.

이를 구현하면 다음과 같다.

```cpp
int findMaxLength(vector<int>& nums) {
  int size = nums.size();
  int answer = 0;

  // key : diff of 1,0
  // value : first index
  unordered_map<int, int> appears;
  appears[0] = -1;

  int diff = 0;
  for (int i = 0; i < size; i++) {
    int& num = nums[i];
    if (num == 0) {
      diff--;
    } else {
      diff++;
    }

    if (appears.count(diff)) {
      answer = max(answer, i - appears[diff]);
    } else {
      appears[diff] = i;
    }
  }

  return answer;
}
```

## 고생한 점
