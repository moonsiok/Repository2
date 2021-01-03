#pragma once

template <typename T>
void proverka2(T& input, std::string inputText)
{
	std::cout << inputText;
	while ((std::cin >> input).fail() || input < 0) {
		std::cout << "Incorrect value. Try again\n";
		std::cin.clear();
		std::cin.ignore(10000, '\n');
	}
}