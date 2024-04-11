# 1700. Number of Students Unable to Eat Lunch

[링크](https://leetcode.com/problems/number-of-students-unable-to-eat-lunch/description/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

students, sandwiches 배열의 크기를 N이라 하자.

시뮬레이션을 사용할 경우 O(N)의 시간 복잡도를 사용한다.

### 공간 복잡도

큐로 직접 시뮬레이션을 수행할 경우 O(N)의 공간 복잡도를 사용한다.

### 시뮬레이션

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      3       |    O(N)     |    O(N)     |

students, sandwiches를 각각 큐로 만든다.

이후 문제 조건에 따라 시뮬레이션을 수행한다.

이 때 만약 student 큐를 순회해도 정답이 나오지 않는 경우는 무한 루프에 빠지는 경우이므로 이를 방지한다.

```cpp
int countStudents(vector<int>& students, vector<int>& sandwiches) {
  queue<int> studentQueue, sandwichQueue;
  for (int& s : students) {
    studentQueue.push(s);
  }
  for (int& s : sandwiches) {
    sandwichQueue.push(s);
  }

  int waitCount = 0;
  while (!studentQueue.empty()) {
    if (studentQueue.front() == sandwichQueue.front()) {
      waitCount = 0;
      studentQueue.pop();
      sandwichQueue.pop();
    } else {
      studentQueue.push(studentQueue.front());
      studentQueue.pop();
      waitCount++;
    }

    if (waitCount == studentQueue.size()) break;
  }
  return studentQueue.size();
}
```

## 고생한 점
