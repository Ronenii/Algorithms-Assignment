#include "Vertex.h"

void vertex::add_neighbor(vertex & i_neighbor)
{
	if (!neighbor_exists(i_neighbor))
	{
		m_neighbors.push_back(i_neighbor);
	}
}

bool vertex::neighbor_exists(const vertex& i_neighbor) const
{
	for (auto& neighbor : m_neighbors)
	{
		if (i_neighbor.m_value == neighbor.m_value)
		{
			return true;
		}
	}

	return false;
}

void vertex::remove_neighbor(vertex & vertex_to_remove)
{
	m_neighbors.remove(vertex_to_remove);
	vertex_to_remove.get_neighbors_by_ref().remove(*this);
}

bool vertex::has_neighbors()
{
	return !m_neighbors.empty();
}