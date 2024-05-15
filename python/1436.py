

a = int(input())
found = 0
num = 660
while True:

    if found == a:
        break
    num += 1
    if (str(num).find("666") != -1):
        found += 1
print(num)