# Undirected Weighted Graph - Adjacency List-Implementation-in-C-
This project is a simulator for a satellite navigator, that could be used by a salesman to plan trips between the cities in which he trades. Among the many functions that the navigator must offer the user is also to search for and suggest a route that, from any city of departure, leads to another city of arrival. Normally the path to look for would be that of minimum length, but for simplicity we limit ourselves to any path as long as it is acyclic, that is to say that a same location is visited at most once. 
The navigator is able to load, from files or standard input, the maps of the regions in which the user moves. The following actions can be carried out at the choice of the user: 
1. Creation of the graph by acquiring information on vertices and arcs from standard input, expressed in the following format: 
  origin1 destination1 dist1  
  origin2 destination2 dist2 ....  
  originN destinationN distN  
  0 
2. Creation of the graph acquiring from file the information on the vertices and on the arcs (the format is the same as for the acquisition from standard input) 
3. Textual display of the graph, which shows the list of vertices with the respective labels and, for each vertex, the relative adjacency list with string weights. 
4. Insertion of a new vertex in the graph, whose label is provided by input. 
5. Insertion of a new arc in the graph, assuming that the labels of its vertices are supplied as input. 
6. Determination of the number of vertices. 
7. Determination of the number of arcs. 
8. Determination of the degree of a vertex, whose label is provided by input.
9. Verificance adjacency between two vertices, whose labels are provided as input. 
10. Display of the adjacency list associated with a vertex, whose label is provided as an input. 
11. Search for an acyclic path between origin and destination and display on standard output of the path found, in the format: 
  source vertex vertex2 .... vertexN destination - and overall length.
