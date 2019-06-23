import sys


def fibbonachi(num):
    a = b = 1
    for _ in range(num):
        yield a
        a, b = b, a + b


if __name__ == '__main__':
    count = int(sys.argv[1]) if len(sys.argv) > 1 else 10
    print(count)
    for i in fibbonachi(count):
        print(i)
