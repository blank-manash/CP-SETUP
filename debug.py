#!/opt/homebrew/bin/python3
import random

n = random.randrange(4, 10)
print(n)
for k in range(0, n):
    print(random.randrange(1, 100), end="")
    if k != n - 1:
        print(" ", end="")


"""
Find   
"""