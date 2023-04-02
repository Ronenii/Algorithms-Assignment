#pragma once
#include "Directed Graph.h"
#include "Non Directed Graph.h"
#include "Exceptions.h"

class io_manager
{
private:

public:
	 static bool get_is_graph_directed();
	 static graph * get_user_input();
	 static void get_directed_graph_input(directed_graph& dg);
};