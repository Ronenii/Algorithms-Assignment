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
	virtual ~graph() = default;
	bool is_vertex_exists(vertex& i_vertex) const;
	virtual vector<vertex> get_vertexes() const { return m_vertexes; }
	virtual int get_num_of_vertexes() const { return m_num_of_vertexes; }
	virtual int get_num_of_edges() const { return m_num_of_edges; }
	virtual void set_num_of_vertexes(const int i_num_of_vertexes) { m_num_of_vertexes = i_num_of_vertexes; }
	virtual void set_num_of_edges(const int i_num_of_edges) { m_num_of_edges = i_num_of_edges; }
	virtual vertex& get_vertex_by_value(int i_value) { return m_vertexes[i_value - 1]; }
	virtual void set_edge(vertex& i_src, vertex& i_dst) = 0;
	void visit(vertex& i_vertex);
	void set_all_white();
	bool is_all_black();
	vector<vertex*> find_circuit(int i_value);
	bool is_unsused_edge(vertex i_current_vertex, list<vertex>& i_neighbors_list, vertex& o_next_neighbor);
	virtual bool is_euler() = 0;
	list<vertex*> get_euler_circuit();
	bool has_usused_egde(vertex& i_vertex);
	void paste_circuit(vector<vertex*>& i_dst, vector<vertex*>& i_src, int i_start_index);
	void change_edeges_to_used(int i_current_vertex_value, vertex& neighbor);
	virtual bool is_directed() = 0;

	vertex* mashu(list<vertex>* ref_neighbors_list, int current_vertex_value, bool& o_flag);
	
};
