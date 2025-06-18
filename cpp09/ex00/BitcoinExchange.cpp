#include "BitcoinExchange.hpp"
#include <fstream>
#include <sstream>
#include <iostream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::~BitcoinExchange() {}

bool BitcoinExchange::validDate(const std::string& date) const {
    int y, m, d;
    char sep1, sep2;
    std::istringstream ss(date);
    if (!(ss >> y >> sep1 >> m >> sep2 >> d) || sep1 != '-' || sep2 != '-')
        return false;
    if (m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    return true;
}

void BitcoinExchange::loadDatabase(const std::string& dbFile) {
    std::ifstream file(dbFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open database file." << std::endl;
        exit(EXIT_FAILURE);
    }
    std::string line;
    std::getline(file, line); // skip header
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, valueStr;
        if (!std::getline(ss, date, ',') || !std::getline(ss, valueStr))
            continue;
        double value = std::atof(valueStr.c_str());
        _data[date] = value;
    }
}

void BitcoinExchange::processInput(const std::string& inputFile) const {
    std::ifstream file(inputFile);
    if (!file.is_open()) {
        std::cerr << "Error: could not open file." << std::endl;
        return;
    }
    std::string line;
    std::getline(file, line); // header or first line
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string date, sep, valueStr;
        if (!(ss >> date >> sep >> valueStr) || sep != "|") {
            std::cerr << "Error: bad input => " << line << std::endl;
            continue;
        }
        if (!validDate(date)) {
            std::cerr << "Error: bad input => " << date << std::endl;
            continue;
        }
        double value;
        try {
            value = std::stod(valueStr);
        } catch (...) {
            std::cerr << "Error: bad input => " << valueStr << std::endl;
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
        auto it = _data.lower_bound(date);
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