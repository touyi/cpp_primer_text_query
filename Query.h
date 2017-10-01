#pragma once
#include"stdhead.h"
#include"QueryBase.h"
#include"QueryResult.h"
#include"TextQuery.h"

class Query
{
	friend Query operator~(Query& que);
	friend Query operator&(Query& left, Query& right);
	friend Query operator|(Query& left, Query& right);
public:
	Query(string);
	~Query();
	string rep() const { return query->rep(); }
	QueryResult eval(const TextQuery& tq) const { return query->eval(tq); }
private:
	shared_ptr<QueryBase> query;
	Query(shared_ptr<QueryBase>&_q) :query(_q) {};
};
Query operator~(Query& que);
Query operator&(Query& left, Query& right);
Query operator|(Query& left, Query& right);