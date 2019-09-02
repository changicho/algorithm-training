def solution(array, commands):
    answer = []

    for command in commands:
        new_array = []
        # print(command)
        # print(range(command[0],command[1]))
        for index in range(command[0]-1,command[1]):
            new_array.append(array[index])
        
        new_array.sort()
        print(new_array)
        answer.append(new_array[command[2]-1])

    return answer

# input & run
array = [1, 5, 2, 6, 3, 7, 4]
commands = [[2, 5, 3], [4, 4, 1], [1, 7, 3]]

print(solution(array, commands))