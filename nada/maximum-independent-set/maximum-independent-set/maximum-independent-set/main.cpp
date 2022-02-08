//
//  main.cpp
//  maximum-independent-set
//
//  Created by Igor Peric on 5/2/22.
//

#include <iostream>
#include <cstring>

using namespace std;

typedef unsigned long long set;
typedef unsigned long long bigint;

#define MAXN 40

// print indices of set bits inside data
void debug(set *data) {
    set t = *data;
    bigint c = 0;
    while (1) {
        if (t & 1) cout << c << " ";
        c++;
        t >>= 1;
        if (!t) break;
    }
    cout << endl;
}

// count the number of set bits inside data
bigint num_of_set_bits(set *data) {
    set t = *data;
    bigint c = 0;
    while (1) {
        c += (t & 1);
        t >>= 1;
        if (!t) break;
    }
    return c;
}

// get the degree of node in the graph v with index i,
// where d is the bitmask for deleted nodes
bigint deg(set *v, set *d, int i, int n) {
    set t = v[i] & (~(*d)); // all nodes connected to node i, but at the same time not deleted
    return num_of_set_bits(&t);
}

// disconnects a single node from the graph
void remove_node(set *d, int i) {
    *d |= (1LL << i);
}

// disconnects all of the neighbors of a node i from the graph
void remove_neighbors(set *v, set *d, int i) {
    remove_node(d, i);
    *d |= v[i];
}

// computes the set of independent nodes inside of a graph with vertices v
// where nodes indicated by bitmask d are disconnected from the graph
// and one of the cycles with degree 2 nodes is guaranteed to start at the node i
// and graph has n nodes
// note: at this point there should be no nodes with degrees other than 2
set component(set *v, set *d, int i, int n) {
    set t = v[i] & (~(*d)); // all nodes connected to node i, but at the same time not deleted
    for (int k=0; t; t >>= 1, k++) {
        if (t & 1) {
            remove_neighbors(v, d, k);
            return (1LL << k) | component(v, d, k, n);
        }
    }
    return 0;
}

// s is a bitmask (a set) of nodes not visited
set f(set *v, set *d, int n) {
    
    for (int i=0;i<n;i++) {
 
        if ((*d & (1LL << i))) continue;
        
        // CASE 1: if degree of the node is 0 or 1, optimal solution must contain it
        if (deg(v, d, i, n) == 0 || deg(v, d, i, n) == 1) {
            remove_neighbors(v, d, i); // disconnect the neighbors of the current node
            return (1LL << i) | f(v, d, n); // add the current node to the solution and recurse deeper
        }
        
        // CASE 2: if degree is > 2, we can either take it or not take it
        // we test both options and choose a better one
        if (deg(v, d, i, n) > 2) {
            
            // 1. try taking the current node, meaning all of the neighbors must be removed
            
            set mem_take = *d; // store the connectivity graph we're about to change
            remove_neighbors(v, d, i); // disconnect all the neighbors of the current node
            set take_it = (1LL << i) | f(v, d, n); // explore the option of taking the node i
            *d = mem_take; // once done exploring, reset the graph connectivity to where it was before
            
            // 2. now try disconnecting skipping the current node,
            // meaning disconnect only the node i from the graph, leaving the neighbors intact
            remove_node(d, i);
            set skip_it = f(v, d, n); // we don't add the node to the set since we skipped it
            
            // pick the better option between skipping the node and choosing it
            if (num_of_set_bits(&take_it) > num_of_set_bits(&skip_it)) {
                return take_it;
            } else {
                return skip_it;
            }
        }
        
        // CASE 3: if degree is 2, we skip for now, since this is potentially
        // a part of a cycle with all nodes of degree 2.
        // Degree 2 nodes will be processed outside of the for loop.
    }
    
    // CASE 4: process the remaining nodes
    // all of them are cycles of nodes with degree 2 at this point
    bigint c = 0;
    for (int k=0;k<n;k++) {
        // if we hit a node which is not disconnected, this must be a part of unvisited cycle
        if (!(*d & (1LL << k))) {
            // visit the cycle, adding all of the nodes from it into the final solution (should be floor(|c|/2))
            c |= component(v, d, k, n);
        }
    }
    
    return c;
}

int main(int argc, const char * argv[]) {
    
    int i, n, m;
    
    // connectivity "matrix" - bit B in the number v[A] will be set if there is a connection from A to B in the graph
    set v[MAXN];
    memset(v, 0, MAXN * sizeof(set));
    
    // node disconnection bitmask - if bit with index i is 1 node i is disconnected from the graph
    bigint d = 0;

    scanf("%d %d", &n, &m);
    bigint a, b;
    for (i=0;i<m;i++) {
        scanf("%lld %lld", &a, &b);
        v[a] |= (1LL << b);
        v[b] |= (1LL << a); // undirected graph
    }
    
    set sol = f(v, &d, n);
    printf("%lld\n", num_of_set_bits(&sol));
    debug(&sol);
}
