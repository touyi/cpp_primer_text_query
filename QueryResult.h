#pragma once
#include"stdhead.h"
#include"TextQuery.h"
ostream& operator<<(ostream& out, const QueryResult&);

class QueryResult
{
	friend ostream& operator<<(ostream&, const QueryResult&);
public:
	QueryResult(string s, shared_ptr<set<TextQuery::line_no>>, shared_ptr<vector<string>>);
	~QueryResult();
	auto begin() {
		return lines->begin();
	}
	auto end() {
		return lines->end();
	}
	auto get_file()
	{
		return text;
	}
private:
	string sought;
	shared_ptr<set<TextQuery::line_no>> lines;
	shared_ptr<vector<string>> text;
};

