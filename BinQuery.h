#pragma once
#include "QueryBase.h"
#include"Query.h"
class BinQuery :
	public QueryBase
{
	friend class QueryBase;
protected:

	string sym;
	Query lobj, robj;
public:
	BinQuery(Query& l,Query& r,string s);
	virtual ~BinQuery();
};

