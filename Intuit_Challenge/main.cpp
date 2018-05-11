#include<iostream>
#include<fstream>
#include<map>
#include<unordered_map>
#include<string>
#include <sstream>
#include<algorithm>
#include"ResourceManager.h"
#include<cmath>


void PrintMap(unordered_map<std::string, float> map)
{
	
	typedef std::unordered_map<std::string, float>::iterator iterator;
	for (iterator p = map.begin(); p != map.end(); p++)
	{
		cout << p->first << ":\t " << p->second <<"%"<< endl;
		
	}
	
}


float Compatability(string fileOne,string fileTwo)
{
	//the below value is obtained by training data present in each user to every other user.
	float highestDiff = 13.3193;
	float user1Value = 0.0f, user2Value =0.0f,compatibilityFactor=0.0f;

	std::unordered_map<std::string, int> catergoryweightage = { 
		{"Education",16 }, { "Sports",10 }, { "Food and Dining",7 }, {"Transportation",5},{"Art",10},{"Music",23},{"Entertainment",11},{"Baby Products",672},
		{"House and Maintenance",11},{"Pets",44},{"Health",17},{"Wine and Bars",15},{"Weddings and Divorse",1786},{"Late Payment",80},{"Other Expenses",94}
	};

	ResourceManager callFunc;
	// Will store the word and count.
	std::unordered_map<std::string, float> userOneInfo = callFunc.CategorizeIncExp(fileOne);
	// Print the words map.
	cout <<"The transaction percentages of first person:" << endl;
	PrintMap(userOneInfo);

	cout << endl;

	std::unordered_map<std::string, float> userTwoInfo = callFunc.CategorizeIncExp(fileTwo);
	cout <<"The transaction of second person:" << endl;
	PrintMap(userTwoInfo);

	cout << endl;

	//gets the diff. in expenditure of similar category with the help of category weightage 
	typedef std::unordered_map<std::string, float>::iterator iterator;
	for (iterator i = userOneInfo.begin(); i != userOneInfo.end();++i)
	{
		if (userTwoInfo[i->first] !=0 && userOneInfo[i->first]!=0)
		{
			float value = std::abs(((userOneInfo[i->first]*catergoryweightage[i->first])/100)-((userTwoInfo[i->first]*catergoryweightage[i->first])/100));
			compatibilityFactor += value;
		}
	}
	compatibilityFactor = 1 - (compatibilityFactor/highestDiff);
	
	return compatibilityFactor;
}


int main()
{

	float compatibilityRatio=0.0f;
	
	std::string fileOne,fileTwo;
	cout << "Please enter the profile of first person:" << flush;
	getline(cin, fileOne);
	fileOne = "transaction-data/" + fileOne + ".csv";

	cout << "Please enter the profile of second person:" << flush;
	getline(cin, fileTwo);
	fileTwo = "transaction-data/" + fileTwo + ".csv";

	compatibilityRatio=Compatability(fileOne,fileTwo);
	
	cout << "The above two people are:" << compatibilityRatio<<"\tor\t"<<(compatibilityRatio*100)<<"% compatible"<< endl;
	


	cin.get();

	return EXIT_SUCCESS;
}





