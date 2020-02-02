# 11279. 최대 힙

[링크](https://www.acmicpc.net/problem/11279)

|  난이도   | 정답률(\_%) |
| :-------: | :---------: |
| Silver II |     42      |

## 설계

### heap

![heap](https://upload.wikimedia.org/wikipedia/commons/thumb/3/38/Max-Heap.svg/220px-Max-Heap.svg.png)

값들의 대소 관계는 부모와 자식 노드 간에만 존재한다.

시간 복잡도는 log(n) 이다.

### heap 자료구조

```cpp
long long heap[100002];
int heap_size = 0;
```

### 최소 heap

#### heap 삭제 연산

루트 노드의 값을 삭제하고, 힙의 맨 마지막 노드의 값을 루트에 넣은 뒤 갱신한다.

```cpp
void heap_delete() {
  int current, left, right;

  heap[1] = heap[heap_size];
  heap[heap_size] = 0;
  heap_size -= 1;

  if (heap_size == 0) {
    return;
  }

  current = 1;
  while (true) {
    left = current * 2;
    right = current * 2 + 1;

    if (left > heap_size) {
      break;
    }

    // if it has only left node
    if (right > heap_size) {
      if (heap[left] < heap[current]) {   // 변경점
        swap(heap[left], heap[current]);
        current = left;
        continue;
      }
    }
    // if it has two node
    else {
      if (heap[left] <= heap[right]) {   // 변경점
        if (heap[left] < heap[current]) {   // 변경점
          swap(heap[left], heap[current]);
          current = left;
          continue;
        }
      }
      else {
        if (heap[right] < heap[current]) {   // 변경점
          swap(heap[right], heap[current]);
          current = right;
          continue;
        }
      }
    }

    if (current == left / 2) {
      break;
    }
  }

  return;
}
```

#### heap push 연산 (최소 힙)

힙의 맨 마지막에 새로운 값을 넣고, 부모노드와 비교하며 갱신한다.

```cpp
void heap_push(int input) {
  heap_size += 1;
  heap[heap_size] = input;

  int current = heap_size, parent;

  while (true) {
    if (current == 1) break;

    parent = current / 2;

    if (heap[current] < heap[parent]) {   // 변경점
      swap(heap[parent], heap[current]);
    }
    else {
      break;
    }
    current = parent;
  }
}
```

### 최대 힙

위 식에서 주석처리한 부분의 등호를 변경하면 최대 힙이 된다.

### 우선순위 큐

우선순위 큐의 경우 heap으로 이루어져 있다.

```cpp
priority_queue<int> pq; // 우선순위 큐 선언

cin >> input;

switch(input){
  case 0:{
    if (pq.empty()) {   // queue가 비어있을 경우 0 출력
      cout << "0\n";
    } else {
      // 가장 위에 들어가있는 값을 출력
      cout << pq.top() << "\n";
      pq.pop();
    }
  }
  case 1:{
    pq.push(x); // 입력한 숫자 queue에 삽입
  }
}
```

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
|  12 ms  |           |

## 고생한 점
