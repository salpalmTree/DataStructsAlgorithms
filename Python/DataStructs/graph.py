class Vertex:
    def __init__(self, value): 
        self.value = value
        self.edges = {}

    def add_edge_to_vertex(self, vertex, weight=0):
        self.edges[vertex] = weight

    def get_connected_vertices(self):
        return list(self.edges.keys())


class Graph: 
    def __init__(self, directed=False):
        self.graph_dict = {}
        self.directed = directed

    def add_vertex(self, vertex):
        self.graph_dict[vertex.value] = vertex

    def add_edge(self, from_vertex, to_vertex, weight = 0):
        self.graph_dict[from_vertex.value].add_edge_to_vertex(to_vertex.value, weight)
        if not self.directed:
            self.graph_dict[to_vertex.value].add_edge_to_vertex(from_vertex.value, weight)

    def find_path(self, start, end): 
        # queue for traversing
        traverse_queue = [start]
        
        # dictionary to keep track of visited vertices
        seen = {}

        while len(traverse_queue) > 0:
            current_vertex = traverse_queue.pop(0)

            seen[current_vertex] = True

            # print("Visiting: {0}".format(current_vertex.value))
            print("Visiting " + current_vertex)
            if current_vertex == end:
                return True
          
            next_vertices = self.graph_dict[current_vertex].edges.keys()

            traverse_queue += [vertex for vertex in next_vertices if vertex not in seen]
            
            # traverse_queue += next_vertices
        return False

    def print_graph(self):
        for vertex in self.graph_dict:
            print(vertex + " is connected to:")
            neighbors = self.graph_dict[vertex].edges
            if len(neighbors) == 0:
                print("Nothing")
            for adj_vertex in neighbors:
                print("-----> " + adj_vertex)

            
my_graph = Graph()

# creating vertices
a_vertex = Vertex("A")
b_vertex = Vertex("B")
c_vertex = Vertex("C")
d_vertex = Vertex("D")

# adding vertices to graph
my_graph.add_vertex(a_vertex)
my_graph.add_vertex(b_vertex)
my_graph.add_vertex(c_vertex)
my_graph.add_vertex(d_vertex)

# connecting vertices to each other
my_graph.add_edge(a_vertex, d_vertex)
my_graph.add_edge(a_vertex, c_vertex)
my_graph.add_edge(b_vertex, c_vertex)
my_graph.add_edge(d_vertex, c_vertex)


print("Path from B to D: ")
print(my_graph.find_path("B", "D"))


print("\n\n")
my_graph.print_graph()

