#pragma once
using namespace std;
#include "Vertex.h"
#include <iostream>

class graph
{
private:
	vector<vertex> m_vertexes;
	int m_num_of_vertexes, m_num_of_edges;
public:
	graph(int i_num_of_vertexes, int i_num_of_edges);
	virtual ~graph() = default;
	virtual vector<vertex> get_vertexes() const { return m_vertexes; }
	virtual int get_num_of_vertexes() const { return m_num_of_vertexes; }
	virtual int get_num_of_edges() const { return m_num_of_edges; }
	virtual void set_num_of_vertexes(const int i_num_of_vertexes) {m_num_of_vertexes = i_num_of_vertexes;}
	virtual void set_num_of_edges(const int i_num_of_edges) { m_num_of_edges = i_num_of_edges; }
	virtual void set_edge(vertex i_src, vertex i_dst) = 0;
};
