
#include <iostream>
#include "csv.hpp"

using namespace csv;

const std::string csvFilePath = "./datasets/Cleaned-Lund-data.csv";
int main() {
  std::ifstream inputFile(csvFilePath);
  
  CSVReader reader(inputFile);

double sum = 0;
 
CSVRow row;
 
for (auto& row: reader) {
    // Note: Can also use index of column with [] operator
    sum += row[0].get<double>();
    std::cout << sum << std::endl;
}
  
  return 0;
}
