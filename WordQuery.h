#pragma once
#include "QueryBase.h"
class WordQuery :
	public QueryBase
{
private:
	string qtext;
	virtual string rep() const override;
	virtual QueryResult eval(const TextQuery&)const override;
public:
	WordQuery(string &s);
	virtual ~WordQuery();
};

