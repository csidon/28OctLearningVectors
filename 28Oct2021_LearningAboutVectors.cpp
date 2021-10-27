//*****************************
// HEADERS
//*****************************
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
using namespace std;

//*****************************
// DEFINING STRUCTURES
//*****************************

struct softDrink 
{
	string brand, size;
	double price;

	//Constructor with default values assigned to variables
	softDrink(string br = "Coke", string sz = "L", double px = 5.50)
	{
		brand = br;
		size = sz;
		price = px;
	}

};

//*****************************
// FUNCTION PROTOTYPES
//*****************************

//vector<softDrink> inputFizzy(vector <softDrink> &f);
void outputFizzy(vector <softDrink>& f);
void writeFizzyToFile(vector <softDrink>& f);
vector <softDrink> readFizzyFromFile();


int main() 
{
	/*softDrink fizzy;*/ //instead of defining a variable or array assigned to struct, I'm defining a vector instead
	vector <softDrink> fizzy;
	vector <softDrink> fizzyFromFile;

	//inputFizzy(fizzy); //calling function to get input --- when you pass the vector, it auto-passes the reference
	//outputFizzy(fizzy);
	writeFizzyToFile(fizzy);
	fizzyFromFile=readFizzyFromFile(); //no need to pass any marker because we're reading from the file
	outputFizzy(fizzyFromFile);

}




//*****************************
// DEFINING FUNCTIONS
//*****************************

//push_back to push input to the last part of the array
//pop_back removes the last input of the array
//inputFizzy takes user input 
//vector <softDrink> inputFizzy(vector<softDrink> &f)
//{
//	softDrink fizz;  //doesn't need to be a vector because vector inputs can only be received one at a time
//	int i = 0;
//	char inputMore = 'y';
//	
//	while (tolower(inputMore) == 'y')
//	{
//
//		cout << "\nWhat is the soft drink brand? ";
//		cin >> fizz.brand;
//		cout << "\nWhat is the size of the soft drink bottle? (S, M, L)? ";
//		cin >> fizz.size;
//		cout << "\nWhat is the price of the soft drink bottle? $";
//		cin >> fizz.price;
//
//		f.push_back(fizz);
//		i++;
//		cout << "\nRecord data for another soft drink?(Y/N)\n";
//		cin >> inputMore;
//	}
//	
//
//	return f; //return f - the vector that has been passed and processed
//}

//function outputs the softDrink details into console
void outputFizzy(vector <softDrink>& f)
{
	for (int i = 0; i < f.size(); i++)
	{
		cout << "\nSoft drink brand: " << f[i].brand;
		cout << "\nSoft drink brand: " << f[i].size;
		cout << "\nSoft drink brand: " << f[i].price;

	}

}

//This function writes softDrink inputs to a file
void writeFizzyToFile(vector <softDrink>& f)
{

	fstream fizzyFile("fizzyDetails.txt", ios::app);
	for (int i = 0; i < f.size(); i++)
	{
		fizzyFile << f[i].brand << ",";
		fizzyFile << f[i].size << ",";
		fizzyFile << f[i].price << "\r";
	}
	fizzyFile.close();
}

//This function reads data from the fizzyFile
vector <softDrink> readFizzyFromFile()
{

	fstream fizzyFile("fizzyDetails.txt", ios::in);
	vector<softDrink> tempSDVec;
	softDrink f;
	string fizzyLineStorage;
	while (getline(fizzyFile,fizzyLineStorage))//while it is possible to get a line from the file, get the line and put it in storage
	{
		istringstream fizzyStream(fizzyLineStorage);
		string eachItem;


		getline(fizzyStream, eachItem, ',');
		f.brand = fizzyLineStorage;
		getline(fizzyStream, eachItem, ',');
		f.size = fizzyLineStorage;
		getline(fizzyStream, eachItem, ',');
		stringstream ss(eachItem); //converting the string to a double
		ss >> f.price;

		tempSDVec.push_back(f);

	}
	fizzyFile.close();
	return readFizzyFromFile();
}