#include<algorithm>
#include<iostream>
#include<fstream>
#include<set>

using namespace std;

int main()
{
	string from, to;
	cin >> from >> to;
	
	ifstream is {from};
	ofstream os {to};
	
	set<string> b {istream_iterator<string>{is}, istream_iterator<string>{}};  // read input
	copy(b.begin(),b.end(),ostream_iterator<string>{os, "\n"});  // copy to output
	
	return !is.eof() || !os;
}

