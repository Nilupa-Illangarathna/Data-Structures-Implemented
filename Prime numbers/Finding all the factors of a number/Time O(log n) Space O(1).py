def primeFactors(n):
    c = 2
    while (n > 1):

        if (n % c == 0):
            print(c, end=" ")
            n = n / c
        else:
            c = c + 1


# Driver code
n = 23483460
primeFactors(n)

# This code is contributed by Taranpreet

#result 2 2 3 5 7 11 13 17 23 