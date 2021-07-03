# 658. Find K Closest Elements

[링크](https://leetcode.com/problems/find-k-closest-elements/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

배열의 모든 원소의 개수를 N이라 하자.

문제에 주어진 조건대로 k개의 우선순위를 뽑기 위해 정렬을 이용할 경우 O(N \* log_2(N))의 시간 복잡도가 필요하다.

또한 배열의 각각의 distance를 계산해 볼 경우 2차원 그래프와 유사한것을 알 수 있다.

따라서 거리가 가장 작아지는 index를 갖는 k개의 range를 찾는 문제로 변환할 수 있다.

해당 index를 빠르게 찾기 위해 이분 탐색을 사용할 수 있다. 이에 O(log_2(N))의 시간 복잡도가 소요된다.

이후 range를 찾는데 슬라이딩 윈도우를 사용할 수도 있고 index를 이용해 찾을수도 있다.

이때 answer 배열을 만들 때 O(N)의 시간 복잡도가 소요되므로 최종 시간 복잡도는 O(N)이다.

### 공간 복잡도

정답 배열을 만들기 위해 O(N)의 공간이 필요하다.

정렬을 이용할 경우 O(N)의 공간이 필요하다.

이분 탐색을 이용할 경우 별도의 공간이 필요하지 않다.

### 정렬

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      68      | O(N \* log_2(N)) |    O(N)     |

문제에서 주어진 대로 정렬을 이용해 구현한다.

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  vector<int> dataArray;
  for (int num : arr) {
    dataArray.push_back(num);
  }

  sort(dataArray.begin(), dataArray.end(), [&x](int& a, int& b) { return (abs(a - x) < abs(b - x)) || (abs(a - x) == abs(b - x) && a < b); });

  vector<int> answer = {dataArray.begin(), dataArray.begin() + k};
  sort(answer.begin(), answer.end());
  return answer;
}
```

구조체를 이용할 경우 다음과 같이 구현할 수 있다.

```cpp
struct Data {
  int diff, origin;

  bool operator<(const Data& b) {
    if (diff < b.diff || diff == b.diff && origin < b.origin) return true;
    return false;
  }
};

vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  vector<Data> dataArray;
  for (int num : arr) {
    dataArray.push_back({abs(num - x), num});
  }
  sort(dataArray.begin(), dataArray.end());

  vector<int> answer;
  for (int i = 0; i < k; i++) {
    answer.push_back(dataArray[i].origin);
  }

  sort(answer.begin(), answer.end());
  return answer;
}
```

### 이분 탐색 & 슬라이딩 윈도우

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |    O(N)     |    O(1)     |

(정답을 생성할 때의 공간 복잡도는 제외함)

문제에서 주어진 조건대로라면 각 원소마다 distance는 2차 방정식과 비슷하게 나타난다.

따라서 range의 중앙점을 이분탐색으로 찾은 뒤 해당 중앙점부터 왼쪽과 오른쪽의 범위를 하나하나 늘려가며 range를 완성한다.

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  int size = arr.size();
  if (k == size) return arr;

  int left = 0, right = size - 1, mid = 0;
  while (left <= right) {
    mid = (left + right) / 2;

    if (arr[mid] > x) {
      right = mid - 1;
    } else if (arr[mid] < x) {
      left = mid + 1;
    } else if (arr[mid] == x) {
      break;
    }
  }

  left = max(0, mid - 1), right = left + 1;
  while (right - left - 1 < k) {
    if (left == -1) {
      right += 1;
      continue;
    }
    if (right == size) {
      left -= 1;
      continue;
    }

    if (abs(arr[left] - x) <= abs(arr[right] - x)) {
      left -= 1;
    } else {
      right += 1;
    }
  }

  vector<int> answer;
  for (int i = left + 1; i < right; i++) {
    answer.push_back(arr[i]);
  }
  return answer;
}
```

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      32      |    O(N)     |    O(1)     |

이분탐색을 진행하며 range범위 자체에 대해서 이분탐색을 진행할 수 있다.

이분 탐색을 이용해서 시작점을 찾고, 시작점 + k index의 점을 range의 끝점으로 설정한다.

중앙점 왼쪽에 있는 값의 distance와 중앙점 오른쪽에 있는 값의 distance를 비교하고 값을 업데이트한다.

- 왼쪽 값의 distance가 더 큰 경우 왼쪽을 이동
- 오른쪽 값의 distance가 더 큰 경우 오른쪽을 이동

여기서 왼쪽 값과 오른쪽 값의 distance를 구할 때 절대값으로 구하지 않는다.

이는 range의 mid를 구할 때 mid 왼쪽에 있는 값은 x 이하로, 오른쪽에 있는 값은 x 이상으로 구성하려 하기 때문이다.

```cpp
vector<int> findClosestElements(vector<int>& arr, int k, int x) {
  int size = arr.size();
  if (k == size) return arr;

  int left = 0, right = size - k;
  while (left < right) {
    int mid = (left + right) / 2;

    if (x - arr[mid] > arr[mid + k] - x) {
      left = mid + 1;
    } else {
      right = mid;
    }
  }

  vector<int> answer;
  for (int i = left; i < left + k; i++) {
    answer.push_back(arr[i]);
  }
  return answer;
}
```

## 고생한 점
