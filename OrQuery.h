#pragma once
#include "BinQuery.h"
#include"Query.h"
class OrQuery :
	public BinQuery
{
	friend class Query;
private:
	virtual string rep() const override;
	virtual QueryResult eval(const TextQuery& tq) const override;
public:
	OrQuery(Query& l,Query& r);
	virtual ~OrQuery();
};

