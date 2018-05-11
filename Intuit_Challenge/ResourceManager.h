#pragma once
#include<iostream>
#include<unordered_map>
#include<fstream>
#include<sstream>
#include<algorithm>
#include<array>

using namespace std;


class ResourceManager
{
public:
	std::unordered_map<std::string, float> CategorizeIncExp(string fileName);
		
};


