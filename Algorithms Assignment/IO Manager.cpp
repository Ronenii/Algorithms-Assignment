#include "IO Manager.h"

bool io_manager::get_is_graph_directed()
{
	char input;

	cout << "Is the graph directed : y / n " << endl;
	cin >> input;

	if (input == 'n') return false;

	return true;
}

graph * io_manager::get_user_input()
{
	int vertices, edges;

	const bool is_directed = get_is_graph_directed();
	cin >> vertices >> edges;

	if(is_directed)
	{
		directed_graph * dg = new directed_graph(vertices, edges);
		get_graph_input(dg);
		return dg;
	}
	else
	{
		non_directed_graph * ndg = new non_directed_graph(vertices, edges);
		get_graph_input(ndg);
		return ndg;
	}
}

void io_manager::get_graph_input(graph* i_graph)
{
	int src_value, dst_value;

	for (int i = 0; i < i_graph->get_num_of_edges(); i++)
	{
		cin >> src_value >> dst_value;
		vertex& src = i_graph->get_vertex_by_value(src_value);
		vertex& dst = i_graph->get_vertex_by_value(dst_value);
		i_graph->set_edge(src, dst);
	}
}