
#include <iostream>
#include "csv.hpp"

using namespace csv;
int year;
int month;
int day;
int hour;
int temp;
char grade;
const std::string csvFilePath = "./datasets/Cleaned-Lund-data.csv";

int main() {
  std::ifstream inputFile(csvFilePath);
  //std::vector<std::string> col_names = {"Date", "time", "Temp", "Grade"};
CSVFormat format;
//format.column_names(1, 2, 3, 4, 5);
format.delimiter({'-'})
      .no_header()
      .quote(';');
CSVReader reader(inputFile, format);

 
CSVRow row;

 
for (auto& row: reader) {
  
    if (row[0].is_int()){
      year = row[0].get<int>();
      //std::cout << "date" << std::endl;
    }
    //kan markera detta som komentar month funkar inte, year gör dock
    //if ( row[1].is_int()){
      //month = row[1].get<int>();
    //}
    std::cout << year << month << std::endl;
    
}
  
  return 0;
}
