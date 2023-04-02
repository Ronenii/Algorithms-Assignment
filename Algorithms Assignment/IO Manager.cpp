#include "IO Manager.h"

graph* io_manager::get_user_input()
{
	int vertices, edges;

	const bool is_directed = get_is_graph_directed();
	cin >> vertices >> edges;

	if (is_directed)
	{
		directed_graph* dg = new directed_graph(vertices, edges);
		return dg;
	}
	else
	{
		non_directed_graph* ndg = new non_directed_graph(vertices, edges);
		return ndg;
	}
}

bool io_manager::get_is_graph_directed()
{
	char input;

	cout << "Is the graph directed : y / n " << endl;
	cin >> input;

	if (input == 'n') return false;

	return true;
}

void io_manager::get_directed_graph_input(directed_graph & i_dg)
{
	int v1, v2;

	for(int i = 0; i < i_dg.get_num_of_edges(); i++)
	{
		cin >> v1 >> v2;
		i_dg.set_edge(i_dg.get_vertex_by_value(v1), i_dg.get_vertex_by_value(v2));
	}
}

