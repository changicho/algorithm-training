# 769. Max Chunks To Make Sorted

[링크](https://leetcode.com/problems/max-chunks-to-make-sorted/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(2^N)이며 제한시간 내에 불가능하다.

순회와 prefix sum을 이용해 풀이할 경우 시간 복잡도는 O(N)이다.

### 공간 복잡도

합과 정답을 저장하는데 O(1)의 공간 복잡도가 필요하다.

### prefix sum & 순회

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

배열을 특정 part들로 나누고 해당 part들을 정렬했을 때 모든 배열이 정렬되는지 확인해야 한다.

이 때 정렬 조건을 맞추기 위해 순서가 정렬되어있지 않은 part들을 찾아야 한다. 이미 정렬되어있는 part들은 최대한 쪼갤 수 있을만큼 쪼개 정답의 크기를 최대한 크게 한다.

순서가 정렬되어 있지 않은지 판단하기 위해 prefix sum을 이용할 수 있다.

이는 배열의 원소가 0 ~ N-1까지 유니크한 수로 이루어져 있으므로 가능하다.

특정 part의 오른쪽 index까지 합이 0 ~ index까지의 합과 같다면 해당 part를 정렬했을 때 정답조건을 만족시킬 수 있다.

```cpp
int maxChunksToSorted(vector<int>& arr) {
  int size = arr.size();

  int answer = 0;
  int prefixSum = 0;

  for (int i = 0; i < size; i++) {
    int num = arr[i];

    prefixSum += num;
    // sum of 0 to i
    int target = (i + 1) * i / 2;

    if (target == prefixSum) answer++;
  }
  return answer;
}
```

## 고생한 점
