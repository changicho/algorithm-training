# 1850. Minimum Adjacent Swaps to Reach the Kth Smallest Number

[링크](https://leetcode.com/problems/minimum-adjacent-swaps-to-reach-the-kth-smallest-number/)

| 난이도 |
| :----: |
| Medium |

## 설계

### 시간 복잡도

문자열 N의 크기는 최대 1,000 이다.

next_permutation의 횟수의 최대 값은 1,000이다.

next_permutation 연산에 소요되는 시간 복잡도는 O(N) 이므로 k번째 숫자를 찾는 데 들어가는 시간 복잡도는 O(N \* K) 이다.

이후 원본 문자와 k번째 문자를 같게 하기 위해서 문자를 이동해야 한다.

문자는 서로 붙어있는 것끼리만 이동 가능하므로 앞자리 부터 채워나가면서 이동의 횟수를 센다. (그리디 알고리즘)

이는 맨 앞 문자를 채우면서 흐뜨러지는 상태를 미리 만들어 놓아야 뒷 문자를 채운 것이 섞이지 않기 때문이다.

이 경우 시간 복잡도는 O(N^2)이다.

### 공간 복잡도

원본 문자열을 알고 있어야 하므로 O(N)의 공간 복잡도가 필요하다.

### 탐욕 알고리즘

| 내 코드 (ms) | 시간 복잡도 | 공간 복잡도 |
| :----------: | :---------: | :---------: |
|      20      |   O(N^2)    |    O(N)     |

k번째 수를 구하는것은 next_permutation을 이용해 구현할 수 있다.

```cpp
for (int i = 0; i < k; i++) {
  next_permutation(num.begin(), num.end());
}
```

이후 원본 문자열을 k번째 문자열로 만들기 위해 그리디 알고리즘을 이용해 찾는다.

맨 앞자리부터 위치를 순회한다.

만약 현재 상태 start와 target의 현재 위치값이 다른 경우 start에서 가장 가까운 target의 현재 위치값과 같은 값을 찾는다.

해당 값을 앞으로 한칸씩 이동시키며 target과 일치시킨다. (인접한 값들끼리 swap하면서)

이 과정은 해당 문자를 원래 위치로 옮기는 최소한의 이동이며 이는 인접한 스왑만으로 원래 위치로 가져 오는 다른 방법이 없기 때문이다.

즉 남은 문자열의 길이가 L이라고 한다면 현재 위치를 맞춘 뒤에는 L-1의 문자열에 대해 똑같은 연산을 수행하는 것으로 이해할 수 있다.

```cpp
int countSwaps(string current, string target) {
  int length = current.length();
  int index = 0;
  int count = 0;

  while (index < length) {
    int from = index;

    if (current[index] != target[index]) {
      // find first index that target[index] == current[from]
      from = current.find(target[index], index);
    }

    for (int i = from; i > index; i--) {
      swap(current[i], current[i - 1]);
      count += 1;
    }

    index++;
  }
  return count;
}

int getMinSwaps(string num, int k) {
  string original = num;

  for (int i = 0; i < k; i++) {
    next_permutation(num.begin(), num.end());
  }

  return countSwaps(num, original);
}
```

## 고생한 점
