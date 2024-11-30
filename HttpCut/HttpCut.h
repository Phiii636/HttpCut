#pragma once
#include <iostream>  
#include <fstream>  
#include <string>

using namespace std;

#define SUCCESS true
#define FAIL false

#define _in_
#define _out_
#define _typein_

namespace my
{
	bool HttpCut(string _in_ name);
	bool HttpCut(_typein_);
	bool DeleteStr(string& _in_ _out_ str, string _in_ word);
	bool FindReplace(string& _in_ _out_ str, string _in_ word1, string _in_ word2);
}