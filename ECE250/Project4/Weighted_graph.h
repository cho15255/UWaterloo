#ifndef WEIGHTED_GRAPH_H
#define WEIGHTED_GRAPH_H

#include <iostream>
#include <limits>
#include "Exception.h"
#include "ece250.h"

using namespace std;

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
        bool *table_Validity;
        double *table_Distance;

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
edges(0) {
    
    if (n <= 0) 
        n = 1;
        
    vertices = n;
    table_Distance = new double [n];
    table_Validity = new bool [n];
    matrix = new double *[n];
    degrees = new int [n];
        
    for (int i=0; i<n; i++) {
        matrix[i] = new double[n];
        table_Distance[i] = INF;
        table_Validity[i] = false;
        degrees[i] = 0;
        for (int j=0; j<n; j++) {
            matrix[i][j] = INF;
        }
    }
}

Weighted_graph::~Weighted_graph() {
    for (int i=0; i<vertices; i++) {
        delete[] matrix[i];
    }
    delete[] matrix;
    delete[] table_Distance;
    delete[] table_Validity;
    delete[] degrees;
}

int Weighted_graph::degree(int n) const {
    if (n >= vertices || n < 0) 
        throw illegal_argument();
    
    return degrees[n];
}

int Weighted_graph::edge_count() const {
    return edges;
}

double Weighted_graph::adjacent(int m, int n) const {
    if (m >= vertices || n >= vertices || m < 0 || n < 0)
        throw illegal_argument();
    
    if (matrix[m][n] == INF)
        return 0.0;
    else
        return matrix[m][n];
}

double Weighted_graph::distance(int m, int n) const {
    if (m >= vertices || n >= vertices || m < 0 || n < 0)
        throw illegal_argument();
    
    for (int i=0; i<vertices; i++) {
        table_Distance[i] = INF;
        table_Validity[i] = false;
    }
    
    double smallest;
	int small;
    table_Distance[m] = 0;
    //table_Validity[m] = true;
    
    for (int i=0; i<vertices; i++) {

		smallest = INF;

        //break if nth position is smallest
		if (table_Validity[n])
            break;

        //finding vertices with smallest weight
        for (int j=0; j<vertices; j++) {
            if (smallest > table_Distance[j] && !table_Validity[j]) {
                smallest = table_Distance[j];
				small = j;
            }
        }
        
        //setting adjacent node's distance
        for (int j=0; j<vertices; j++) {
            if (matrix[small][j] != INF && !table_Validity[j] && 
                    table_Distance[j] > table_Distance[small] + matrix[small][j]) {
                table_Distance[j] = table_Distance[small] + matrix[small][j];
            }
        }
        
		table_Validity[small] = true;
    }
    
    return table_Distance[n];
}

void Weighted_graph::insert(int m, int n, double w) {
    if (w < 0 || m < 0 || n < 0 || m == n || m >= vertices || n >= vertices)
        throw illegal_argument();
    
    //if edge exists, add degree of m and n
    if (matrix[m][n] == INF) {
		degrees[m]++;
		degrees[n]++;
		edges++;
    }

    matrix[m][n] = w;
	matrix[n][m] = w;
}

#endif