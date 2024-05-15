def fac(a):
    if a <= 1:
        return 1
    return a * fac(a-1)
a = int(input())
b = int(input())
print(int(fac(a)/fac(b)/fac(a-b)))