#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>
#include <cstdlib>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::validDate(const std::string& date) const {
    if (date.length() != 10)
        return false;
    for (int i = 0; i < 10; ++i) {
        if (i == 4 || i == 7) {
            if (date[i] != '-')
                return false;
        } else {
            if (!isdigit(date[i]))
                return false;
        }
    }
    int m = atoi(date.substr(5, 2).c_str());
    int d = atoi(date.substr(8, 2).c_str());
    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
            continue;
        double value = atof(valueStr.c_str());
        _data[date] = value;
    }
}

void BitcoinExchange::processInput(const std::string& inputFile) const {
    std::ifstream file(inputFile.c_str());
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line); 
    while (std::getline(file, line)) {
        std::string raw = line;
        while (!raw.empty() && isspace(raw[0])) raw.erase(0, 1);
        while (!raw.empty() && isspace(raw[raw.size()-1])) raw.erase(raw.size()-1, 1);
        if (raw.empty()) continue;

        size_t sep = raw.find('|');
        if (sep == std::string::npos) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        std::string date = raw.substr(0, sep);
        std::string valueStr = raw.substr(sep + 1);
        while (!date.empty() && isspace(date[date.size()-1])) date.erase(date.size()-1, 1);
        while (!date.empty() && isspace(date[0])) date.erase(0, 1);
        while (!valueStr.empty() && isspace(valueStr[0])) valueStr.erase(0, 1);
        while (!valueStr.empty() && isspace(valueStr[valueStr.size()-1])) valueStr.erase(valueStr.size()-1, 1);

        if (!validDate(date)) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (valueStr.empty()) {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        char* endptr;
        double value = strtod(valueStr.c_str(), &endptr);
        if (*endptr != '\0') {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (value < 0) {
            std::cerr << "Error: not a positive number." << std::endl;
            continue;
        }
        if (value > 1000) {
            std::cerr << "Error: too large a number." << std::endl;
            continue;
        }
        std::map<std::string, double>::const_iterator it = _data.lower_bound(date);
        if (it == _data.begin() && (it == _data.end() || it->first > date)) {
            std::cerr << "Error: no earlier date available for " << date << std::endl;
            continue;
        }
        if (it == _data.end() || it->first > date)
            --it;
        double rate = it->second;
        double result = value * rate;
        std::cout << date << " => " << value << " = " << result << std::endl;
    }
}