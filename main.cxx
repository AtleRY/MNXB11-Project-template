
#include <iostream>
#include "csv.hpp"

using namespace csv;



int main() {
  CSVReader reader("Cleaned-Lund-data.csv");

double sum = 0;

CSVRow row;
 
for (auto& row: reader) {
    // Note: Can also use index of column with [] operator
    sum += row["1"].get<double>();
    std::cout << sum << std::endl;
}
  
  return 0;
}
