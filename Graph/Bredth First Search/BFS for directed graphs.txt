# Python code to give the traversed path by BFS algorithm as output. BFS(int n) scans through the vertices which are reachable from n.
from collections import defaultdict as dd


class Graph:

    # Constructing a list
    def __init__(self):

        # default dictionary to store graph
        self.graph = dd(list)

        # defining function which will add edge to the graph

    def addEdgetoGraph(self, x, y):
        self.graph[x].append(y)

        # defining function to print BFS traverse

    def BFSearch(self, n):

        for i in self.graph.keys():
            # print(self.graph[i])
            for j in range(len(self.graph[i])):
                # print(self.graph[i][j],end=" ")
                if self.graph[i][j]==i:
                    self.graph[i].pop(j)
                    break

            # for j in range(len(self.graph[i])):
            #     print(self.graph[i][j],end=" ")
            # print("")


        # Initially marking all vertices as not visited
        visited_vertices = (len(self.graph)) * [False]

        # creating a queue for visited vertices
        queue = []

        # setting source node as visited and adding it to the queue
        visited_vertices[n] = True
        queue.append(n)

        while queue:

            # popping the element from the queue which is printed
            n = queue.pop(0)
            # for i in self.graph.keys():
            #     print(self.graph[i])
            print(n, end=" ")

            # getting vertices adjacent to the vertex n which is dequed.
            for v in self.graph[n]:
                if visited_vertices[v] == False:
                    queue.append(v)
                    visited_vertices[v] = True

                # Example code


# Initializing a graph
graph = Graph()

# Me widiyata self loop walin initialize karanna oni hama node ekkma
#e LOOP AIN WENA WIDIYATA MODE KARA CODE EKA
graph.addEdgetoGraph(0, 0)
graph.addEdgetoGraph(1, 1)
graph.addEdgetoGraph(2, 2)
graph.addEdgetoGraph(3, 3)
graph.addEdgetoGraph(4, 4)
graph.addEdgetoGraph(5, 5)
graph.addEdgetoGraph(6, 6)


# DIRECTED PATH DENNA ONI MEKEDI
graph.addEdgetoGraph(0, 1)
graph.addEdgetoGraph(0, 3)
graph.addEdgetoGraph(0, 2)

graph.addEdgetoGraph(1, 4)
graph.addEdgetoGraph(1, 3)

graph.addEdgetoGraph(2, 5)

graph.addEdgetoGraph(3, 2)
graph.addEdgetoGraph(3, 4)
graph.addEdgetoGraph(3, 5)

graph.addEdgetoGraph(4, 6)

graph.addEdgetoGraph(5, 6)


print(" The Breadth First Search Traversal for The Graph is as Follows: ")
graph.BFSearch(0) # Ki wenu node eke idan da kiyala danna oni
                  # E kiwe 3 kiyanne indexwise 2 weni index eke thiyena ekane, e nisa 3 nm oni node eka eka danna oni