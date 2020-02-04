# 2042. 구간 합 구하기

[링크](https://www.acmicpc.net/problem/2042)

|   난이도   | 정답률(\_%) |
| :--------: | :---------: |
| Platinum V |     29      |

## 설계

### 이진 트리 - 인덱스 트리

새로운 값이 부여되지 않고, 기존의 값만 변경되므로 인덱스 트리를 사용했다.

이 때, 인덱스 트리를 생성하기 위해 nums의 사이즈는 N 이상의 가장 작은 2의 제곱수 + 1로 설정한다

인덱스 트리인 trees의 사이즈는 log2(nums.size())를 올림한 값만큼 2를 제곱한 수 + 1로 설정한다.

```cpp
int numSize = pow(2, (int)ceil(log2(N)));
int treeSize = pow(2, (int)ceil(log2(numSize) + 1));

nums.resize(numSize + 1);
tree.resize(treeSize + 1);
```

## 정리

| 내 코드 | 빠른 코드 |
| :-----: | :-------: |
| 148 ms  |           |

## 고생한 점

### 컴파일 에러

백준의 환경에서 ceil과 pow를 사용하므로 math.h를 include한다.

### index 초과

이진 인덱스 트리에 관한 모든 함수는 1~nums.size()-1 의 범위에서 사용한다.

nums,size() - 1 이 한계치인 이유는 앞서 설계에서 nums,size() 맨 뒤에 빈공간을 하나 더 만들어서 사이즈가 하나 더 커졌기 때문이다.
