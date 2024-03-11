# Python3 Program for Floyd Warshall Algorithm

# Number of vertices in the graph


# Define infinity as the large
# enough value. This value will be
# used for vertices not connected to each other
INF = 99999999999999999999999999999


# Solves all pair shortest path
# via Floyd Warshall Algorithm


def floydWarshall(graph):
    """ dist[][] will be the output
       matrix that will finally
        have the shortest distances
        between every pair of vertices """
    """ initializing the solution matrix
    same as input graph matrix
    OR we can say that the initial
    values of shortest distances
    are based on shortest paths considering no
    intermediate vertices """

    dist = list(map(lambda i: list(map(lambda j: j, i)), graph))

    """ Add all vertices one by one
    to the set of intermediate
     vertices.
     ---> Before start of an iteration,
     we have shortest distances
     between all pairs of vertices
     such that the shortest
     distances consider only the
     vertices in the set
    {0, 1, 2, .. k-1} as intermediate vertices.
      ----> After the end of a
      iteration, vertex no. k is
     added to the set of intermediate
     vertices and the
    set becomes {0, 1, 2, .. k}
    """
    for k in range(V):

        # pick all vertices as source one by one
        for i in range(V):

            # Pick all vertices as destination for the
            # above picked source
            for j in range(V):
                # If vertex k is on the shortest path from
                # i to j, then update the value of dist[i][j]
                dist[i][j] = min(dist[i][j],
                                 dist[i][k] + dist[k][j]
                                 )
    printSolution(dist)


# A utility function to print the solution
def printSolution(dist):
    print("Following matrix shows the shortest distances\
 between every pair of vertices")
    for i in range(V):
        for j in range(V):
            if (dist[i][j] == INF):
                print("%7s" % ("INF"), end=" ")
            else:
                print("%7d\t" % (dist[i][j]), end=' ')
            if j == V - 1:
                print()


# Driver's code
if __name__ == "__main__":
    """
         Graph 01 is as follows
                10
           (A)------->(D)
            |         /|\
          5 |          |
            |          | 1
           \|/         |
           (B)------->(C)
                3           """
    V = 4
    graph1 = [[0, 5, INF, 10],
             [INF, 0, 3, INF],
             [INF, INF, 0, 1],
             [INF, INF, INF, 0]
             ]

    # V = 9
    # graph2 = [[INF, 4, INF, INF, INF, INF, INF, 8, INF],
    #            [4, INF, 8, INF, INF, INF, INF, 11, INF],
    #            [INF, 8, INF, 7, INF, 4, INF, INF, 2],
    #            [INF, INF, 7, INF, 9, 14, INF, INF, INF],
    #            [INF, INF, INF, 9, INF, 10, INF, INF, INF],
    #            [INF, INF, 4, 14, 10, INF, 2, INF, INF],
    #            [INF, INF, INF, INF, INF, 2, INF, 1, 6],
    #            [8, 11, INF, INF, INF, INF, 1, INF, 7],
    #            [INF, INF, 2, INF, INF, INF, 6, 7, INF]
    #            ]
    # Function call
    floydWarshall(graph1)
# This code is contributed by Mythri J L