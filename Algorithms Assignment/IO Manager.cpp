#include "IO Manager.h"

void io_manager::run_program()
{
	list<vertex*> euler_circuit;
	graph* input_graph;
	input_graph = get_user_input();
	get_graph_input(input_graph);
	if(input_graph->is_euler())
	{
		cout << "The graph is aulerian" << endl;
		euler_circuit = input_graph->get_euler_circuit();
		print_euler_circuit(euler_circuit);
	}
	else
	{
		cout << "Graph is not aulerian" << endl;
	}
	// free allocation.

}


graph* io_manager::get_user_input()
{
	int vertices, edges;

	const bool is_directed = get_is_graph_directed();
	while(true)
	{
		try
		{
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
			cout << "Exception thrown: " << e.what() << endl;
		}
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
		throw invalid_edge_input_exception();
}

void io_manager::get_vertexes_and_edges_input(int& vertexes, int& edges)
{
	cin >> vertexes >> edges;
	if (!(vertexes > 0) || !(edges >= 0))
		throw invalid_input_exception();
}

void io_manager::print_euler_circuit(list<vertex*> i_euler_circuit)
{
	cout << '(';
	for (auto& vertex : i_euler_circuit)
	{
		cout << vertex->get_value() << ',';
	}
	cout << ')' << endl;
	
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

void io_manager::get_graph_input(graph * i_graph)
{
	int v1, v2;

	for(int i = 0; i < i_graph->get_num_of_edges(); i++)
	{
		try
		{
			get_edge_input(v1, v2, i_graph->get_num_of_vertexes());
			i_graph->set_edge(i_graph->get_vertex_by_ref(v1), i_graph->get_vertex_by_ref(v2));
		}
		catch (const invalid_edge_input_exception& e)
		{
			cout << "Exception thrown: " << e.what() << endl;
			i--;
		}
	}
}


