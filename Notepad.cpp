#include <fstream>
#include <iostream>
#include <string>
#include <clocale>
#include <Windows.h>

void GetName(std::string *name)
{
	//std::cout << "Введите желаемое имя текстового файла" << std::endl;
	//getline(std::cin, *name);
	while(*name == "")
	{
		std::cout << "Введите желаемое имя текстового файла" << std::endl;
		getline(std::cin, *name);
	}
	system("CLS");

}

void GetExt(std::string* ext) {

	char ext_change = 0;

	std::cout << "Пожалуйста выберете цифру в соответствии с интересующим вас расширением для файла" << std::endl;
	std::cout << "(если не знаете что выбрать выберете пункт 1)" << std::endl;
	std::cout << "1 - .txt" << std::endl;
	std::cout << "2 - .cfg" << std::endl;
	std::cout << "3 - .cmd" << std::endl;
	std::cout << "4 - пользовательское расширение" << std::endl << std::endl;
	std::cin >> ext_change;
	while(ext_change != '1' && ext_change != '2' && ext_change != '3' && ext_change != '4') {
		std::cout << "Введите корректный символ" << std::endl;
		std::cin >> ext_change;
	}
	system("CLS");
	
		switch (ext_change)
		{
		case '1':
			*ext = "txt";
			break;
		case '2':
			*ext = "cfg";
			break;

		case '3':
			*ext = "cmd";
			break;


		case '4':
			std::string UserExt;
			std::cout << "Введите без точки требуемое вам расширение для файла (мне не приниципиально можешь и с пробелами я всё равно их удалю)" << std::endl;
			getchar();
			getline(std::cin, UserExt);
			//std::cin >> UserExt;
			int sizeExt = UserExt.size();
			//UserExt += "0";
			for (int i = 0; i < sizeExt; i++)
			{
				if (isspace(UserExt[i]))
				{
					for (int j = i; j < sizeExt; j++)
					{
						UserExt[j] = UserExt[j + 1];
					}
				}
			}
			*ext = UserExt;
			//std::cout << UserExt << std::endl;
			system("CLS");
			break;


		}

}

std::string Write2File(std::string *ptr) {
	std::string textmem;

	getline(std::cin, textmem);
	*ptr += textmem + "\n";

	
	return *ptr;
}

 

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	//setlocale(LC_ALL, "");
	std::string filename;
	std::string extension;
	std::string fullName;
	std::string textBank;
	std::size_t found;
	std::string end_command = "-s";
	

	std::cout << "Эта программа простой текстовый генератор" << std::endl;
	std::cout << "Итоговый файл будет располагаться в одной папке с этой программой" << std::endl << std::endl;
	std::cout << "Для продолжения нажмите enter..." << std::endl;
	getchar();
	system("CLS");
	std::cout << "Terms of use aka Pravila ispolzovania:" << std::endl;
	std::cout << "- Не использовать кириллицу при написании " << std::endl << std::endl;
	//std::cout << "- Когда программа просит ввести цифру ввести цифру, а не символ"<< std::endl << std::endl;
	std::cout << "Для продолжения нажмите enter... ";
	getchar();
	system("CLS");


	GetName(&filename);
	GetExt(&extension);
	fullName = filename += "." + extension;

	std::cout << "Полноё имя твоего файла: " << fullName << std::endl;
	std::cout << "Для продолжения нажмите enter... ";
	getchar();
	getchar();
	system("CLS");
	std::cout << "Введите текстовое содержимое файла \n" << "(для сохранения файла введите команду \"-s\") " << std::endl;
	
	while (textBank.find(end_command) == std::string::npos) {
		std::ofstream MyFile(fullName);
		MyFile << Write2File(&textBank);
		//textPtr = textmem;
		MyFile.close();
	}

	textBank.erase(textBank.size() - end_command.size() - 1, textBank.size() + end_command.size());
	std::ofstream MyFile(fullName);
	MyFile << textBank;
	MyFile.close();


	system("CLS");
	std::cout << "Содержимое вашего файла " << std::endl << textBank << std::endl << std::endl;
	std::cout << "Для выхода нажмите enter..." << std::endl;
	getchar();
	
}