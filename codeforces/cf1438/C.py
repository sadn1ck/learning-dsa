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


def main():
    sys.stdin = open('/home/anik/projects/learning/dsa/input.txt', 'r')
    sys.stdout = open('/home/anik/projects/learning/dsa/output.txt', 'w')
    for _ in range(int(input())):
        n, m = map(int, input().split())
        arr = []
        for _ in range(n):
            mi = list(map(int, input().split()))
            arr.append(mi)
        for i in range(n):
            for j in range(m):
                if (i+j) % 2 != (arr[i][j]) % 2:
                    arr[i][j] += 1

        for i in arr:
            for j in i:
                print(j, end=" ")
            print()


if __name__ == "__main__":
    main()
