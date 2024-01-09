
def main():
    n, tz, x = int(input()), 0, 5
    i = int(n/x)
    while i > 0:
        tz += i
        x *= 5
        i = int(n/x)
    print(tz)

main()
        