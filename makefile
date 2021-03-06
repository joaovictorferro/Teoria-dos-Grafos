BELLMAN_FORD = "Bellman-Ford/bellmanFord.cpp"
KRUSKAL = "Kruskal/kruskal.cpp"
DIJKSTRA = "Dijkstra/dijkstra.cpp"
PRIM = "Prim/prim.cpp"

bellmanFord:
	g++ 	$(BELLMAN_FORD)	 -o		bellmanFord

kruskal:
	g++ 	$(KRUSKAL)	 -o		kruskal

dijkstra:
	g++ 	$(DIJKSTRA)	 -o		dijkstra

prim:
	g++ 	$(PRIM)	 -o		prim

