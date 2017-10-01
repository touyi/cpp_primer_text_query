#pragma once
#include "QueryBase.h"
#include"Query.h"
class NotQuery :
	public QueryBase
{
private:
	virtual string rep() const override;
	virtual QueryResult eval(const TextQuery& tq)const override;
	Query query;
public:
	NotQuery(Query&q);
	virtual ~NotQuery();
};

