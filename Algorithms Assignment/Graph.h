#pragma once
using namespace std;
#include "Vertex.h"
#include <iostream>

class graph
{
protected:
	vector<vertex> m_vertexes;
	int m_num_of_vertexes, m_num_of_edges;

public:
	graph(int i_num_of_vertexes, int i_num_of_edges);
	bool is_vertex_exists(vertex& i_vertex) const;
	virtual ~graph() = default;
	virtual vector<vertex> get_vertexes() const { return m_vertexes; }
	virtual int get_num_of_vertexes() const { return m_num_of_vertexes; }
	virtual int get_num_of_edges() const { return m_num_of_edges; }
	virtual void set_num_of_vertexes(const int i_num_of_vertexes) { m_num_of_vertexes = i_num_of_vertexes; }
	virtual void set_num_of_edges(const int i_num_of_edges) { m_num_of_edges = i_num_of_edges; }
	virtual vertex& get_vertex_by_value(int i_value) { return m_vertexes[i_value - 1]; }
	virtual void set_edge(vertex& i_src, vertex& i_dst) = 0;
	virtual bool is_graph_connected() = 0;
	void visit(vertex& i_vertex);
	void set_all_white();
	bool is_all_black();
};
