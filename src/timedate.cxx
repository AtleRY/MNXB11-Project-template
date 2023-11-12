timedate::timedate(int year, int month, int day, int hour, double temp) : year{year}, month{month}, day{day}, hour{hour}, temp{temp} { 
    // A check to see if the temp is too high or too low
        if (temp < -50 || temp > 50)  {
        throw std::invalid_argument("Temperature either to high or too low!");
        }}