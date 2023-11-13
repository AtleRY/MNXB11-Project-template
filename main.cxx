#include <string.h>
#include <iostream>
#include "include/csv.hpp"

using namespace csv;
int year;
int month;
int day;
int hour;
double temp;
char grade;
std::string date;
std::string temperature;
std::string tim;
std::string grading;
const std::string csvFilePath = "./datasets/Cleaned-Lund-data.csv";

int main() {
  std::ifstream inputFile(csvFilePath);
  //std::vector<std::string> col_names = {"Date", "tim", "Temp", "Grade"};
CSVFormat format;
//format.column_names(1, 2, 3, 4, 5);
format.delimiter({';'})
      .no_header();
      
CSVReader reader(inputFile, format);

 
CSVRow row;

 
for (auto& row: reader) {
  
    
      date = row[0].get<std::string>();
    year=std::stoi(date.substr(0,4));
    month=std::stoi(date.substr(5,2));
    day=std::stoi(date.substr(8,2));
    
    
    tim = row[1].get<std::string>();
     hour=std::stoi(tim.substr(0,2));
      // Någon av er kan klura på hur man ska göra för att få ut timmen :)
      
   
    temperature = row[2].get<std::string>();
    temp = std::stod(temperature);
    
    grading = row[3].get<std::string>();
    
    std::cout << year << ", " << month << ", " << day << ", " << hour << ", " << temp << ", " << grading << std::endl;
    
}
  
  return 0;
}