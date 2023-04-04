#pragma once

#include "Graph.h"

class directed_graph: public graph
{
public:
	directed_graph(int i_num_of_vertexes, int i_num_of_edges) :graph(i_num_of_vertexes, i_num_of_edges) {}
	~directed_graph() = default;
	virtual void set_edge(vertex& i_src, vertex& i_dst) override;
	bool is_grpah_strongly_connected();
	directed_graph & get_transposed();
	virtual bool is_euler() override;
	bool all_degrees_equal();
};