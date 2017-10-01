#pragma once
#include"stdhead.h"
#include"QueryResult.h"
class QueryBase
{
	friend class Query;
public:
	QueryBase();
	virtual ~QueryBase();
protected:
	using line_no = vector<string>::size_type;
	virtual string rep() const = 0;
	virtual QueryResult eval(const TextQuery&)const = 0;
};

