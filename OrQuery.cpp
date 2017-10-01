#include "OrQuery.h"






string OrQuery::rep() const
{
	return "(" + lobj.rep() + "|" + robj.rep() + ")";
}

QueryResult OrQuery::eval(const TextQuery & tq) const
{
	auto l = lobj.eval(tq);
	auto r = robj.eval(tq);

	auto line = make_shared<set<line_no>>();
	for (auto i = l.begin(); i != l.end(); i++)
	{
		line->insert(*i);
	}
	for (auto i = r.begin(); i != r.end(); i++)
	{
		line->insert(*i);
	}
	return QueryResult(rep(), line, l.get_file());
}

OrQuery::OrQuery(Query & l, Query & r):BinQuery(l,r,"|")
{
}

OrQuery::~OrQuery()
{
}

