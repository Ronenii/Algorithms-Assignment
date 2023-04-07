#include "IO_Manager.h"

void io_manager::run_program()
{
	list<vertex> euler_circuit;
	graph* input_graph;
	input_graph = get_user_input();
	if (input_graph != nullptr)
	{
		int complete_edges_counter = 0;
		get_graph_input(input_graph, complete_edges_counter);
		if(complete_edges_counter == input_graph->get_num_of_edges())
		{
			if (input_graph->is_euler())
			{
				cout << "The graph is aulerian" << endl;
				input_graph->get_and_print_euler_circuit();
			}
			else
			{
				cout << "The graph is not aulerian" << endl;
			}
		}
		delete(input_graph);
	}
}


graph* io_manager::get_user_input()
{
	int vertices, edges;

	try
	{
		const bool is_directed = get_is_graph_directed();
		get_vertexes_and_edges_input(vertices, edges);
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
	catch (const invalid_input_exception& e)
	{
		cout << e.what() << endl;
		return nullptr;
	}

}

void io_manager::get_char_input(char& input)
{
	cin >> input;
	if (input != 'n' && input != 'y')
		throw invalid_input_exception();
}

void io_manager::get_edge_input(int& src, int& dst, int num_of_vertexes)
{
	cin >> src >> dst;
	if (!(src > 0 && src <= num_of_vertexes) || !(dst > 0 && dst <= num_of_vertexes))
		throw invalid_input_exception();
}

void io_manager::get_vertexes_and_edges_input(int& vertexes, int& edges)
{
	cin >> vertexes >> edges;
	if (!(vertexes > 0) || !(edges >= 0))
		throw invalid_input_exception();
}

bool io_manager::get_is_graph_directed()
{
	char input;
	cout << "Is the graph directed : y / n " << endl;
	get_char_input(input);

	if (input == 'n') return false;

	return true;
}

void io_manager::get_graph_input(graph * i_graph, int& o_completed_edges)
{
	int v1, v2;

	for(int i = 0; i < i_graph->get_num_of_edges(); i++)
	{
		try
		{
			get_edge_input(v1, v2, i_graph->get_num_of_vertexes());
			i_graph->set_edge(i_graph->get_vertex_by_value(v1), i_graph->get_vertex_by_value(v2));
			o_completed_edges++;
		}
		catch (const invalid_input_exception& e)
		{
			cout << e.what() << endl;
			return;
		}
	}
}


