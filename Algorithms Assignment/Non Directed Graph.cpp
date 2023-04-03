#include "Non Directed Graph.h"

void non_directed_graph::set_edge(vertex& i_src, vertex& i_dst)
{
	i_src.add_neighbor(i_dst);
	i_src.set_degree(i_src.get_degree() + 1);
	i_dst.add_neighbor(i_src);
	i_dst.set_degree(i_dst.get_degree() + 1);
}

bool non_directed_graph::is_graph_conected() 
{
	if (!is_even_degrees())
		return false;

	set_all_white();
	visit(get_vertex_by_value(1));
	if (is_all_black())
		return false;
	return true;
}

bool non_directed_graph::is_even_degrees()
{
	vector<vertex> vertexes = get_vertexes();
	for (auto& vertex : vertexes)
	{
		if (vertex.get_degree() % 2 != 0)
			return false;
	}
	return true;
}


