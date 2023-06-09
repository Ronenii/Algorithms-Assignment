#pragma once

#include "Graph.h"

class non_directed_graph: public graph
{
public:
	non_directed_graph(int i_num_of_vertexes, int i_num_of_edges) :graph(i_num_of_vertexes, i_num_of_edges) {}
	~non_directed_graph() = default;
	virtual void set_edge(vertex& i_src, vertex& i_dst) override;
	virtual bool is_euler() override;
	virtual void mark_edge(vertex& i_current_vertex, vertex& i_neighbor_vertex) override;
	bool is_even_degrees();
	virtual bool is_directed();
	virtual graph* get_dummy_graph();
};