# 881. Boats to Save People

[링크](https://leetcode.com/problems/boats-to-save-people/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

people의 크기를 N이라 하자.

각 사람들을 두명씩 짝지었을 때 가능한지, 불가능한지를 판단하며 정답을 구할 경우 경우의 수는 N^2이다. 이는 제한시간 내에 불가능하다.

정렬 후 각 사람마다 최적의 값을 이분탐색을 이용해 풀이할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

정렬 후 투 포인터를 사용할 수 있다. 이 경우 O(N \* log_2(N))의 시간 복잡도가 소요된다.

### 공간 복잡도

정렬 후 별도의 배열등을 사용할 경우 O(N)의 공간 복잡도를 사용한다.

### 정렬 & 투 포인터

| 내 코드 (ms) |   시간 복잡도    | 공간 복잡도 |
| :----------: | :--------------: | :---------: |
|      96      | O(N \* log_2(N)) |    O(1)     |

각 인원의 몸무게를 오름차순으로 정렬한다.

한 보트에 두 사람을 태울 수 있다.

따라서 하나의 보트에 사람을 한명 태웠을 때, 남은 인원중에서 가장 최적의 인원을 찾을 수 있다.

만약 정렬 후 가장 무거운 사람과 가장 가벼운 사람들을 순회하며 합이 limit보다 작거나 같다면 이 두 사람은 같은 보트에 태울 수 있다.

각 과정에서 현재 남은 공간에 태울 수 있는 최대 인원을 찾기 위해 순회를 진행한다.

무거운 사람, 가벼운 사람에 대한 index를 각각 right, left라 하자.

right를 감소시키며 순회하고 각 과정에서 현재 무거운 사람을 태웠을 때 가벼운 사람을 태울 수 있는지 판단한다.

각 과정에서 이미 현재 right보다 무거운 사람들은 이미 순회가 끝났으므로 left에 대해 정답을 구한다.

해당 과정에서 left와 right가 같아지 않을 때 까지 반복한다.

```cpp
int numRescueBoats(vector<int>& people, int limit) {
  int size = people.size();
  sort(people.begin(), people.end());

  int answer = size;
  int left = 0, right = size - 1;
  while (left < right) {
    int person = people[right];

    if (person <= limit - people[left]) {
      left++;
      answer--;
    }
    right--;
  }
  return answer;
}
```

## 고생한 점
