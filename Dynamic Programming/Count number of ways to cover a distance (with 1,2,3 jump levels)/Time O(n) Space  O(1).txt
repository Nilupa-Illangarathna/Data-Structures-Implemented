# A Dynamic Programming based C++ program to count number of ways
def prCountDP(dist):
    # Create the array of size 3.
    ways = [0] * 3
    n = dist

    # Initialize the bases cases
    ways[0] = 1
    ways[1] = 1
    ways[2] = 2

    # Run a loop from 3 to n
    # Bottom up approach to fill the array
    for i in range(3, n + 1):
        ways[i % 3] = ways[(i - 1) % 3] + ways[(i - 2) % 3] + ways[(i - 3) % 3]

    return ways[n % 3]


# driver program
dist = 4 #upto 800000
print(prCountDP(dist))

# This code is contributed by shivanisinghss2110
