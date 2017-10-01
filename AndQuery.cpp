#include "AndQuery.h"



string AndQuery::rep() const
{
	return "(" + lobj.rep() + "&" + robj.rep() + ")";
}

QueryResult AndQuery::eval(const TextQuery &tq) const
{
	auto l = lobj.eval(tq);
	auto r = robj.eval(tq);
	auto line = make_shared<set<line_no>>();
	
	auto lc = l.begin();
	auto rc = r.begin();

	
	while (lc!=l.end() && rc!=r.end())
	{
		if (*lc < *rc)
		{
			lc++;
		}
		else if (*lc > *rc)
		{
			rc++;
		}
		else
		{
			line->insert(*lc);
			lc++,rc++;
		}
	}
	return QueryResult(rep(), line, l.get_file());

}

AndQuery::AndQuery(Query & l, Query & r):BinQuery(l,r,"&")
{
}

AndQuery::~AndQuery()
{
}


