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

directed_graph io_manager::get_directed_graph_input()
{
	
}

void io_manager::get_non_directed_graph_input(non_directed_graph & ret_ndg)
{
	
}
