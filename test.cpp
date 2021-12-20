
#include <bits/stdc++.h>
using namespace std;

#define PARANTHESIS_ERR 3
#define SQUAREBRAC_ERR  57
#define CURLYBRAC_ERR   1197
#define ANGLEBRAC_ERR   25137

int checkErrorCount(char x) {
  int errorCount = 0;
  switch (x) {
	case ')':
		errorCount = PARANTHESIS_ERR;
		break;
	case '}':
		errorCount = SQUAREBRAC_ERR;
		break;
	case ']':
		errorCount = CURLYBRAC_ERR;
		break;
	case '>':
		errorCount = ANGLEBRAC_ERR;
		break;
	}
	return errorCount;
}

int checkErrorCountForOpen(char x) {
    int errorCount = 0;
  switch (x) {
	case '(':
		errorCount = PARANTHESIS_ERR;
		break;
	case '{':
		errorCount = SQUAREBRAC_ERR;
		break;
	case '[':
		errorCount = CURLYBRAC_ERR;
		break;
	case '<':
		errorCount = ANGLEBRAC_ERR;
		break;
	}
	return errorCount;
}

long long int calculateSyntaxErrorCode(string data)
{
	stack<char> s;
	char x;
	long long int syntaxErr = 0;

	for (int i = 0; i < data.length(); i++)
	{
		if (data[i] == '(' || data[i] == '['
			|| data[i] == '{' || data[i] == '<')
		{
			// Push the element in the stack to track the details of each open chunks
			s.push(data[i]);
			continue;
		}

		if (s.empty())
			return -1;

		switch (data[i]) {
		case ')':
			x = s.top();
			s.pop();
			if (x != '(')
				syntaxErr += checkErrorCount(x);
			break;

		case '}':
			x = s.top();
			s.pop();
			if (x != '{')
				syntaxErr += checkErrorCount(x);
			break;

		case ']':
			x = s.top();
			s.pop();
			if (x != '[')
				syntaxErr += checkErrorCount(x);
			break;

		case '>':
			x = s.top();
			s.pop();
			if (x != '>')
				syntaxErr += checkErrorCount(x);
			break;
		}
	}

  // incase still we have some data left in the stack calculate error counts for that also.
	while(!s.empty()) {
	    x = s.top();
	    s.pop();
	    syntaxErr += checkErrorCountForOpen(x);
	}

	return syntaxErr;
}

int main()
{
	string data = "{()}[][";
	cout << "syntax error count value = " << calculateSyntaxErrorCode(data);
	return 0;
}
