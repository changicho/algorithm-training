# 705. Design HashSet

[링크](https://leetcode.com/problems/design-hashset/)

| 난이도 |
| :----: |
|  Easy  |

## 설계

### 시간 복잡도

N을 값의 범위, K를 bucket의 갯수, M을 unique한 값 이라고 하자.

key의 범위는 0부터 1e6까지이다.

값의 범위를 모두 배열로 관리해도 될 정도의 크기이므로 boolean 배열을 사용할 경우 O(1)의 시간 복잡도로 모든 연산을 수행 가능하다.

연결 리스트를 이용해 구현할 경우 모든 값이 버켓에 나뉘어 있을 수 있으므로 평균 O(N / K)의 시간 복잡도를 사용한다.

### 공간 복잡도

모두 배열로 관리할 경우 O(1e6)의 공간 복잡도를 사용한다.

연결 리스트를 사용할 경우 hash set에 저장되는 값을 총 M개라고 할 때 O(M)만큼의 공간 복잡도를 사용한다.

### 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     126      |    O(1)     |   O(1e6)    |

배열로 범위만큼 크기의 공간을 선언한뒤 관리한다.

```cpp
class MyHashSet {
 private:
  bool us[1000001] = {
      false,
  };

 public:
  MyHashSet() {}

  void add(int key) { us[key] = true; }

  void remove(int key) { us[key] = false; }

  bool contains(int key) { return us[key]; }
};
```

### 연결리스트 & 버킷

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     157      |  O(N / K)   |  O(K + M)   |

hash 함수를 생성한 뒤, 각 key를 해시로 변경한 값에 연결리스트로 이어붙인다.

이후 삭제와 검색에는 해당 해시값의 연결리스트에서 삭제, 검색을 수행한다.

이를 구현하면 다음과 같다.

```cpp
class MyHashSet {
 private:
  const static int size = 19997;
  const int mult = 12582917;

  list<int> data[size];

  int hashFunction(int key) { return (int)((long)key * mult % size); }

 public:
  void add(int key) {
    if (contains(key)) return;

    int hashValue = hashFunction(key);
    data[hashValue].push_back(key);
  }

  bool contains(int key) {
    int hashValue = hashFunction(key);
    auto it = data[hashValue].begin();

    while (it != data[hashValue].end()) {
      if (*it == key) return true;
      it++;
    }

    return false;
  }

  void remove(int key) {
    int hashValue = hashFunction(key);
    auto it = data[hashValue].begin();

    while (it != data[hashValue].end()) {
      if (*it == key) {
        data[hashValue].erase(it);
        break;
      }
      it++;
    }
  }
};
```

## 고생한 점
