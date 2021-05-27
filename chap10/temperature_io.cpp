#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <string>

int main() {
    try {
        struct Reading {
            int hour;
            double temp;
        };
        std::vector<Reading> readings;
        
        std::string iname = "temps_data.txt";
        std::ifstream ist {iname};
        if(!ist) throw std::runtime_error("Could not open file " + iname);

        int hour;
        double temp;
        
        while(ist >> hour >> temp) {
            if(hour < 0 || hour > 23) std::cout << "Ignored invalid hour " << hour << "\n";
            else readings.push_back(Reading {hour, temp});
        }
        
        std::string oname = "temps_output.txt";
        std::ofstream ost {oname};
        if(!ost) throw std::runtime_error("Could not open file " + oname);
        
        for(Reading r : readings) ost << "(" << r.hour << ", " << r.temp << ")\n";
    } catch(std::runtime_error& e) {
        std::cout << e.what();
    }
}