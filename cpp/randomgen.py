import random

with open("in2.txt", "w") as f:
    for i in range(int(input())):
        f.write(f"{random.randint(1,1<<31)}\n")
    f.write("0\n")
