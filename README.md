# Disciplina: Teoria-dos-Grafos
## Professor: Rian Gabriel Santos Pinheiro
### Equipe:
- João Victor Ribeiro Ferro
-  William Philippe

### Grafos Escolhidos para implementação:
- [x] Bellman Ford
- [x] Dijkstra
- [x] Kruskal
- [x] Prim

Para compilar o programa basta digitar:
```
make ?
```
Você subtitui a interrogação(?) pelo o algoritmo que queira executar exs:
```
make bellmanFord
make kruskal
make dijkstra
```
Depois vc seleciona o arquivo que queira executar:
```
./bellmanFord exemplos/exBellman.txt
./kruskal exemplos/exKruskal.txt
./dijkstra exemplos/exDijkstra.txt
```
Obs: caso queira executar outro exemplo, so criar um na pasta(exemplos) e fazer os passos acima

Arquivo tem que esta nesse formato:
```
5 4
1 4 6
```
Na primeira linha contém o número de Vertice (V) e Aresta (E), 
seguido por E aresta contendo cada aresta como:

`vertex_src vertex_dest weight`
