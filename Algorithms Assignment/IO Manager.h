#pragma once
#include "Directed Graph.h"
#include "Non Directed Graph.h"
#include "Exceptions.h"

class io_manager
{
private:

public:
	bool get_is_graph_directed();
	graph* get_user_input();
	void get_graph_input(graph* i_graph);
	void get_char_input(char& input);
	void get_edge_input(int& src, int& dst, int num_of_vertexes);
	void get_vertexes_and_edges_input(int& vertexes, int& edges);

};