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

void io_manager::get_char_input(char& input)
{
	cin >> input;
	if (input != 'n' || input != 'y')
		throw invalid_input_exception();
}

void io_manager::get_edge_input(int& src, int& dst, int num_of_vertexes)
{
	cin >> src >> dst;
	if (!(src > 0 && src < num_of_vertexes) || !(dst > 0 && dst < num_of_vertexes))
		throw invalid_edge_input_exception();
}

bool io_manager::get_is_graph_directed()
{
	char input;
	cout << "Is the graph directed : y / n " << endl;
	while(true)
	{
		try
		{
			get_char_input(input);
			if(input == 'n') return false;

			return true;
		}
		catch (const invalid_input_exception& e)
		{
			cout << "Exception thrown: " << e.what() << endl;
		}
	}
	
}



void io_manager::get_directed_graph_input(directed_graph & i_dg)
{
	int v1, v2;

	for(int i = 0; i < i_dg.get_num_of_edges(); i++)
	{
		try
		{
			get_edge_input(v1, v2, i_dg.get_num_of_vertexes());
			i_dg.set_edge(i_dg.get_vertex_by_value(v1), i_dg.get_vertex_by_value(v2));
		}
		catch (const invalid_edge_input_exception& e)
		{
			cout << "Exception thrown: " << e.what() << endl;
			i--;
		}
		
		
	}
}

directed_graph io_manager::get_directed_graph_input()
{
	
}