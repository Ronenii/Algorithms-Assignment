#include "Non Directed Graph.h"

void non_directed_graph::set_edge(vertex& i_src, vertex& i_dst)
{
	i_src.add_neighbor(i_dst);
	i_dst.add_neighbor(i_src);
}

bool non_directed_graph::is_graph_conected() const
{
	return false;
}
