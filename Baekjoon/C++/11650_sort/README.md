# 11650. 좌표 정렬하기

[링크](https://www.acmicpc.net/problem/11650)

난이도\_50%

## 정리

내 코드 : 48 ms;

우선 순위가 x좌표, 그리고 y좌표 순 이므로 x좌표, y좌표 각각을 비교해야 한다.
구조체 axis로 x,y 좌표의 묶음을 만들고 vector로 좌표들을 입력받았다.

sort 함수를 이용해 정렬을 수행. 따라서 compare 함수를 직접 만들었다.

```cpp
bool compare(axis a, axis b) {
    if (a.x < b.x) {
        return true;
    }

    if (a.x == b.x && a.y < b.y) {
        return true;
    }

    return false;
}
```

굉장히 재밌었던 문제였다.
