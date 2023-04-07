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
	list<vertex> neighbors = i_vertex.get_neighbors();
	i_vertex.set_color(Color::GRAY);
	for (auto& neighbor : neighbors)
	{
		vertex& real_neighbor = m_vertexes[neighbor.get_value() - 1];
		mark_edge(i_vertex, real_neighbor);
		visit(real_neighbor);
	}
	i_vertex.set_color(Color::BLACK);
}

void graph::mark_edge(vertex& i_current_vertex, vertex& i_neighbor_vertex)
{
	i_current_vertex.get_neighbors().remove(i_neighbor_vertex);
	mark_edge_for_non_directed_graph(i_current_vertex, i_neighbor_vertex);
}

void graph::mark_edge_for_non_directed_graph(vertex& i_current_vertex, vertex& i_neighbor_vertex)
{
	if (!is_directed())
	{
		i_neighbor_vertex.get_neighbors().remove(i_current_vertex);
	}
}

void graph::get_and_print_euler_circuit()
{
	graph* dummy_graph = get_dummy_graph();
	list<vertex*> circuit = dummy_graph->find_circuit(dummy_graph->get_vertex_by_value(1));
	list<vertex*> temp_circuit;
	
	for (int i = 0; i < circuit.size(); i++)
	{
		vertex& current_vertex = get_vertex_from_circuit(circuit, i);
		if (current_vertex.has_neighbors())
		{
			temp_circuit = dummy_graph->find_circuit(current_vertex);
			paste_circuit(circuit, temp_circuit, i);
		}
	}

	print_euler_circuit(circuit);
	delete(dummy_graph);
}

void graph::print_euler_circuit(list<vertex*>& i_circuit)
{
	bool skip_first_comma = true;
	cout << '(';
	for (auto& vertex : i_circuit)
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

vertex& graph::get_vertex_from_circuit(list<vertex*>& i_circuit, int i_index)
{
	auto it = i_circuit.begin();
	advance(it, i_index);
	return *(*it);
}

void graph::paste_circuit(list<vertex*>& i_dst, list<vertex*>& i_src, int i_start_index)
{
	i_src.pop_front();
	auto pos = next(i_dst.begin(), i_start_index + 1);
	i_dst.insert(pos, i_src.begin(), i_src.end());
}

list<vertex*> graph::find_circuit(vertex& i_vertex)
{
	list<vertex*> circuit;
	vertex copy_of_neighbor, *current_vertex = &i_vertex;
	circuit.push_back(current_vertex);
	while (current_vertex->has_neighbors())
	{
		copy_of_neighbor = current_vertex->get_neighbors().front();
		vertex& real_neighbor = m_vertexes[copy_of_neighbor.get_value() - 1];
		mark_edge(*current_vertex, real_neighbor);
		circuit.push_back(&real_neighbor);
		current_vertex = &real_neighbor;
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