#include "NotQuery.h"



string NotQuery::rep() const
{
	return "~" + query.rep();
}

QueryResult NotQuery::eval(const TextQuery & tq) const
{
	auto res = query.eval(tq);
	auto cnt = res.begin();
	auto line = make_shared<set<line_no>>();
	for (int i = 0;i<res.get_file()->size();i++)
	{
		if (i == *cnt)
		{
			cnt++;
		}
		else
		{
			line->insert(i);
		}
	}
	return QueryResult(rep(), line, res.get_file());
}



NotQuery::NotQuery(Query & q):query(q)
{
}

NotQuery::~NotQuery()
{
}

Query operator~(Query & que)
{
	return shared_ptr<QueryBase>(new NotQuery(que));
}
