#pragma once
#include"stdhead.h"
class QueryResult;
class TextQuery
{

public:
	TextQuery(ifstream& is);
	using line_no = vector<string>::size_type;
	QueryResult query(const string&) const;
	~TextQuery();
private:
	shared_ptr<vector<string>> file;
	map<string, shared_ptr<set<line_no>>> word;
};

