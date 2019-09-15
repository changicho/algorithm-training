def solution(phone_book):
    # 사전순으로 정렬
    sorted_phone_book = sorted(phone_book)
    
    # n번째 문자열은 n+1번째 보다 사전순으로 앞이므로, n번째 이후부터는 접두어가 될 수 없다.
    # n번째와 n+1번째를 비교
    for target, number in zip(sorted_phone_book, sorted_phone_book[1:]):

        # 문자열의 startswith 메소드 사용
        if number.startswith(target):
            return False
    
    # 접두어인 경우 true, 아니면 false
    return True

# input & run
# array = ['119', '97674223', '1195524421']
array = ['119', '12345']

print(solution(array))