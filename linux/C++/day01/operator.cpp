#include <iostream>
using namespace std;

int main(void)
<%
	int a = 0;
	int b = 1;
	if(a or b)<%
		cout << "ture" << endl;
	%>
	else<%
		cout << "false" << endl;
	%>
%>
