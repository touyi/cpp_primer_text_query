#include "Query.h"
#include"WordQuery.h"



Query::Query(string str):query(new WordQuery(str))
{
	
}

Query::~Query()
{
}






