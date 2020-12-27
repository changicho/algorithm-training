# 15666. N과 M (12)

[링크](https://www.acmicpc.net/problem/15666)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |   81.718    |

## 설계

### 시간 복잡도

N과 M이 주어진다. (1 ≤ M ≤ N ≤ 8)

N은 최대 8이며, M또한 최대 8 이므로 가능한 경우의 수는 8^8 = 16,777,216 이다.

여기에 각 경우마다 오름차순인지 검사하는데 M번 만큼의 시간복잡도가 소요되므로, 최악의 경우 시간 복잡도는

O(134,217,728) 이므로 제한시간 내에 불가능하다.

따라서 탐색에서 불가능한 경우는 백트래킹을 이용해 탐색을 중지해야 한다.

### 공간 복잡도

입력받는 숫자는 전부 10,000 이하의 자연수이다. 따라서 int형으로 선언한다.

### 중복되는 경우를 제외

중복되는 경우를 제외하기 위해서 입력받은 숫자들 중에서 중복된 것들을 제거하고 탐색을 진행한다.

```cpp
sort(arr.begin(), arr.end());
arr.erase(unique(arr.begin(), arr.end()), arr.end());
```

오름차순으로 탐색해야 하므로 입력받은 숫자들을 오름차순으로 정렬한다.

탐색 시에는 현재 마지막 수보다 큰 수만 탐색하면 되므로, 시작 위치를 정해준다.

```cpp
void recursive(vector<int> numbers, int index) {
  if (numbers.size() == M) {
    for (int number : numbers) {
      cout << number << " ";
    }
    cout << "\n";

    return;
  }

  numbers.push_back(-1);

  int size = numbers.size();
  int before = size > 1 ? numbers[size - 2] : -1;

  for (int i = index; i < arr.size(); i++) {
    int number = arr[i];

    numbers[size - 1] = number;
    recursive(numbers, i);
  }
}
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      0       |       0        |

## 고생한 점
