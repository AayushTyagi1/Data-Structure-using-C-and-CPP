def twosum(arr, b):
    num = {}
    for i in arr:
        check = b - i
        if check in num:
            return [check, i]
        else:
            num[i] = True
    return []


print(twosum([1, 2, 3, 4, 5, 6], 7))
