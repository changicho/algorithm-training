# 167. Two Sum II - Input array is sorted

[링크](https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

배열의 요소의 최대 개수는 3 \* 10^4 이다.

브루트 포스의 경우 O(N^2) 이므로 제한시간 내에 불가능하다.

따라서 투 포인터, map을 이용해 O(N) 이내에 해결해야 한다.

### 공간 복잡도

map을 이용하는 경우 각 숫자의 index를 저장해야 하기 때문에 O(N)의 공간 복잡도가 필요하다.

### map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(N)     |

모든 숫자에 대해서 map을 생성한다.

- key : 값
- value : index

map을 생성한 뒤 맨 처음 index부터 순회하며 target - 해당 숫자 가 map에 저장되어 있는지판단한다.

정답은 유일하게 하나가 존재하는것이 보장되므로 정답이 맞는 경우 return한다.

```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
  map<int, int> m;
  vector<int> answer;
  int size = numbers.size();

  for (int i = 0; i < size; i++) {
    int number = numbers[i];
    m[number] = i + 1;
  }

  for (int i = 0; i < size; i++) {
    int number = numbers[i];
    if (m[target - number] != 0) {
      answer = {i + 1, m[target - number]};
      return answer;
    }
  }
  return answer;
}
```

### 투 포인터

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      0       |    O(N)     |    O(1)     |

맨 왼쪽과 맨 오른쪽 인덱스를 변경해가며 탐색한다.

두 인덱스의 숫자의 합이 target보다 작은 경우 왼쪽 인덱스를 증가시키고 (합을 더 크게 만들고)

target보다 큰 경우 오른쪽 인덱스를 감소시킨다. (합을 더 작게 만든다)

정답은 유일하게 하나가 존재하는것이 보장되므로 정답이 맞는 경우 return한다.

```cpp
vector<int> twoSum(vector<int>& numbers, int target) {
  vector<int> answer;
  int size = numbers.size();

  int first = 0;
  int second = numbers.size() - 1;

  while (first < second) {
    if (numbers[first] + numbers[second] == target) {
      answer = {first + 1, second + 1};
      return answer;
    } else if (numbers[first] + numbers[second] > target) {
      second--;
    } else {
      first++;
    }
  }

  return answer;
}
```

## 고생한 점
