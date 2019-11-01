#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <iostream>
#include <string>
#include <fstream>

void hello(void)
{
	printf("Hello world!!!\n");	
}

bool activateLicense(void)
{
	std::string str1;
	std::string str2;
	std::system("dmidecode -s system-serial-number > license.txt"); //dmi - desktop management interface
	std::ifstream license;
	license.open("license.txt");
	std::ifstream key;
	key.open("key.txt");
	getline(license, str1);
	getline(key, str2);
	if (str1 == str2)
	{
		std::cout << "Activation successful" << std::endl;
		return true;
	}
	std::cout << "Activation unsuccessful" << std::endl;
	return false;
} 

void printMenu(void)
{	
	system("clear");
	printf("МЕНЮ:\n");
	printf("1 - Запустить программу\n");
	printf("2 - Активировать лицензию\n");
	printf("0 - Выход\n");
	printf("> ");
}

int main(void)
{
	char ch;
	bool flag = false;
	printMenu();
    do
	{
	    std::cin >> ch;

		switch(ch)
		{
		case '1':
			printMenu();
			if (flag == true)
			{
				hello();
				printf("> ");
			}
			else
			{
				printf("\nНет лицензии\n\n");
				printf("> ");
			}		
			break;
		case '2':
			printMenu();
			flag = activateLicense();
			printf("> ");
			break;
		case '0':
			break;
		default:
			printMenu();
			break;
		}
	}
    while(ch != '0');
	return 0;
}

