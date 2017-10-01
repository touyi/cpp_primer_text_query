#include "BinQuery.h"
#include"AndQuery.h"
#include"OrQuery.h"


BinQuery::BinQuery(Query & l, Query & r, string s):lobj(l),
robj(r),
sym(s)
{
}

BinQuery::~BinQuery()
{
}

Query operator&(Query & left, Query & right)
{
	return shared_ptr<QueryBase>(new AndQuery(left, right));
}

Query operator|(Query & left, Query & right)
{
	return shared_ptr<QueryBase>(new OrQuery(left, right));
}
