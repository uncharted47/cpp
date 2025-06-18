#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <string>
#include <map>

class BitcoinExchange {
public:
    BitcoinExchange();
    ~BitcoinExchange();
    void loadDatabase(const std::string& dbFile);
    void processInput(const std::string& inputFile) const;
private:
    std::map<std::string, double> _data;
    bool validDate(const std::string& date) const;
};

#endif