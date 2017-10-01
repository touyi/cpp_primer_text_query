#include "TextQuery.h"
#include"QueryResult.h"

using std::getline;

TextQuery::TextQuery(ifstream& is): file(new vector<string>())
{
	if (!is)
		return;
	string text;
	int now = 0;
	while (getline(is,text))
	{
		file->push_back(text);
		istringstream line(text);
		while (line >> text)
		{
			if (word.count(text) > 0)
			{
				word[text]->insert(now);
			}
			else {
				word[text].reset(new set<line_no>());
				word[text]->insert(now);
			}
		}
		now++;
	}
}


QueryResult TextQuery::query(const string &s) const
{
	static shared_ptr<set<line_no>> nodata(new set < line_no >);
	auto res = word.find(s);
	if (res == word.end())
	{
		return QueryResult(s, nodata, file);
	}
	else
	{
		return QueryResult(s, res->second, file);
	}
}

TextQuery::~TextQuery()
{
}
