#pragma once

#include "Vertex.h"

class directed_vertex : public vertex
{
private:
	int m_in_degree=0, m_out_degree=0;
public:
	directed_vertex(const int i_value) : vertex(i_value) {}
	int get_in_degree() const { return m_in_degree; }
	void set_in_degree(const int i_in_degree) { m_in_degree = i_in_degree; }
	int get_out_degree() const { return m_out_degree; }
	void set_out_degree(const int i_out_degree) { m_out_degree = i_out_degree; }
};
