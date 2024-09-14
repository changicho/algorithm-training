# 1310. XOR Queries of a Subarray

[링크](https://leetcode.com/problems/xor-queries-of-a-subarray/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N, 쿼리의 개수를 Q라 하자.

모든 경우를 탐색할 경우 시간 복잡도는 O(N \* Q) 이므로 제한시간 내에 불가능하다.

prefix sum을 이용해 XOR값을 누적하고 풀이할 수 있다.

이 경우 시간 복잡도는 O(N + Q)이다.

### 공간 복잡도

prefix sum을 사용할 경우 O(N)의 공간 복잡도가 필요하다.


### prefix sum (bit count)

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      69      |  O(N + Q)   |    O(N)     |

각 index 까지의 bit들의 수의 누적합을 생성한다.

이후 쿼리를 수행할 때 해당 범위의 비트의 갯수 누적합을 구하고, 해당 누적합을 XOR한다.

이 때 비트의 수가 짝수인 경우는 0, 홀수인 경우는 1이 된다.

```cpp
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
  int size = arr.size();

  vector<int> subArraySum(size + 1, 0);

  for (int i = 0; i < size; i++) {
    subArraySum[i + 1] = subArraySum[i];

    int cur = arr[i];
    for (int j = 0; j < 31; j++) {
      int bit = (1 << j);

      if ((cur & bit) > 0) {
        subArraySum[i + 1] ^= bit;
      }
    }
  }

  vector<int> answer;
  for (vector<int>& query : queries) {
    int left = query[0] + 1, right = query[1] + 1;

    int ret = subArraySum[right] ^ subArraySum[left - 1];

    answer.push_back(ret);
  }
  return answer;
}
```

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      61      |  O(N + Q)   |    O(N)     |

위 방법에서 결국 해당 비트의 수가 짝수개인지 홀수개인지가 중요하다.

따라서 index마다 XOR값을 누적하며 누적합을 구하고 쿼리에서 이를 이용해 XOR값을 구할 수 있다.

```cpp
vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
  int size = arr.size();

  vector<int> prefixes(size + 1, 0);

  for (int i = 0; i < size; i++) {
    prefixes[i + 1] = prefixes[i];

    prefixes[i + 1] ^= arr[i];
  }

  vector<int> answer;
  for (vector<int>& query : queries) {
    int left = query[0] + 1, right = query[1] + 1;

    int ret = prefixes[right] ^ prefixes[left - 1];

    answer.push_back(ret);
  }
  return answer;
}
```

## 고생한 점
