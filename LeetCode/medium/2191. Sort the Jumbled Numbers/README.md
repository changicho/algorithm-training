# 2191. Sort the Jumbled Numbers

[링크](https://leetcode.com/problems/sort-the-jumbled-numbers/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

mapping의 크기는 10으로 고정, nums의 크기를 N이라 하자.

결국 원소를 원하는 방식대로 정렬해야 하므로 O(N \* log_2(N))의 시간 복잡도를 사용한다.

숫자의 범위가 매우 크므로 counting sort는 사용할 수 없다.

각 수를 순회하며 convert한 수를 저장하는데 O(N)의 시간 복잡도를 사용한다.

이 때 convert에는 각 수의 길이만큼 시간복잡도를 사용한다. 이 길이는 최대 5이다.

따라서 순회와 convert에는 O(N)의 시간 복잡도를 사용한다.

따라서 총 시간 복잡도는 O(N \* log_2(N))이다.

### 공간 복잡도

convert한 수와 원본 수를 저장할 배열에 O(N)의 공간 복잡도를 사용한다.

정답 배열에 O(N)의 공간 복잡도를 사용한다.

### 변환 후 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|     461      | O(N \* log_2(N)) |    O(N)     |

각 숫자들에 대해 원본 숫자와 변환한 숫자를 담는 구조체를 정의한다.

```cpp
struct Number {
  int origin, converted;

  bool operator<(const Number &b) const { return converted < b.converted; }
};
```

각 수를 원본과 변환한 수를 같이 담아 배열에 저장한다. 이후 정렬한다.

이 때 정렬의 비교 연산은 converted로만 수행하며, 만약 converted가 같은 경우 원본 순서를 유지한다.

이를 위해 stable sort를 사용한다.

(unstable sort를 사용해도 정답 통과)

혹은 index를 같이 저장하고 정렬에 사용할 수 있다.

```cpp
vector<int> sortJumbled(vector<int> &mapping, vector<int> &nums) {
  vector<Number> datum;

  for (int &num : nums) {
    string converted = "";
    for (char c : to_string(num)) {
      converted += mapping[c - '0'] + '0';
    }

    datum.push_back({num, stoi(converted)});
  }

  stable_sort(datum.begin(), datum.end());

  vector<int> answer;
  for (Number &d : datum) {
    answer.push_back(d.origin);
  }

  return answer;
}
```

## 고생한 점
