#include "QueryResult.h"





QueryResult::QueryResult(string s, shared_ptr<set<TextQuery::line_no>> li, shared_ptr<vector<string>> tex) :
	sought(s),
	lines(li),
	text(tex)
{
}

QueryResult::~QueryResult()
{
}

ostream & operator<<(ostream & out, const QueryResult & msg)
{
	out << msg.sought << endl;
	for (auto i = msg.lines->begin(); i != msg.lines->end(); i++)
	{
		out << *i << endl;
		out << (*msg.text)[*i] << endl;
	}

	return out;
}
