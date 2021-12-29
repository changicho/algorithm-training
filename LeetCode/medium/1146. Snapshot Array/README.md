# 1146. Snapshot Array

[링크](https://leetcode.com/problems/snapshot-array/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

초기에 세팅하는 숫자 length를 N, 쿼리의 갯수를 M이라 하자.

각 경우마다 set, snap을 하고 get하는 경우를 모두 배열로 저장할 경우 다음과 같은 시간 복잡도를 사용한다.

- get : O(1)
- set : O(1)
- snap : O(N \* M)

만약 쿼리에 대해서 변경된 값들만 snap에 저장할 경우 snap_id에 해당하는 값을 빠르게 찾기 위해 이분 탐색을 사용할 수 있다.

이 경우 BST기반으로 동작하므로 시간 복잡도는 다음과 같다.

- get : O(log_2(M))
- set : O(log_2(M))
- snap : O(1)

### 공간 복잡도

모든 경우를 저장할 경우 O(N \* M)의 공간 복잡도를 사용하며 이는 제한 조건을 초과한다.

BST기반으로 snap에 해당하는 값의 변화를 저장할 경우 O(N + M)의 공간 복잡도를 사용한다.

### 이분 탐색

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|     208      | O(log_2(M)) |  O(N + M)   |

각 숫자마다 변화되는 값들을 map에 저장한다.

- key : snap_id
- value : number when snap_id

여기서 snap_id에 따라서 값을 저장하므로 이분 탐색을 이용해 해당 snap_id일때의 값을 찾을 수 있다.

이 때 검색하는 snap_id가 key로 없을 수 있다. (변화가 나중에 일어난 경우)

이 경우는 snap_id 이하의 가장 큰 snap_id에 해당하는 값을 찾으면 된다.

이를 이용하기 위해 upper_bound로 검색한 뒤 해당 iterator 앞에 있는 iterator의 값을 사용한다.

(초과하는 처음 값 앞에있는 값은 snap_id 이하임이 보장되므로)

초기에 snap_id가 0인 경우에 대해서 모든 값을 초기화 해놓을 경우 이후에 upper_bound를 할 때 무조건 하나의 iterator를 찾을 수 있다.

snap 연산시에 snap_id를 증가시키기만 하면 된다. (저장인 이미 map에 되어있으므로)

```cpp
class SnapshotArray {
 private:
  vector<map<int, int>> snapshots;
  int id = 0;

 public:
  SnapshotArray(int length) {
    snapshots.resize(length);

    for (int i = 0; i < length; i++) {
      snapshots[i][0] = 0;
    }
  }

  void set(int index, int val) { snapshots[index][id] = val; }

  int snap() {
    id++;
    return id - 1;
  }

  int get(int index, int snap_id) {
    auto it = snapshots[index].upper_bound(snap_id);
    return prev(it)->second;
  }
};
```

## 고생한 점

map에 snap_id가 0인 경우를 저장하지 않을 경우 upper_bound를 수행할 때 예외 처리를 추가해야 한다.
