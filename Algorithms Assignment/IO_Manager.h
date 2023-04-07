#pragma once
#include "DirectedGraph.h"
#include "NonDirectedGraph.h"
#include "Exceptions.h"

class io_manager
{
private:

public:
	static void run_program();
	static bool get_is_graph_directed();
	static graph* get_user_input();
	static void get_graph_input(graph* i_graph, int& o_completed_edges);
	static void get_char_input(char& input);
	static void get_edge_input(int& src, int& dst, int num_of_vertexes);
	static void get_vertexes_and_edges_input(int& vertexes, int& edges);
	static void print_euler_circuit(list<vertex*> i_euler_circuit);
};