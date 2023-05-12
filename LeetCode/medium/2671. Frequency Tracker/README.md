# 2671. Frequency Tracker

[링크](https://leetcode.com/problems/frequency-tracker/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 원소의 수를 N이라 하자.

count와 빈도에 대한 두 개의 hash map을 이용하고 push, delete 연산마다 이를 조정한다.

이 경우 각 연산마다 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

총 N개의 수를 저장할 수 있어야 하므로 O(N)의 공간 복잡도를 사용한다.

### hash map

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     554      |    O(1)     |    O(N)     |

다음과 같은 두개의 hash map을 사용한다.

- key : 숫자, value : 빈도
- key : 빈도, value : 숫자

각 경우마다 add, delete 시에 빈도가 변경하므로 두개의 hash map을 업데이트한다.

이를 구현하면 다음과 같다.

```cpp
class FrequencyTracker {
 private:
  unordered_map<int, int> counts;
  unordered_map<int, unordered_set<int>> keyByFreq;

 public:
  void add(int number) {
    int before = counts[number];
    counts[number]++;

    keyByFreq[before].erase(number);
    keyByFreq[counts[number]].insert(number);
  }

  void deleteOne(int number) {
    if (counts[number] == 0) return;

    int before = counts[number];
    counts[number]--;

    keyByFreq[before].erase(number);
    keyByFreq[counts[number]].insert(number);
  }

  bool hasFrequency(int frequency) { return keyByFreq[frequency].size() > 0; }
};
```

## 고생한 점
