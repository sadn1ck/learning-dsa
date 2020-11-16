#!/usr/bin/env python
import os
import sys
from io import BytesIO, IOBase
# from bisect import bisect_left as bl                #c++ lowerbound bl(array,element)
# from bisect import bisect_right as br               #c++ upperbound br(array,element)
# ---------------------------------fast-------------------------------------!
# region fastio

BUFSIZE = 8192


class FastIO(IOBase):
    newlines = 0

    def __init__(self, file):
        self._fd = file.fileno()
        self.buffer = BytesIO()
        self.writable = "x" in file.mode or "r" not in file.mode
        self.write = self.buffer.write if self.writable else None

    def read(self):
        while True:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            if not b:
                break
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines = 0
        return self.buffer.read()

    def readline(self):
        while self.newlines == 0:
            b = os.read(self._fd, max(os.fstat(self._fd).st_size, BUFSIZE))
            self.newlines = b.count(b"\n") + (not b)
            ptr = self.buffer.tell()
            self.buffer.seek(0, 2), self.buffer.write(b), self.buffer.seek(ptr)
        self.newlines -= 1
        return self.buffer.readline()

    def flush(self):
        if self.writable:
            os.write(self._fd, self.buffer.getvalue())
            self.buffer.truncate(0), self.buffer.seek(0)


class IOWrapper(IOBase):
    def __init__(self, file):
        self.buffer = FastIO(file)
        self.flush = self.buffer.flush
        self.writable = self.buffer.writable
        self.write = lambda s: self.buffer.write(s.encode("ascii"))
        self.read = lambda: self.buffer.read().decode("ascii")
        self.readline = lambda: self.buffer.readline().decode("ascii")


sys.stdin, sys.stdout = IOWrapper(sys.stdin), IOWrapper(sys.stdout)
def input(): return sys.stdin.readline().rstrip("\r\n")

# endregion


def SieveOfEratosthenes(limit=10**6):
    """Returns all primes not greater than limit."""
    isPrime = [True]*(limit+1)
    isPrime[0] = isPrime[1] = False
    primes = []
    for i in range(2, limit+1):
        if not isPrime[i]:
            continue
        primes += [i]
        for j in range(i*i, limit+1, i):
            isPrime[j] = False
    return primes


def main():
    sys.stdin = open('/home/anik/projects/learning/dsa/input.txt', 'r')
    sys.stdout = open('/home/anik/projects/learning/dsa/output.txt', 'w')
    primes = SieveOfEratosthenes()
    for _ in range(int(input())):
        n = int(input())
        arr = list(map(int, input().split()))
        ans = [0] * n
        for i in range(n):
            ans[i] = primes[i]
        for i in range(n):
            if arr[i] != (i+1):
                ans[i] = ans[arr[i] - 1]
        print(*ans)


if __name__ == "__main__":
    main()
