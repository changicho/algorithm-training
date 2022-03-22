# 2202. Maximize the Topmost Element After K Moves

[링크](https://leetcode.com/problems/maximize-the-topmost-element-after-k-moves/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

nums 원소의 크기를 N, 입력받은 수를 K라 하자.

모든 경우를 탐색해 볼 경우 경우의 수는 최대 2^K 가지가 존재하며 이를 모두 탐색할 경우 제한시간 내에 불가능하다.

탐욕 알고리즘을 이용할 경우 한번의 순회로 풀이가 가능하다. 따라서 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

탐욕 알고리즘을 이용할 경우 O(1)의 공간 복잡도를 사용한다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     153      |    O(N)     |    O(1)     |

앞에서부터 K-1개를 꺼낸다고 가정하자.

이 때 K-1개까지 꺼낸 뒤 그중 제일 큰 수를 back에 넣으면 K번움직이며 가장 큰 수를 뽑을 수 있다.

따라서 기본적으로 K-1 번 순회하며 해당 수 까지 가장 큰 수를 찾을 수 있다.

혹은 K개의 숫자를 다 뽑은 뒤 남은 숫자가 정답이 될 수도 있다.

따라서 정답의 후보는 다음과 같다.

- 앞에서 K-1개의 숫자중 하나
- K+1번째 숫자 (K+1번째가 배열에 존재할경우)

여기서 정답을 만들지 못하는 경우는 다음과 같다.

- 원소의 갯수가 1개이며 K가 홀수인 경우

위와 같은 경우는 nums배열 자체가 비어버리는 선택지만이 존재한다.

이를 구현하면 다음과 같다.

```cpp
int maximumTop(vector<int>& nums, int k) {
  int size = nums.size();
  if (size == 1 && k % 2 == 1) {
    return -1;
  }

  int maximum = -1;
  for (int i = 0; i < min(size, k - 1); i++) {
    maximum = max(maximum, nums[i]);
  }

  if (k < size) {
    maximum = max(maximum, nums[k]);
  }

  return maximum;
}
```

## 고생한 점
