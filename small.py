fib = []
fib.append(1)

res = 1
for i in range(1, 101):
    res = res * i
    fib.append(res)
# print(fib[100])
n = int(input())
for i in range(0, n):
    num = int(input())
    print(fib[num])