#pragma once
#include "BinQuery.h"
#include"Query.h"
class AndQuery :
	public BinQuery
{
	friend class Query;
private:
	virtual string rep() const override;
	virtual QueryResult eval(const TextQuery&) const override;
public:
	AndQuery(Query& l,Query& r);
	virtual ~AndQuery();
};

