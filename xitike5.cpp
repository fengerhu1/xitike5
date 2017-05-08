#include<iostream>
#include<fstream>
#include<string>
#include<map>
#include<vector>
#include<sstream>

using namespace std;

int main()
{
	fstream file;
	file.open("dictionary.txt");
	map<string, vector<string>> suffix_num;
	map<string, int> suffix_num_true;
	map<string, bool> suffix_gotten;
	map<string, bool> vec_gotten;
	string word;
	string input;
	cin >> input;
	int model = 0;
	int n;
	if ((input[0] <= '9') &&(input[0] >= '1'))
	{
		model = 1;
		stringstream ss;
		ss << input;
		ss >> n;
	}
	if (model == 1)
	{
		while (file >> word)
		{
			string suffix;
			if (word.size() >= n)
			{
			suffix = word.substr(word.size() - n, n);
			suffix_num[suffix].push_back(word);
			suffix_num_true[suffix] = suffix_num[suffix].size();
			suffix_gotten[suffix] = true;
			}
		}
		map<string, int> ::iterator it_1;
		map<string, int> ::iterator it_2;
		for (int i = 0; i < 10; i++)
		{
			int tot = 0;
			it_2 = suffix_num_true.begin();
			for (it_1 = suffix_num_true.begin(); it_1 != suffix_num_true.end(); it_1++)
			{
				if ((suffix_gotten[it_1->first]) && (it_1->second > tot))
				{
					tot = it_1->second;
					it_2 = it_1;
				}
			}
			suffix_gotten[it_2->first] = false;
			if(it_2->second>0)
	
				std::cout << it_2->first << " num: " << it_2->second << endl;
		}
	}
	else
	{
		n = input.size();
		while (file >> word)
		{
			string suffix;
			if (word.size() >= n)
			{
				suffix = word.substr(word.size() - n, n);
				suffix_num[suffix].push_back(word);
				suffix_num_true[suffix] = suffix_num[suffix].size();
				suffix_gotten[suffix] = true;
			}
		}
		if (suffix_num_true[input] != 0)
		{
			std::cout << suffix_num_true[input] << endl;
			for (int i = 0; i < suffix_num[input].size(); i++)
				vec_gotten[suffix_num[input][i]] = true;
			for (int i = 0; i < suffix_num[input].size(); i++)
			{
				string tot = "";
				int k = 0;
				for (int j = 0; j < suffix_num[input].size(); j++)
				{
					if ((vec_gotten[suffix_num[input][j]]) && (suffix_num[input][j] > tot))
					{
						tot = suffix_num[input][j];
						k = j;
					}
				}
				vec_gotten[suffix_num[input][k]] = false;
				std::cout << suffix_num[input][k] << endl;
			}
			
		}
	}
	int aaa;
	std::cin >> aaa;
	return 0 ;
}