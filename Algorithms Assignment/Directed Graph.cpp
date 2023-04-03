#include "Directed Graph.h"

void directed_graph::set_edge(vertex& i_src, vertex& i_dst)
{
	i_src.add_neighbor(i_dst);
	i_src.set_out_degree(i_src.get_out_degree() + 1);
	i_dst.set_in_degree(i_dst.get_in_degree() + 1);
}

bool directed_graph::is_graph_connected()
{
	return false; // placeholder
}

