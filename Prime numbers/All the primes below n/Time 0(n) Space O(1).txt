# Python program for the above approach
Primes = [0] * 500001


def SieveOfEratosthenes(n):
    Primes[0] = 1
    i = 3
    while (i * i <= n):
        if (Primes[i // 2] == 0):
            for j in range(3 * i, n + 1, 2 * i):
                Primes[j // 2] = 1

        i += 2


# Driver Code
if __name__ == "__main__":

    n = 200
    SieveOfEratosthenes(n)
    for i in range(1, n + 1):
        if (i == 2):
            print(i, end=" ")
        elif (i % 2 == 1 and Primes[i // 2] == 0):
            print(i, end=" ")

    # This code is contributed by code_hunt.
    
    #result 2 3 5 7 11 13 17 19 23 29 31 37 41 43 47 53 59 61 67 71 73 79 83 89 97 101 103 107 109 113 127 131 137 139 149 151 157 163 167 173 179 181 191 193 197 199 