a. 

Verifying is P: Given a subset of vertices of the size of n/2, we can check if its a clique in $O(n^2)$. So the problem is in NP. 

The problem can be reduced to a clique problem. If the problem is true, n/2-clique problem is true. If the problem is false, n/2-clique is false or it is true and there is a node connected to all the nodes in the clique of size n/2. So the problem is at least as hard as clique problem. As clique is NP-complete, the problem is NP-hard.

So the problem is NP-complete.



f. 

Verifying is P: Given a subset, we can check if the sum is 0 in O(n). So the problem is in NP.

If the problem is true, let the size of subset be k. Then the Subset Sum problem with the set adjusted by adding a same integer i to all the elements to make them positive, and the target sum set to be ki is true, with a solution of size k.

If the problem is false, The the problem above says false or says true but without a solution of size k.  

So the problem is at least as hard as Subset Sum problem. As Subset Sum problem is NP-complete, the problem is NP-hard.

So the problem is NP complete.



e.

Verifying is P: Given a collection, we can check if it covers U in O(mk). So the problem is in NP.

The problem can be reduced to a vertex cover problem. Assume that there's a Vertex Cover problem with G=(V,E). Make E the ground set U. For each vertex, create a subset Sv with all the edge connected to it in it. Let k be the demanded size of vertex cover. And we've generated the required problem from a Vertex Cover problem. As Vertex Cover is NP-complete, the problem is NP-hard.

So the problem is NP-complete.



i.

Verifying a given coloring requires O(|V||E|). So the problem is NP. 

Create the complement graph G'. In graph G', if there exists a vertex cover Vc of size k in the Vertex Cover instance, we can color the vertices in Vc with one color. Remove all the vertices colored and do it again. Then we can get the 3-coloring scheme if exists. 

Correctness: An edge in G' represents not-an-edge in G. So Vertex Cover in G' is a maximum set of independent vertices in G.

As Vertex Cover is NP-complete, 3-coloring is NP-hard.

So 3-coloring is NP-complete.





