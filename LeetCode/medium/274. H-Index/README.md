# 274. H-Index

[링크](https://leetcode.com/problems/h-index/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

citations의 크기를 N이라 하자.

이분 탐색을 이용할 경우 범위의 탐색에 O(log_2(N))의 시간 복잡도를, 검사하는데 O(N)의 시간 복잡도를 사용한다. 따라서 총 O(N \* log_2(N))의 시간 복잡도를 사용한다.

정렬을 사용할 경우 O(N \* log_2(N))을 사용한다.

카운팅 정렬을 이용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

이분 탐색, 정렬에 별도의 공간 복잡도를 사용하지 않으므로 O(1)의 공간 복잡도를 사용한다.

(정렬의 경우 변경될 수 있음)

카운팅 정렬의 경우 O(N)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      9       | O(N \* log_2(N)) |    O(1)     |

특정 h에 대해서 valid한지 검사는 다음과 같이 진행할 수 있다.

- 원소의 배열중 h이상의 값이 h개 이상 나타나는지 여부

따라서 정답으로 가능한 h는 0부터 배열의 크기만큼이다.

이 구간을 이분탐색으로 찾고, 매 구간마다 배열을 순회해 valid여부를 체크한다.

```cpp
bool isValid(int h, vector<int>& citations) {
  int count = 0;
  for (int& c : citations) {
    if (c >= h) count++;
  }
  return count >= h;
}

int hIndex(vector<int>& citations) {
  int size = citations.size();

  int left = 0, right = size + 1;
  int answer = 0;
  while (left < right) {
    int mid = left + (right - left) / 2;

    if (isValid(mid, citations)) {
      // pick right part
      answer = mid;
      left = mid + 1;
    } else {
      // pick left part
      right = mid;
    }
  }

  return answer;
}
```

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      8       | O(N \* log_2(N)) |    O(1)     |

배열의 원소를 내림차순으로 정렬한다.

이후 i번째 값이 i보다 작기 전 까지 정답을 증가시킨다.

이는 원소의 배열중 h이상의 값이 h개 이상 나타나는지에 대해서 정렬된 원소의 경우 한번의 순회로 판단이 가능하기 때문이다.

이를 구현하면 다음과 같다.

```cpp
int hIndex(vector<int>& citations) {
  int size = citations.size();
  sort(citations.begin(), citations.end(), greater<int>());

  int answer = 0;
  for (int i = 0; i < size; i++) {
    if (i + 1 <= citations[i]) {
      answer++;
      continue;
    }
    break;
  }

  return answer;
}
```

### 카운팅 정렬

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(N)     |    O(N)     |

문제에서 결국 배열의 원소의 값이 N을 넘어서는 경우는 무시해도 된다. (N으로 치환해도 똑같음)

따라서 카운팅 정렬을 사용할 수 있다.

카운팅 정렬을 수행한 이후 정렬 방법과 마찬가지로 h인 값이 h개 이상 나타나는지 여부를 판단한다.

이 때 N부터 0까지 순회하며 해당 값의 count를 증가시키는 방향으로 구현한다.

```cpp
int hIndex(vector<int>& citations) {
  int size = citations.size();
  vector<int> counting(size + 1, 0);

  for (int& c : citations) {
    counting[min(c, size)]++;
  }

  int answer = 0;
  int sum = 0;
  for (int i = size; i >= 1; i--) {
    sum += counting[i];
    if (sum >= i) {
      answer = i;
      break;
    }
  }

  return answer;
}
```

## 고생한 점
