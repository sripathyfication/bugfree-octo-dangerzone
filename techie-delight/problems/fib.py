#/usr/bin/python


def fib(n):
    if n is 0:
        return 0
    if n is 1:
        return 1
    return fib(n-1) + fib(n-2)

print fib(5)
