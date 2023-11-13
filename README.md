For this program you will need this csv parser "https://github.com/vincentlaucsb/csv-parser"
To install you simply clone the csdv-parser library to your directory and copy the header.
The library is contained in a single header file named "csv-parser.hpp" in the lib repository and located in the single-include directory.
The process should look something like this:

git clone https://github.com/vincentlaucsb/csv-parser.git

cp csv-parser/single-include/csv-parser.hpp /MNXB11-Project-template/include

To run the program you will first have to enter the apptainer from the MNXB11-Project-template directory
with the command specified in the manual in canvas.
To compile the file you will have to use this specified command:

g++ -o Makefile main.cxx $(root-config --cflags --libs)

and then:

./Makefile

To produce a .png in the MNXB11-Project-template with the histogram.
