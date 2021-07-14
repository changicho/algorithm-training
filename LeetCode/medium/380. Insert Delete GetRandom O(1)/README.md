# 380. Insert Delete GetRandom O(1)

[링크](https://leetcode.com/problems/insert-delete-getrandom-o1/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

저장된 원소의 개수를 N이라 하자.

hash map을 이용해 삽입과 삭제 연산의 시간 복잡도를 줄일 수 있다.

getRandom함수에서 최적화 하기 위해서 빠르게 특정 위치의 값에 방문하는 방법이 필요하다.

이를 맨 앞부터 순차적으로 방문하는 경우 O(N)의 시간 복잡도가 소요된다.

배열을 이용해 값들을 저장하고 사용하는 경우 O(1)의 시간 복잡도로 방문 가능하다.

### 공간 복잡도

원소들을 저장해야 하므로 O(N)의 공간 복잡도가 필요하다.

### hash set

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     244      |    O(N)     |    O(N)     |

- 삽입 : O(1)
- 삭제 : O(1)
- 랜덤 : O(N)

삽입과 삭제는 hash set으로 구현하며, 임의의 값을 찾기 위해 iteration을 순차적으로 방문한다.

```cpp
unordered_set<int> us;

bool insert(int val) {
  if (us.count(val) > 0) return false;
  us.insert(val);
  return true;
}

bool remove(int val) {
  if (us.count(val) == 0) return false;
  us.erase(val);
  return true;
}

int getRandom() {
  int count = rand() % us.size();
  auto it = next(us.begin(), count);

  return *it;
}
```

### hash set & 배열

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     208      |    O(1)     |    O(N)     |

- 삽입 : O(1)
- 삭제 : O(1)
- 랜덤 : O(1)

hash map과 배열을 이용해 임의의 값을 찾을 때 index를 이용해 빨리 접근 하도록 구성한다.

삽입시에 map에는 값과 현재 배열의 크기를 저장하며, 배열에는 해당 값을 저장한다.

삭제 시에 배열에 유일한 값들만 남아있을 수 있도록 map에 저장된 지울 값의 index를 가져오고

배열의 맨 끝에 있는 값과 바꾼다.

이후 배열의 맨 끝을 pop하면 배열에서 해당값을 삭제할 수 있다.

```cpp
vector<int> numberList;
unordered_map<int, int> hashTable;

bool insert(int val) {
  if (hashTable.find(val) != hashTable.end()) {
    return false;
  }
  hashTable[val] = numberList.size();
  numberList.push_back(val);
  return true;
}

bool remove(int val) {
  if (hashTable.find(val) == hashTable.end()) {
    return false;
  }

  swap(numberList[hashTable[val]], numberList[numberList.size() - 1]);
  numberList.pop_back();

  hashTable[numberList[hashTable[val]]] = hashTable[val];
  hashTable.erase(val);

  return true;
}

int getRandom() {
  return numberList[rand() % numberList.size()];
}
```

## 고생한 점
