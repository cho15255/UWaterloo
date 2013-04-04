#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include "Exception.h"
#include "ece250"

/*****************************************
 * UW User ID:  uwuserid
 * Submitted for ECE 250
 * Semester of Submission:  (Winter|Spring|Fall) 20NN
 *
 * By submitting this file, I affirm that
 * I am the author of all modifications to
 *  the provided code.
 *****************************************/

// include whatever classes you want

class Weighted_graph {
    private:
		// your implementation here
		static const double INF;
        int edges;
        int vertices;
        int *degrees;
        double **matrix;

	public:
		Weighted_graph( int = 50 );
		~Weighted_graph();

		int degree( int ) const;
		int edge_count() const;
		double adjacent( int, int ) const;
		double distance( int, int ) const;

		void insert( int, int, double );
};

const double Weighted_graph::INF = std::numeric_limits<double>::infinity();

Weighted_graph::Weighted_graph(int n): 
(vertices = n), (edges = 0) {
    
    if (n <= 0) 
        n = 1;
        
    for (int i=0; i<n; i++) {
        matrix[i] = new double[n];
    }
    
    degrees = new int[n];
}

Weighted_graph::~Weighted_graph() {
    for (int i=0; i<vertice; i++) {
        delete[] matrix[i];
    }
}

int Weighted_graph::degree(int n) const {
    if (n > vertices || n <= 0) 
        throw illegal_argument();
    
    return degrees[n];
}

int Weighted_graph::edge_cout() const {
    return edges;
}

double Weighted_graph::adjacent(int m, int n) const {
    if (m > vertices || n > vertices || m <= 0 || n <= 0)
        throw illegal_argument();
    
    if (matrix[m][n] == INF)
        return 0.0;
    else
        return matrix[m][n];
}

double Weighted_graph::distance(int m, int n) const {
    if (m > vertices || n > vertices || m <= 0 || n <= 0)
        throw illegal_argument();
    
    
}

#endif