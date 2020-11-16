#!/usr/bin/env python
from math import gcd, ceil
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


def prod(a, mod=10**9+7):
    ans = 1
    for each in a:
        ans = (ans * each) % mod
    return ans


def lcm(a, b): return a * b // gcd(a, b)


def binary(x, length=16):
    y = bin(x)[2:]
    return y if len(y) >= length else "0" * (length - len(y)) + y


def main():
    sys.stdin = open('/home/anik/projects/learning/dsa/input.txt', 'r')
    sys.stdout = open('/home/anik/projects/learning/dsa/output.txt', 'w')
    for _ in range(int(input())):
        n, k = map(int, input().split())
        st = input()
        cnt, stk, mag, iron = 0, [0] * 100001, [], []
        for i, v in enumerate(st):
            if v == ':':
                cnt += 1
            stk[i] = cnt
        ans = 0
        for i, v in enumerate(st):
            if v == 'M':
                mag.append(i)
            elif v == 'I':
                iron.append(i)
            elif v == 'X':
                mag = []
                iron = []

            if len(iron) > 0 and len(mag) > 0:
                while len(iron) > 0 and len(mag) > 0:
                    p = mag[0]
                    j = iron[0]
                    power = k + 1 - abs(j - p) - abs(stk[j] - stk[p])
                    if power > 0:
                        ans += 1
                        iron.pop(0)
                        mag.pop(0)
                    else:
                        if p > j:
                            iron.pop(0)
                        else:
                            mag.pop(0)
        print(ans)


if __name__ == "__main__":
    main()
