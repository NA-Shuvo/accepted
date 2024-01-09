
def summation(n):
    return n*(n+1) >> 1

def main():
    
    n = int(input())
    S = summation(n)

    taken = [False for i in range(n+1)]
    
    if S%2 == 0:
        print("YES")
        target = S >> 1
        i = n
        count = 0
        while target > 0:
            if target - i >= 0:
                target -= i
                taken[i] = True
                count += 1
            i -= 1

        print(count)
        temp = count
        for i in range(n+1):
            if taken[i] == True:
                if temp > 1:
                    print(i, end=" ")
                else:
                    print(i)
                temp -= 1
        
        print(n-count)
        temp = n - count
        for i in range(1, n+1):
            if taken[i] == False:
                if temp > 1:
                    print(i, end=" ")
                else:
                    print(i)    
                temp -= 1
    else:
        print("NO")

main()