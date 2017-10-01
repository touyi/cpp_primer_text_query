#include"stdhead.h"
#include"TextQuery.h"
#include"QueryResult.h"
#include"Query.h"
int main()
{
	ifstream file("1.txt");
	TextQuery textq(file);
	Query ans = Query("ni") & Query("hao") & (~Query("ri"));
	cout << ans.eval(textq) << endl;
	system("pause");
	return 0;
}