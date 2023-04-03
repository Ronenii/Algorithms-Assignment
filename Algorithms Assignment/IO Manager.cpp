#include "IO Manager.h"

bool io_manager::get_is_graph_directed()
{
	char input;

	cout << "Is the graph directed : y / n " << endl;
	cin >> input;

	if (input == 'n') return false;

	return true;
}

graph & io_manager::get_user_input()
{
	int vertices, edges;

	const bool is_directed = get_is_graph_directed();
	cin >> vertices >> edges;

	if(is_directed)
	{
		directed_graph dg(vertices, edges);
		return dg;
	}
	else
	{
		non_directed_graph ndg(vertices, edges);
		return ndg;
	}
}

void io_manager::get_directed_graph_input(directed_graph& i_dg)
{
	int src_value, dst_value;
	for (int i = 0; i < i_dg.get_num_of_edges(); i++)
	{
		cin >> src_value >> dst_value;
		vertex& src = i_dg.get_vertex_by_value(src_value);
		vertex& dst = i_dg.get_vertex_by_value(dst_value);
		i_dg.set_edge(src, dst);
	}
}