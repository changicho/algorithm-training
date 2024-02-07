# 3020. Find the Maximum Number of Elements in Subset

[링크](https://leetcode.com/problems/find-the-maximum-number-of-elements-in-subset/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 nums의 갯수를 N이라 하자.

각 수를 작은 값부터 순회하며 subset을 검사할 수 있다. 이 때 이전에 방문한 숫자는 건너 뛴다.

이를 위해 정렬을 수행하며 시간 복잡도는 O(N \* log_2(N))이다.

이후 hash map에 각 숫자의 갯수를 저장하고, 이를 이용해 subset을 검사할 수 있다.

이 때 각 숫자를 한번씩만 방문하므로 시간 복잡도는 O(N)이다.

### 공간 복잡도

정렬에 O(N)의 공간 복잡도를 사용한다.

hash map에 각 숫자의 갯수를 저장할 경우 O(N)의 공간 복잡도가 필요하다.

### BST map

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     254      | O(N \* log_2(N)) |    O(N)     |

각 수를 count하며 map에 저장한다.

가장 작은 값을 기준으로 잡고 순회를 시작한다.

이 때 현재 숫자를 방문한 경우 count를 0으로 변경해 이미 방문했음을 표시한다.

현재 방문한 수의 갯수가 2개 이상인 경우 다음 수로 진행하며, 1인 경우 현재 수까지만 subset을 만들 수 있음으로 탐색을 중지한다.

이 때 1의 경우 몇번을 제곱해도 1이므로 별도로 처리한다.

```cpp
int maximumLength(vector<int> &nums) {
  int maximum = 0;

  map<int, int> counts;
  for (int &num : nums) {
    counts[num]++;
    maximum = max(num, maximum);
  }

  int answer = 0;
  if (counts[1] > 0) {
    answer = counts[1] - (counts[1] % 2 == 0);
  }
  counts[1] = 0;

  for (auto &[key, count] : counts) {
    long long cur = key;
    int length = 0;

    while (cur <= maximum && counts[cur] > 0) {
      length += 2;
      if (counts[cur] == 1) break;
      counts[cur] = 0;
      cur *= cur;
    }

    length--;
    answer = max(answer, length);
  }
  return answer;
}
```

## 고생한 점
