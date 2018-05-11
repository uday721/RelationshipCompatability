#include "ResourceManager.h"

std::unordered_map<std::string, float> ResourceManager::CategorizeIncExp(string fileName)
{
	const int numOfCategories = 15;
	std::string csv_File_name = fileName;
	std::ifstream data(csv_File_name);
	std::string line;
	
	
	float totalExpense[numOfCategories] = { 0.0f };
	float totalExpenditure = 0.0f;
	float totalDebt = 0.0f;
	int totalIncome = 0;
	
	const string categoryNames[numOfCategories] = { "Education","Sports","Food and Dining","Transportation","Art","Music","Entertainment","Baby Products","House and Maintenance","Pets","Health","Wine and Bars","Weddings and Divorse","Late Payment","Other Expenses" };

	//All the vendors are categorized in a map.
	std::unordered_map<std::string, int> catergory = {
	{"Paycheck",1},{"ACS - Student Loans",2},{"Amazon Order - Biology Book",2},{"Amazon Order - Mathematics Book",2},{"Amazon Order - Science Book",2},{"Online Education Courses",2},{"Navient - Student Loans",2},{"Library Membership",2},{"Mary's Book Store",2},{"Science Museum",2},
	{"Amazon Order - Athletic Equipment",3},{"Athletic Apparel",3},{"Bowling",3},{"Dick's Sporting Goods",3},{"Ice Skating Rink",3},{"NBA Ticket - Lakers",3},{"NFL Ticket - Chargers",3},{"Sam's Sporting Apparel",3},
	{"Coffee",4},{"Food Delivery - GrubHub",4},{"Food Delivery - Uber Eats",4},{"Restaurant - Burgers",4},{"Restaurant - Chinese",4},{"Restaurant - Pizza",4},{"Restaurant - Steakhouse",4},{"Starbucks Coffee",4},
	{"Bike Rental",5},{"Public Transportation - Bus Pass",5},{"Public Transportation - Train Pass",5},{"Taxi",5},{"Uber",5},{"Lyft",5},
	{"Amazon Order - Paint Bushes",6},{"Amazon Order - Paint Canvas",6},{"Art Auction",6},{"Art Museum",6},{"Art's Art Supplies",6},{"Ashley's Craft Store",6},{"Painting Course Fees",6},{"San Diego Museum",6},{"Michael's Crafts",6},
	{"Guitar Center",7},{"Karaoke Bar",7},{"Music Lessons - Piano",7},{"Podcast Subscription",7},
	{"Amazon Order - Star Wars Figurine",8},{"Concert Ticket",8},{"DVD - Star Trek",8},{"Movie Ticket",8},{"Netflix Subscription",8},{"On Demand Movie",8},{"On Demand TV",8},{"PlayStation Membership",8},{"Red Box DVD Rental",8},{"Video Game - PlayStation",8},
	{"Amazon Order - Baby Crib",9},{"Babies R Us",9},{"BuyBuyBaby.com",9},{"Hospital - Prenatal Care",9},
	{"Gas & Electric",10},{"Housing Rent",10},{"Von's Groceries",10},{"Water & Sewer",10},{"Whole Foods",10},{"Ralph's Grocery Store",10},{"Time Warner Cable",10},{"Credit Card Payment",10},
	{"Pet Smart",11},{"Pet Supply - Cat Food",11},	
	{"Total Gym Fees",12},{"GNC",12},{"Sprouts Market",12},{"Vitamin Shoppe",12},
	{"Wine Bar",13},{"Wine Delivery",13},{"Green Flash Brewery",13},{"John's Bar & Restaurant",13},{"Owl Night Club",13},{"Rodriguez's Bar and Grill",13},{"Fisker Night Club",13},{"Seaside Bar",13},
	{"Wedding Planner",14},{"Divorce Lawyer Fees",14},
	{"Bank Fee - Negative Balance",15},{"Credit Card Overdraft Fee",15},{"Time Warne Cable - Late Payment Fee",15},{"Water & Sewer - Late Payment Penalty",15},{"Housing Rent - Late Fee",15},
	{"FedEx Shipping",16},{"Goods2 - ThinkGeek",16},{"Hamilton Move & Stotrage",16},{"Home Depot",16},{"Jerome's Furniture",16},{"Kay Jewelry",16},{"Mark's Movers",16},{"Refrigerator Depot",16},{"Southwest Flights - Cancun",16},{"Best Western Hotel",16},{ "Cancun Beach Resort",16 },{ "Comfort Inn",16 }
	};

	std::unordered_map<std::string, float> parsedData;

	//skip the first line in the csv file
	std::getline(data, line);

	while (std::getline(data, line)) {
		std::stringstream  lineStream(line);
		std::string        cell;
		int column_count = 0;


		while (std::getline(lineStream, cell, ',')) {
			column_count += 1;
			string word;
			float amount = 0.0f;

			// You have a cell!!!!
			if (column_count == 3) {
				word = cell;
				//to remove the double quotes from babies "r" us vendor name
				word.erase(remove(word.begin(), word.end(), '\"'), word.end());

			}

			std::unordered_map<std::string, int>::const_iterator got = catergory.find(word);

			if (got != catergory.end()){
				std::getline(lineStream, cell, ','); // getting the corresponding amount of the vendor
				amount = std::stof(cell);
				totalDebt += amount;
			}

			switch (got->second)
			{
			case 1:totalIncome += amount; // case 1 is total credit in the transactions
				break;
			case 2:totalExpense[0] += amount; // case 2 is total money spent on education
				break;
			case 3:totalExpense[1] += amount; // case 3 is total money spent on sports and accessories
				break;
			case 4:totalExpense[2] += amount; // case 4 is total money spent on food and dining
				break;
			case 5:totalExpense[3] += amount; // case 5 is total money spent on transportation
				break;
			case 6:totalExpense[4] += amount; // case 6 is total money spent on arts
				break;
			case 7:totalExpense[5] += amount; // case 7 is total money spent on music
				break;
			case 8:totalExpense[6] += amount; // case 8 is total money spent on entertainment
				break;
			case 9:totalExpense[7] += amount; // case 9 is money spent on baby products
				break;
			case 10:totalExpense[8] += amount; // case 10 is money spent on house and maintenance
				break;
			case 11:totalExpense[9] += amount; // case 11 is money spent on pets
				break;
			case 12:totalExpense[10] += amount; // case 12 is money spent on health
				break;
			case 13:totalExpense[11] += amount; // case 13 is money spent on wines and bars
				break;
			case 14:totalExpense[12] += amount; // case 14 is money spent on wedding and divorse
				break;
			case 15:totalExpense[13] += amount; // case 15 is money spent on late payments
				break;
			case 16:totalExpense[14] += amount; // case 16 is other expenses
				break;
			
			default:
				break;
			};
		}
	}
	totalExpenditure = totalDebt - totalIncome;
	cout << endl;
	cout << "Total Income:" << totalIncome << endl;
	cout << "Total Expenditure:" << totalExpenditure << endl;
	cout << "total Debt" << totalDebt << endl;
	cout << endl;
	//parsedData[categoryNames[0]]= totalExpense[0];

	for (unsigned int i = 0; i < 15; i++)
	{
		//percentage spent on each category
		parsedData[categoryNames[i]] = (totalExpense[i]/ totalExpenditure)*100;
	}
	

	return parsedData;
}




