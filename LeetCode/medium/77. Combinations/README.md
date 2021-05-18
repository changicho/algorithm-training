# 77. Combinations

[링크](https://leetcode.com/problems/combinations/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

조합의 모든 갯수를 구하는 문제이다.

중복된 모든 경우를 탐색할 경우 시간 복잡도는 O(N^K)이다. 이는 제한시간 내에 불가능하므로 백트래킹을 이용한다.

### 공간 복잡도

최악의 경우 공간 복잡도는 O(N^K)이다.

### 재귀호출

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      28      |   O(N^K)    |   O(N^K)    |

재귀 호출을 이용해 조합을 생성할 수 있다.

이때 pointer를 넘기는 경우가 속도가 월등히 빠르다.

또한 숫자가 중복되면 안되므로 이전에 넣은 숫자를 이용해 백트래킹을 수행한다.

```cpp
vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> ret;

  vector<int> array;
  recursive(array, ret, n, k);

  return ret;
}

void recursive(vector<int> &arr, vector<vector<int>> &answer, int n, int k) {
  if (arr.size() == k) {
    answer.push_back(arr);
    return;
  }

  for (int i = arr.empty() ? 1 : arr.back() + 1; i <= n; i++) {
    arr.push_back(i);
    recursive(arr, answer, n, k);
    arr.pop_back();
  }
}
```

### 반복문

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |   O(N^K)    |   O(N^K)    |

위의 재귀호출을 일반 반복문으로 구현할 수 있다.

숫자가 n 이상 증가할 경우 현재 숫자 앞자리가 증가하는 것을 이용한다.

```cpp
vector<vector<int>> combine(int n, int k) {
  vector<vector<int>> ret;
  int index = 0;

  vector<int> array(k, 0);
  while (index >= 0) {
    array[index]++;
    if (array[index] > n) {
      index--;
    } else if (index == k - 1) {
      ret.push_back(array);
    } else {
      index++;
      array[index] = array[index - 1];
    }
  }
  return ret;
}
```

## 고생한 점
