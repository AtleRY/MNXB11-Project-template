#include <iostream>
#include <fstream>
#include "include/csv.hpp"
#include <vector>
#include <string>
#include "TH2D.h"
#include "TCanvas.h"
using namespace csv;

int main() {
const std::string csvFilePath = "./datasets/Cleaned-Lund-data.csv";
std::ifstream inputFile(csvFilePath);

if (!inputFile.is_open()) {
std::cerr << "Error opening file!" << std::endl;
return 1;
}

CSVFormat format;
format.delimiter({';'}).no_header();
CSVReader reader(inputFile, format);

// Vectors to store parsed information so that we don't need a ttree
std::vector<int> years;
std::vector<int> months;
std::vector<int> days;
std::vector<int> hours;
std::vector<double> temperatures;
std::vector<char> grades;

CSVRow row;
// loop for getting the data from the csv file and putting it in its own vector
for (auto& row : reader) {
std::string date = row[0].get<std::string>();
int year = std::stoi(date.substr(0, 4));
int month = std::stoi(date.substr(5, 2));
int day = std::stoi(date.substr(8, 2));

std::string tim = row[1].get<std::string>();
int hour = std::stoi(tim.substr(0, 2));

std::string temperature = row[2].get<std::string>();
double temp = std::stod(temperature);

std::string grading = row[3].get<std::string>();
char grade = grading.empty() ? '\0' : grading[0];

// Store values in said vectors
years.push_back(year);
months.push_back(month);
days.push_back(day);
hours.push_back(hour);
temperatures.push_back(temp);
grades.push_back(grade);
}

// Close the CSV file
inputFile.close();



// Creating the histogram
int nBinsX = 250;
int nBinsY = 250;
double minX = *std::min_element(years.begin(), years.end());
double maxX = *std::max_element(years.begin(), years.end());
double minY = *std::min_element(temperatures.begin(), temperatures.end());
double maxY = *std::max_element(temperatures.begin(), temperatures.end());

TH2D* hist = new TH2D("hist", "Year vs Temperature", nBinsX, minX, maxX, nBinsY, minY, maxY);

for (size_t i = 0; i < years.size(); ++i) {
hist->Fill(years[i], temperatures[i]);
}

// Drawing the histogram
TCanvas* canvas = new TCanvas("canvas", "Canvas", 800, 600);
hist->Draw("colz");

// Save the canvas as an image (optional)
canvas->SaveAs("histogram.png");

// Run the ROOT event loop
canvas->Show();
canvas->Update();

return 0;
}