def get_odd(alist):
    ans = []
    for num in alist:
        if num % 2:
            ans.append(num)
    return ans

def get_odd_lazy(alist):
    for num in alist:
        if num % 2:
            yield num

alist = [i for i in range(20)]
print(get_odd(alist))
num = get_odd_lazy(alist)
while True:
    try:
        print(next(num))
    except StopIteration:
        break