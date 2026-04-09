# 379. Design Phone Directory

[링크](https://leetcode.com/problems/design-phone-directory/description/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

입력받은 slot의 크기를 N이라 하자.

hash set을 이용할 경우 각 연산마다 O(1)의 시간 복잡도를 사용한다.

### 공간 복잡도

hash set의 크기에 O(N)의 공간 복잡도를 사용한다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      8       |    O(1)     |    O(N)     |

0부터 maxNumbers-1까지 슬롯을 hash set에 관리하며

각 경우마다 hash set을 이용해 빈 값과 있는 값들을 반환, 확인한다.

(작은 수부터 반환하는 조건이 테스트케이스에 있는것으로 보이는데 문제 조건이 이상함)

```cpp
class PhoneDirectory {
 private:
  unordered_set<int> us;

 public:
  PhoneDirectory(int maxNumbers) {
    for (int i = 0; i < maxNumbers; i++) {
      us.insert(i);
    }
  }

  int get() {
    if (us.empty()) return -1;
    int target = *us.begin();
    us.erase(target);
    return target;
  }

  bool check(int number) {
    if (us.count(number) > 0) {
      return true;
    }
    return false;
  }

  void release(int number) { us.insert(number); }
};
```

## 고생한 점
