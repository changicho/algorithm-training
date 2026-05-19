# 2615. Sum of Distances

[링크](https://leetcode.com/problems/sum-of-distances/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 크기를 N이라 하자.

각 값별로 index를 그룹으로 나눈 후 값을 구할 수 있다.

그룹으로 나눈 후 prefix sum을 이용해 정답을 구할 수 있다.

이 경우 순회에 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

그룹으로 나누는데 hash map을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### prefix sum

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      46      |    O(N)     |    O(N)     |

각 값별로 index를 묶는다.

왼쪽부터 순회하며 hash map에 저장할 경우 자동으로 오름차순으로 정렬된다.

이후 각 index별로 다음과 같은 방법으로 답을 구할 수 있다.

- 현재 index보다 작은 i : index - i 의 합들을 더함
- 현재 index보다 큰 i : i - index 의 합들을 더함

이때 식을 변환할 경우 현재 index에 대해 다음과 같이 구할 수 있다.

- left, leftSum : index보다 작은 i의 갯수, 합
- right, rightSum : index보다 큰 i의 갯수, 합
- sum : 전체 i의 합

이를 이용해 다음 두 부분을 구한다

- `leftPart = left * index - leftSum`
- `rightPart = rightSum - right * index`

이를 index가 작은 순으로 순차적으로 순회하며 구할 경우 leftSum을 구하며 나머지 답을 구할 수 있다. (prefix sum)

```cpp
vector<long long> distance(vector<int>& nums) {
  int size = nums.size();
  unordered_map<int, vector<int>> idxs;

  for (int i = 0; i < size; i++) {
    int cur = nums[i];

    idxs[cur].push_back(i);
  }

  vector<long long> answer(size);

  for (auto& [key, val] : idxs) {
    if (val.size() == 1) continue;

    long long sum = accumulate(val.begin(), val.end(), 0LL);

    long long prefix = 0;

    int ssize = val.size();

    for (long long i = 0; i < ssize; i++) {
      long long leftPart = val[i] * (i + 1) - prefix;

      long long rightPart = (sum - prefix) - val[i] * (ssize - i + 1);

      answer[val[i]] = leftPart + rightPart;
      prefix += val[i];
    }
  }

  return answer;
}
```

## 고생한 점
