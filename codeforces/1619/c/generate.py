#!/usr/bin/env python3
import random

N = random.randint(1, 1000)
print(N)
for _ in range(N):
  v = random.randint(1, 10000000)
  w = random.randint(1, 10000000)
  print(v, w)
