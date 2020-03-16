class Sum:
    def sum(self, n):
        num = 0
        for i in range(n+1):
            num += i
        return num

def sum(n):
        num = 0
        for i in range(n+1):
            num += i
        return num

a = Sum().sum(100)
print(Sum().sum(100))
print(sum(100))