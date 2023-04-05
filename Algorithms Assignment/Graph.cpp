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
	list<vertex>& neighbors = i_vertex.get_neighbors();
	for (auto& neighbor : neighbors)
	{
		vertex& real_current_neighbor = m_vertexes[neighbor.get_value() - 1];
		if (real_current_neighbor.get_color() == Color::WHITE)
		{
			visit(real_current_neighbor);
		}
	}

	i_vertex.set_color(Color::BLACK);
}

/*bool graph::is_unsused_edge(vertex i_current_vertex, list<vertex>& i_neighbors_list, vertex& o_next_neighbor)
{
	for (auto& neighbor : i_neighbors_list)
	{
		if (neighbor.get_color() == Color::WHITE)
		{
			neighbor.set_color(Color::GRAY);
			o_next_neighbor = neighbor;
			vertex& ref_real_next_neighbor = m_vertexes[neighbor.get_value() - 1];
			// in case the graph is non directed
			change_edeges_to_used(i_current_vertex, ref_real_next_neighbor);
			return true;
		}
	}
	return false;
}*/

void graph::change_edeges_to_used(int i_current_vertex_value, vertex& neighbor)
{
	if (!is_directed())
	{
		for(auto& vertex : neighbor.get_neighbors())
		{
			if (vertex.get_value() == i_current_vertex_value)
			{
				vertex.set_color(Color::GRAY);
				break;
			}
		}
	}
}

list<vertex*> graph::get_euler_circuit()
{
	vector<vertex*> circuit = find_circuit(1);
	vector<vertex*> temp_circuit;
	
	for (int i = 0; i < circuit.size(); i++)
	{
		if (has_usused_egde(*circuit[i]))
		{
			temp_circuit = find_circuit(circuit[i]->get_value());
			paste_circuit(circuit, temp_circuit, i);
		}
	}
	list<vertex*>* ret = new list<vertex*>(circuit.begin(), circuit.end());
	return *ret;
	

}

void graph::paste_circuit(vector<vertex*>& i_dst, vector<vertex*>& i_src, int i_start_index)
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
	list<vertex>& neighbors = i_vertex.get_neighbors();
	for (auto& neighbor : neighbors)
	{
		if (neighbor.get_color() == Color::WHITE)
		{
			return true;
		}
	}
	return false;
}


vector<vertex*> graph::find_circuit(int i_value)
{
	vector<vertex*> circuit;
	circuit.push_back(&get_vertex_by_value(i_value));
	list<vertex>* ref_neighbors_list = &get_vertex_by_value(i_value).get_neighbors();
	bool flag = true;
	vertex* next_vertex = mashu(ref_neighbors_list, 1, flag);
	while(flag)
	{
		circuit.push_back(next_vertex);
		ref_neighbors_list = &next_vertex->get_neighbors();
		next_vertex = mashu(ref_neighbors_list, next_vertex->get_value(), flag);
	}

	return circuit;
}

vertex* graph::mashu(list<vertex>* ref_neighbors_list, int current_vertex_value, bool& o_flag)
{
	for (auto& neighbor : *ref_neighbors_list)
	{
		if (neighbor.get_color() == Color::WHITE)
		{
			neighbor.set_color(Color::GRAY);
			vertex* ret = &m_vertexes[neighbor.get_value() - 1];
			change_edeges_to_used(current_vertex_value, m_vertexes[neighbor.get_value() - 1]);
			return ret;
		}
	}
	o_flag = false;
	return nullptr;
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