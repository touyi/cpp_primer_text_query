#include "WordQuery.h"


string WordQuery::rep() const
{
	return qtext;
}

QueryResult WordQuery::eval(const TextQuery &tq) const
{
	return tq.query(qtext);
}




WordQuery::WordQuery(string & s):qtext(s)
{
}

WordQuery::~WordQuery()
{
}
