#include "Graph.h"

graph::graph(int i_num_of_vertexes, int i_num_of_edges) : m_num_of_vertexes(i_num_of_vertexes), m_num_of_edges(i_num_of_edges)
{
	for (int i = 0; i < i_num_of_vertexes; i++)
	{
		m_vertexes.push_back(vertex(i + 1));
	}
}

void graph::visit(vertex& i_vertex)
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

void graph::visit(vertex i_vertex)
{
	i_vertex.set_color(Color::GRAY);
	list<vertex>& neighbors = i_vertex.get_neighbors();
	for (auto& neighbor : neighbors)
	{
		if (neighbor.get_color() == Color::WHITE)
		{
			visit(neighbor);
		}
	}

	i_vertex.set_color(Color::BLACK);
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

bool graph::dfs()
{
	bool isSingleTree;

	for (auto& v : m_vertexes)
	{
		v.set_color(Color::WHITE);
	}

	for (auto& v : m_vertexes)
	{
		if (v.get_color() == Color::WHITE)
		{
			visit(v);
		}
	}
}
