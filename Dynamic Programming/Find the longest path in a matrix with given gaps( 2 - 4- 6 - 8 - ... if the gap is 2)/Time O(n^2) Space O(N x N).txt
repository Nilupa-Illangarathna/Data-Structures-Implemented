# Python3 program to find the longest path in a matrix
# with given constraints

# Returns length of the longest path beginning with mat[i][j].
# This function mainly uses lookup table dp[n][n]


def findLongestFromACell(i, j, mat, dp, m , n):
	# Base case
	if (i < 0 or i >= n or j < 0 or j >= n):
		return 0

	# If this subproblem is already solved
	if (dp[i][j] != -1):
		return dp[i][j]

	# To store the path lengths in all the four directions
	x, y, z, w = -1, -1, -1, -1

	# Since all numbers are unique and in range from 1 to n * n,
	# there is atmost one possible direction from any cell
	if (j < n-1 and ((mat[i][j] + m) == mat[i][j + 1])):
		x = 1 + findLongestFromACell(i, j + 1, mat, dp, m , n)

	if (j > 0 and (mat[i][j] + m == mat[i][j-1])):
		y = 1 + findLongestFromACell(i, j-1, mat, dp, m , n)

	if (i > 0 and (mat[i][j] + m == mat[i-1][j])):
		z = 1 + findLongestFromACell(i-1, j, mat, dp, m , n)

	if (i < n-1 and (mat[i][j] + m == mat[i + 1][j])):
		w = 1 + findLongestFromACell(i + 1, j, mat, dp, m , n)

	# If none of the adjacent fours is one greater we will take 1
	# otherwise we will pick maximum from all the four directions
	dp[i][j] = max(x, max(y, max(z, max(w, 1))))
	return dp[i][j]


# Returns length of the longest path beginning with any cell
def finLongestOverAll(mat, m , n):
	result = 1 # Initialize result

	# Create a lookup table and fill all entries in it as -1
	dp = [[-1 for i in range(n)]for i in range(n)]

	# Compute longest path beginning from all cells
	for i in range(n):
		for j in range(n):
			if (dp[i][j] == -1):
				findLongestFromACell(i, j, mat, dp, m , n)
			# Update result if needed
			result = max(result, dp[i][j])
	return result


# Driver program

mat =  [[1,  2,  21, 20],
	    [5, 14, 16, 18],
        [1, 12, 10, 19],
	    [4,  6,  8, 10]]

matrix_length = len(mat[0]) #MATRIX SIZE
m = 2 #gap between two numbers

#result ->      4->6->8->10->12->14->16->18->20

print("Length of the longest path is ", finLongestOverAll(mat, m , matrix_length))

# this code is improved by sahilshelangia
