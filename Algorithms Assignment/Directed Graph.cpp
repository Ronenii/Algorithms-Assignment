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

bool directed_graph::is_grpah_strongly_connected()
{
	set_all_white();
    visit(get_vertex_by_value(1));

	if(is_all_black())
	{
		directed_graph dg_transposed = get_transposed();
		visit(dg_transposed.get_vertex_by_value(1));
		if(dg_transposed.is_all_black())
		{
			return true;
		}
	}
	
	return false;
}

directed_graph & directed_graph::get_transposed()
{
	directed_graph * transposed = new directed_graph(m_num_of_vertexes, m_num_of_edges);
	vertex src;
	vertex dst;

    for(auto v: m_vertexes)
	{
		dst = v;
		for(auto neighbor: v.get_neighbors())
		{
			src = neighbor;
			transposed->set_edge(src,dst);
		}
	}

	return *transposed;
}

bool directed_graph::is_euler()
{
    return is_grpah_strongly_connected() && all_degrees_equal();
}

bool directed_graph::all_degrees_equal()
{
    for(auto & v: m_vertexes)
	{
		if (v.get_in_degree() != v.get_out_degree())
		{
			return false;
		}
	}

	return true;
}
