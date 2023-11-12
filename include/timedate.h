#ifndef timedate_H
#define timedate_H
#include <cmath>
#include <stdexcept>

class timedate {
 public:
  timedate(int year, int month, int day, int hour, double temp);
  
  

 private:
  int year; 
  int month;
  int day; 
  int hour; 
  double temp; 
 
};


#endif /* timedate_H */