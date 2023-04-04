#include "Graph.h"

graph::graph(int i_num_of_vertexes, int i_num_of_edges) : m_num_of_vertexes(i_num_of_vertexes), m_num_of_edges(i_num_of_edges)
{
	for (int i = 0; i < i_num_of_vertexes; i++)
	{
		m_vertexes.push_back(vertex(i + 1));
	}
}

void graph::set_all_white()
{
	for (auto& vertex : m_vertexes)
		vertex.set_color(Color::WHITE);
}

bool graph::is_all_black()
{
	for (auto& vertex : m_vertexes)
	{
		if (vertex.get_color() != Color::BLACK)
			return false;
	}
	return true;
}

void graph::visit(vertex& i_vertex)
{
	i_vertex.set_color(Color::GRAY);
	list<vertex*>& neighbors = i_vertex.get_neighbors();
	for (auto& neighbor : neighbors)
	{
		if (neighbor->get_color() == Color::WHITE)
		{
			visit(*neighbor);
		}
	}

	i_vertex.set_color(Color::BLACK);
}

bool graph::is_unsused_edge(vertex& i_current_vertex, vertex& i_white_neighbor)
{
	for (auto& neighbor : i_current_vertex.get_neighbors())
	{
		if (neighbor->get_color() == Color::WHITE)
		{
			i_white_neighbor = *neighbor;
			return true;
		}
	}
	return false;
}

list<vertex>& graph::get_euler_circuit()
{
	set_all_white();
	vector<vertex> circuit = find_circuit(get_vertex_by_value(1));
	vector<vertex> temp_circuit;
	vertex current_vertex;
	for (int i = 0; i < circuit.size(); i++)
	{
		if (has_usused_egde(circuit[i]))
		{
			current_vertex = circuit[i];
			temp_circuit = find_circuit(current_vertex);
			paste_circuit(circuit, temp_circuit, i);
		}
	}
	list<vertex>* ret = new list<vertex>(circuit.begin(), circuit.end());
	return *ret;
}

void graph::paste_circuit(vector<vertex>& i_dst, vector<vertex>& i_src, int i_start_index)
{
	int src_size = i_src.size() - 1;
	i_dst.resize((src_size) + i_dst.size());
	for (int i = 1; i <= src_size; i++)
	{
		if (i_start_index + i + src_size < i_dst.size())
		{
			i_dst[i_start_index + i + src_size] = i_dst[i_start_index + i];
		}
		i_dst[i_start_index + i] = i_src[i];
	}
}

bool graph::has_usused_egde(vertex& i_vertex)
{
	for (auto& neighbor : i_vertex.get_neighbors())
	{
		if (neighbor->get_color() == Color::WHITE)
		{
			return true;
		}
	}
	return false;
}


vector<vertex> graph::find_circuit(vertex& i_vertex)
{
	vector<vertex> circuit;
	vertex& current_vertex = i_vertex, *white_neighbor = nullptr;
	circuit.push_back(i_vertex);
	current_vertex.set_color(Color::GRAY);
	while (is_unsused_edge(current_vertex, *white_neighbor))
	{
		white_neighbor->set_color(Color::GRAY);
		circuit.push_back(*white_neighbor);
		current_vertex = *white_neighbor;
	}
	return circuit;
}

bool graph::is_vertex_exists(vertex& i_vertex) const
{
	for (auto& vertex : m_vertexes)
	{
		if (vertex == i_vertex)
			return true;
	}

	return false;
}