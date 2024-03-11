import sys

graph1 = {
    'e': {'a': 1, 'b': 5, 'c': 6, 'd': 6},
    'a': {'e': 2, 'b': 4, 'c': 5, 'd': 5, 'k': 7},
    'b': {'e': 5, 'a': 5, 'c': 3, 'd': 5, 'k': 6},
    'c': {'e': 6, 'a': 5, 'b': 3, 'd': 4, 'k': 5},
    'd': {'e': 6, 'a': 3, 'b': 5, 'c': 4, 'k': 2},
    'k': {'a': 7, 'b': 6, 'c': 5, 'd': 2}
}
# graph1 = {
#     'a': {'b': 4},
#     'b': {'c': 3},
#     'c': {'d': 4},
#     'd': {'e': 6}
# }

#start = input('start ')
#end = input('end ')
#required = input('via ').split(',')
#if required == ['']:
    #required = []

# Hard-code some input data to make it easier to test the code
start, end = 'a', 'd'
required = []

def find_all_paths(graph, start, end, path=None, pathlen=0):
    if path is None:
        path = []
    path = path + [start]
    if start == end:
        yield pathlen, path
    if not start in graph:
        yield [], 0
        return

    for node, val in graph[start].items():
        if node not in path:
            yield from find_all_paths(graph, node, end, path, pathlen + val)

def exists_in_graph(graph, nodes):
    for node in nodes:
        if not node in graph:
            return False
    return True

if not exists_in_graph(graph1, [start, end] + required):
    print('Bad data!')
    sys.exit()

all_paths = (find_all_paths(graph1, start, end))
for pathlen, path in all_paths:
    if exists_in_graph(path, required):
        print(path, pathlen)


graph1 = {
    'a': {'b': 4},
    'b': {'c': 6},
    'c': {'d': 4},
    'd': {'e': 6}
}

all_paths = (find_all_paths(graph1, start, end))
for pathlen, path in all_paths:
    if exists_in_graph(path, required):
        print(path, pathlen)