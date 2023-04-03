#pragma once

#include  <list>
#include <vector>

using namespace std;

class vertex
{
private:
	int m_value;
	list<vertex> m_neighbors;
public:
	vertex(int i_value) { m_value = i_value; }
	vertex(){};
	void add_neighbor(vertex& i_neighbor);
	bool neighbor_exists(const vertex& i_neighbor) const;
	int get_value()const { return m_value; }
	void set_value(int i_value) { m_value = i_value; }
	bool operator==(const vertex& i_other)const { return i_other.m_value == m_value; }
};