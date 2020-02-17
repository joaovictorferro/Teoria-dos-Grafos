BELLMAN_FORD = "Bellman-Ford/bellmanFord.cpp"
KRUSKAL = "Kruskal/kruskal.cpp"
DIJKSTRA = "Dijkstra/dijkstra.cpp"

bellmanFord:
	g++ 	$(BELLMAN_FORD)	 -o		bellmanFord

kruskal:
	g++ 	$(KRUSKAL)	 -o		kruskal

dijkstra:
	g++ 	$(DIJKSTRA)	 -o		dijkstra