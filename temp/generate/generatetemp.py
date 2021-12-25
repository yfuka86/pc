#!/usr/bin/env python3
import random

def main():
    N = random.randint(1, 10 ** 9)  # TODO: edit here
    a = [None for _ in range(N)]
    Q = random.randint(1, 10 ** 9)  # TODO: edit here
    l = [None for _ in range(Q)]
    r = [None for _ in range(Q)]
    for i in range(N):
        a[i] = random.randint(1, 10 ** 9)  # TODO: edit here
    for i in range(Q):
        l[i] = random.randint(1, 10 ** 9)  # TODO: edit here
        r[i] = random.randint(1, 10 ** 9)  # TODO: edit here
    print(N, Q)
    print(*[a[i] for i in range(N)])
    for i in range(Q):
        print(l[i], r[i])

if __name__ == "__main__":
    main()
