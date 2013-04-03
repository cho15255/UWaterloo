#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>

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
        int vertice;
        int edges;
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
(vertice = n), (edges = 0) {
    
    if (n <= 0) {
        
        vertice = 1;
        matrix = new double*[1];
        matrix[1] = new double[1];
    
    }
}

Weighted_graph::~Weighted_graph() {
    for (int i=0; i<vertice; i++) {
        delete[] matrix[i];
    }
}

int Weighted_graph::degree(int n) const {
    
}

int Weighted_graph::edge_cout() const {
    
}

#endif