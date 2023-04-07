#include "NonDirectedGraph.h"

void non_directed_graph::set_edge(vertex& i_src, vertex& i_dst)
{
	i_src.add_neighbor(i_dst);
	i_src.set_degree(i_src.get_degree() + 1);
	i_dst.add_neighbor(i_src);
	i_dst.set_degree(i_dst.get_degree() + 1);
}

bool non_directed_graph::is_euler()
{
	if (!is_even_degrees())
		return false;

	set_all_white();
	graph* dummy_graph = get_dummy_graph();
	dummy_graph->visit(dummy_graph->get_vertex_by_value(1));
	if (dummy_graph->is_all_black())
	{
		delete(dummy_graph);
		return true;
	}
	delete(dummy_graph);
	return false;
}

bool non_directed_graph::is_even_degrees()
{
	for (auto& vertex : m_vertexes)
	{
		if (vertex.get_degree() % 2 != 0)
			return false;
	}
	return true;
}

bool non_directed_graph::is_directed()
{
	return false;
}

graph* non_directed_graph::get_dummy_graph()
{
	graph* dummy_graph = new non_directed_graph(*this);
	return dummy_graph;
}


