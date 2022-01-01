# 2007. Find Original Array From Doubled Array

[링크](https://leetcode.com/problems/find-original-array-from-doubled-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

changed 배열의 크기를 N, changed 배열에서 unique한 숫자의 갯수를 M이라 하자.

original, double 배열 2개가 섞여있으므로 이중에서 original 배열만 추출해야 한다. (불가능한 경우 포함)

double의 각 숫자는 original의 2배이므로 정렬을 이용해 changed에서 작은 숫자부터 비교하며 해당 숫자의 2배인 숫자를 changed에서 지워나가며 탐색할 수 있다.

이 때 중복된 숫자를 처리하기 위해 hash map, map 구조를 사용할 수 있다. 이 자료구조로 변환하는데 O(N)의 시간 복잡도를 사용한다.

이 경우 정렬에 시간 복잡도는 O(M \* log_2(M))이 된다.

이후 각 숫자를 순회하며 각 숫자의 2배가 되는 값이 있는경우 해당 숫자만큼 줄이며 정답에 추가한다.

이 순회에 O(M)의 시간 복잡도를 사용하므로 최종 시간 복잡도는 O(M \* log_2(M) + N)이 된다.

### 공간 복잡도

O(M)크기의 map, hash map을 생성한다.

따라서 공간 복잡도는 O(M)이다.

### 정렬

| 내 코드 (ms) |     시간 복잡도      | 공간 복잡도 |
| :----------: | :------------------: | :---------: |
|     304      | O(M \* log_2(M) + N) |    O(M)     |

먼저 배열의 크기가 짝수가 아닌 경우는 정답을 생성하는것이 불가능하다. (같은 크기의 배열 2개가 합쳐진 것이 아니므로)

각 숫자들을 map에 저장해 count를 수행한다.

map은 BST기반으로 정렬되어있으므로 가장 작은 숫자부터 순회하며 2배인 숫자가 map에 있는지 판별한다.

여기서 숫자는 양수인 경우만 존재하므로 음수인 경우를 고려하지 않는다.

여기서 정답을 만들 수 없는 경우는 다음과 같다.

- 현재 숫자의 갯수가 2배인 숫자의 갯수보다 많은 경우.

이후 map에서 현재 숫자와 2배인 숫자의 count를 줄이며 정답을 갱신한다.

이 때 현재 숫자가 0인 경우는 2배인 숫자도 0이므로 예외 처리해야 한다.

이를 구현하면 다음과 같다.

```cpp
vector<int> findOriginalArray(vector<int> &changed) {
  int size = changed.size();
  if (size % 2 == 1) return {};

  map<int, int> counts;
  for (int &num : changed) {
    counts[num] += 1;
  }

  vector<int> answer;
  // iterate by small one
  for (auto &it : counts) {
    int num = it.first;
    if (counts[num] > counts[num * 2]) return {};
    if (counts[num] == 0) continue;

    int count = counts[num];
    if (num == num * 2) count /= 2;
    counts[num] -= count;
    counts[num * 2] -= count;

    while (count--) {
      answer.push_back(num);
    }
  }

  return answer;
}
```

## 고생한 점

현재 숫자가 0인 경우에 대해서 예외처리 해야 한다.
