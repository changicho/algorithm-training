# 11286. 절댓값 힙

[링크](https://www.acmicpc.net/problem/11286)

|  난이도  | 정답률(\_%) |
| :------: | :---------: |
| Silver I |   54.715    |

## 설계

### 시간 복잡도

문제에서 만들고자 하는 자료구조는 힙이다.

따라서 우선순위 큐를 이용한 큐를 만들어 제작한다.

N은 최대 100,000까지이다. 각 연산마다 쿼리를 log(N) 이내로 수행하지 않는 경우, 시간 복잡도는 O(N^2) 가 되어 제한시간 내에 불가능하다.

따라서 힙에 삽입과 쿼리는 log(N) 이내에 수행해야한다.

### 공간 복잡도

입력되는 정수는 -2^31보다 크고, 2^31보다 작으므로 int형으로 선언해도 충분하다.

절대값과 원본값을 같이 비교해야 하므로 다음과 같은 자료구조를 선언한다.

```cpp
struct Data {
  int abs, value;
};
```

### 우선순위 큐를 이용한 힙

STL queue 의 priority_queue를 이용한 방법은 다음두가지가 존재한다.

구조체를 구현해 사용하는 경우 operator를 직접 구현해야 한다.

방법 1 : compare 구조체 사용

```cpp
struct Data {
  int abs, value;
};

struct compare {
  bool operator()(Data a, Data b) {
    if (a.abs != b.abs) {
      return a.abs > b.abs;
    }
    return a.value > b.value;
  }
};

priority_queue<Data, vector<Data>, compare> pq;
```

방법 2 : operator를 오버로딩

```cpp
struct Data {
  int abs, value;
};

bool operator<(Data a, Data b) {
  if (a.abs != b.abs) {
    return a.abs > b.abs;
  }
  return a.value > b.value;
}

priority_queue<Data> pq;
```

방법 3 : 구조체에 직접 operator 선언

```cpp
struct Data {
  int abs, value;

  bool operator<(const Data &b) const {
    if (abs != b.abs) {
      return abs > b.abs;
    }
    return value > b.value;
  }
};

priority_queue<Data> pq;
```

## 정리

| 내 코드 (ms) | 빠른 코드 (ms) |
| :----------: | :------------: |
|      16      |       8        |

## 고생한 점
