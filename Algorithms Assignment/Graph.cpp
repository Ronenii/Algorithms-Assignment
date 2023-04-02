#include "Graph.h"

graph::graph(int i_num_of_vertexes, int i_num_of_edges) : m_num_of_vertexes(i_num_of_vertexes), m_num_of_edges(i_num_of_edges)
{
	m_vertexes.reserve(i_num_of_vertexes);
	for (int i = 0; i < i_num_of_vertexes; i++)
	{
		m_vertexes.push_back(vertex(i+1));
	}
}


