# 281. Zigzag Iterator

[링크](https://leetcode.com/problems/zigzag-iterator/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

두 벡터의 원소의 개수를 N이라 하자.

처음에 zigzag로 원소를 별도의 배열에 삽입하고 이후 next, hasNext를 구현하는 경우 시간 복잡도는 O(N)이다.

index만을 이용할 경우 시간 복잡도는 O(1)이다.

### 공간 복잡도

입력받은 vector를 저장 사용할 경우 별도의 공간이 필요하므로 O(N)의 공간 복잡도가 필요하다.

이는 값을 미리 zigzag로 queue에 삽입하는 경우 또한 마찬가지이다.

iterator를 사용할 경우 O(1)의 공간 복잡도로 풀이가 가능하다.

### two pointer

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(1)     |    O(N)     |

두 벡터의 현재 index와 size를 저장한다. 그리고 현재 값을 뽑아낼 벡터가 어느 벡터인지를 나타내는 변수를 갖는다.

이후 next마다 현재 벡터에서 값을 뽑아내며 index를 이동시킨다.

그리고 다음 벡터에서 값을 뽑아내도록 toggle하며 다음 벡터가 유효하지 않은경우 toggle을 다시 수행한다.

```cpp
class ZigzagIterator {
 private:
  vector<int> indexes = {0, 0};
  vector<int> sizes;
  int vIndex = 0;

  vector<vector<int>> array;

 public:
  bool canCurIndex(int index) {
    if (indexes[index] == sizes[index]) return false;
    return true;
  }

  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    sizes.emplace_back(v1.size());
    array.emplace_back(v1);

    sizes.emplace_back(v2.size());
    array.emplace_back(v2);

    if (canCurIndex(0)) {
      vIndex = 0;
    } else if (canCurIndex(1)) {
      vIndex = 1;
    }
  }

  int next() {
    int ret;
    int before = vIndex;

    ret = array[vIndex][indexes[vIndex]];
    indexes[vIndex]++;
    vIndex = (vIndex + 1) % 2;

    if (!canCurIndex(vIndex)) vIndex = (vIndex + 1) % 2;

    return ret;
  }

  bool hasNext() {
    if (!canCurIndex(0) && !canCurIndex(1)) return false;
    return true;
  }
};
```

### queue with value

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(N)     |    O(N)     |

처음에 queue에 값을 zigzag로 순회한대로 집어넣는다.

```cpp
class ZigzagIterator {
 private:
  queue<int> q;

 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    int index1 = 0, index2 = 0;
    int size1 = v1.size(), size2 = v2.size();

    while (index1 < size1 || index2 < size2) {
      if (index1 < size1) {
        q.push(v1[index1]);
        index1 += 1;
      }
      if (index2 < size2) {
        q.push(v2[index2]);
        index2 += 1;
      }
    }
  }

  int next() {
    int cur = q.front();
    q.pop();
    return cur;
  }

  bool hasNext() {
    return !q.empty();
  }
};
```

### queue with iterator range

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      12      |    O(1)     |    O(1)     |

큐에 입력받은 벡터 v1, v2의 iterator의 시작과 끝을 삽입한다.

이후에 next연산을 수행할 때마다 현재 range를 갱신한 값 (begin을 한칸 next)을 range로 삽입한다.

이 range들은 next마다 pop되고 새로 push되므로 만약 queue가 비는 경우는 두 벡터의 값을 모두 순회한 경우이다.

```cpp
class ZigzagIterator {
 private:
  queue<pair<vector<int>::iterator, vector<int>::iterator>> q;

 public:
  ZigzagIterator(vector<int>& v1, vector<int>& v2) {
    if (v1.size() != 0) {
      q.push(make_pair(v1.begin(), v1.end()));
    }
    if (v2.size() != 0) {
      q.push(make_pair(v2.begin(), v2.end()));
    }
  }

  int next() {
    auto beginIt = q.front().first;
    auto endIt = q.front().second;
    q.pop();

    if (beginIt + 1 != endIt) {
      q.push(make_pair(beginIt + 1, endIt));
    }

    return *beginIt;
  }

  bool hasNext() {
    return !q.empty();
  }
};
```

## 고생한 점
