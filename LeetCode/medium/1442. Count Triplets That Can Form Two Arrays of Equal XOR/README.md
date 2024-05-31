# 1442. Count Triplets That Can Form Two Arrays of Equal XOR

[링크](https://leetcode.com/problems/count-triplets-that-can-form-two-arrays-of-equal-xor/description)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열 arr의 크기를 N이라 하자.

모든 경우를 탐색할 경우 O(N^3)의 시간 복잡도를 사용한다.

prefix와 hash map을 이용해 순회와 동시에 정답을 구할 수 있다.

이 경우 O(N)의 시간 복잡도가 소요된다.

### 공간 복잡도

직접 계산할 경우 O(1)의 공간 복잡도가 필요하다.

hash map을 이용해 각 index에서의 XOR값을 저장할 경우 O(N)의 공간 복잡도가 필요하다.

### 완전 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      17      |   O(N^3)    |    O(1)     |

직접 3 인덱스를 순회하며 XOR값을 구하고 비교한다.

```cpp
int countTriplets(vector<int>& arr) {
  int size = arr.size();

  int answer = 0;
  for (int from = 0; from < size; from++) {
    int first = 0;
    for (int mid = from; mid < size; mid++) {
      first ^= arr[mid];

      int second = 0;
      for (int to = mid + 1; to < size; to++) {
        second ^= arr[to];

        if (first == second) answer++;
      }
    }
  }
  return answer;
}
```

### prefix one pass

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

```cpp
int countTriplets(vector<int>& arr) {
  int size = arr.size();
  int answer = 0;
  int prefix = 0;

  unordered_map<int, int> countMap = {{0, 1}}, totalMap;

  for (int i = 0; i < size; ++i) {
    prefix ^= arr[i];

    answer += countMap[prefix] * i - totalMap[prefix];
    countMap[prefix]++;

    totalMap[prefix] += i + 1;
  }

  return answer;
}
```

## 고생한 점
