# 251. Flatten 2D Vector

[링크](https://leetcode.com/problems/flatten-2d-vector/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

모든 원소의 개수를 N이라고 하자.

모든 원소를 순회하며 flatten한 뒤 next와 hasNext를 구성할 수 있다.

이 경우 미리 다른 자료구조에 flatten하므로 시간 복잡도는 O(N)이며 next, hasNext연산에 시간 복잡도는 O(1)이다.

혹은 iterator, index를 이용해 매번 움직일 수 있다.

이 경우 빈 배열을 만났을 때 유효한 iterator, index로 이동해야 한다.

이 경우 초기 설정에 시간 복잡도는 O(1)이며 next에 최악의 경우 O(N)의 시간복잡도가 소요된다.

### 공간 복잡도

별도의 자료구조에 값을 저장하고 사용하는 경우 O(N)의 공간 복잡도가 필요하다.

iterator 이용하는 경우 해당 데이터의 iterator를 그대로 이용하면 되므로 별도의 공간 복잡도를 사용하지 않는다.

그 외에 입력받은 vector를 그대로 저장할 경우 O(N)의 공간 복잡도가 필요하다.

### queue

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(N)     |

입력받은 vector를 순회하며 값을 순서대로 queue에 저장한다.

이후 queue를 pop하거나 비었는지 검사한 값을 반환한다.

```cpp
class Vector2D {
 private:
  queue<int> q;

 public:
  Vector2D(vector<vector<int>>& vec) {
    for (vector<int>& cur : vec) {
      for (int num : cur) {
        q.push(num);
      }
    }
  }

  int next() {
    int ret = q.front();
    q.pop();

    return ret;
  }

  bool hasNext() {
    return !q.empty();
  }
};
```

### iterator

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      16      |    O(N)     |    O(1)     |

입력받은 vector의 begin과 end를 미리 저장해놓는다.

이때 next, hasNext를 수행할 때마다 유효한 iterator를 찾아야하므로 trim을 수행해준다.

(빈 배열이 있는 경우 건너뜀)

이 과정에서 최악의 경우 (빈 배열이 연속해서 나오는 경우) next를 수행할 때 O(N)의 시간 복잡도가 필요하다.

```cpp
class Vector2D {
  vector<vector<int>>::iterator outer, iEnd;
  int inner = 0;

  void trimIterator() {
    while (outer != iEnd && inner == (*outer).size()) {
      outer++;
      inner = 0;
    }
  }

 public:
  Vector2D(vector<vector<int>>& vec2d) {
    outer = vec2d.begin();
    iEnd = vec2d.end();
  }

  int next() {
    trimIterator();
    int ret = (*outer)[inner];
    inner++;
    return ret;
  }

  bool hasNext() {
    trimIterator();
    return outer != iEnd;
  }
};
```

### index

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      24      |    O(N)     |    O(N)     |

iterator대신 index를 이용한 방법으로 변경한다.

```cpp
class Vector2D {
 private:
  int outer = 0, inner = 0;
  vector<vector<int>> array;

  void trimIndex() {
    while (outer != array.size() && inner == array[outer].size()) {
      outer++;
      inner = 0;
    }
  }

 public:
  Vector2D(vector<vector<int>>& vec) {
    array = vec;
  }

  int next() {
    trimIndex();
    int ret = array[outer][inner];
    inner += 1;
    return ret;
  }

  bool hasNext() {
    trimIndex();
    return outer < array.size();
  }
};
```

## 고생한 점
