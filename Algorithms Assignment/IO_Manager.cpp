#include "IO_Manager.h"

// Method which runs the entire program. 
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
				get_and_print_euler_circuit(input_graph);
			}
			else
			{
				cout << "The graph is not aulerian" << endl;
			}
		}
		delete(input_graph);
	}
}

// Recieves user input and creates a directed or non directed graph with empty vertices based on the input.
// returns said graph.
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

// Recieves the o_iput as an output parameter, can only accept 'n' or 'y' as input.
void io_manager::get_char_input(char& o_input)
{
	cin >> o_input;
	if (o_input != 'n' && o_input != 'y')
		throw invalid_input_exception();
}

// User input and edge he wants to create and the method validates it.
void io_manager::get_edge_input(int& o_src, int& o_dst, int i_num_of_vertexes)
{
	cin >> o_src >> o_dst;
	if (!(o_src > 0 && o_src <= i_num_of_vertexes) || !(o_dst > 0 && o_dst <= i_num_of_vertexes))
		throw invalid_input_exception();
}

// Recieves how much edges and vertices the user wants as input and validates said input.
void io_manager::get_vertexes_and_edges_input(int& o_vertexes, int& o_edges)
{
	cin >> o_vertexes >> o_edges;
	if (!(o_vertexes > 0) || !(o_edges >= 0))
		throw invalid_input_exception();
}

// Gets user input for weather the graph is directed or not, validates said input.
bool io_manager::get_is_graph_directed()
{
	char input;
	cout << "Is the graph directed : y / n " << endl;
	get_char_input(input);

	if (input == 'n') return false;

	return true;
}

// User inputs the edges he wants to create and the method validates it. User can only create the number of edges he has requested.
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

//Prints out the given vertex list in the required format.
void io_manager::print_vertex_list(list<vertex*>& i_vList)
{
	bool skip_first_comma = true;
	cout << '(';
	for (auto& vertex : i_vList)
	{
		if (skip_first_comma)
		{
			cout << vertex->get_value();
			skip_first_comma = false;
		}
		else
		{
			cout << ',' << vertex->get_value();
		}
	}
	cout << ')' << endl;
}

// Finds this graph's euler circuit and prints it out.
void io_manager::get_and_print_euler_circuit(graph * i_graph)
{
	graph* dummy_graph = i_graph->get_dummy_graph();
	list<vertex*> circuit = dummy_graph->find_circuit(dummy_graph->get_vertex_by_value(1));
	list<vertex*> temp_circuit;

	for (int i = 0; i < circuit.size(); i++)
	{
		vertex& current_vertex = vertex::get_vertex_from_circuit(circuit, i);
		if (current_vertex.has_neighbors())
		{
			temp_circuit = dummy_graph->find_circuit(current_vertex);
			vertex::paste_circuit(circuit, temp_circuit, i);
		}
	}

	print_vertex_list(circuit);
	delete(dummy_graph);
}

