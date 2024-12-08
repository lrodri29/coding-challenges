#include <stdio.h>
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>

const int num_entries = 1000;

int main() {
    
    int safe_reports = 0;
    int unsafe_reports = 0;

    std::ifstream inputFile("day-2-in");
    if (!inputFile) {
        std::cerr << "Error: Unable to open the file." << std::endl;
        return 1;
    }
    
    std::string line; 
    int line_number = 1;

    while(std::getline(inputFile, line)) {
        std::istringstream lineStream(line);
        
        // Reading the numbers and putting them in our vector 
        int num;
        int last_num;
        bool first_num = true;
        bool safe_report = true;
        bool decreasing = false;
        bool increasing = false;

        // each number in the string will be extracted into our int num
        while (lineStream >> num) {
            if (first_num) {
                last_num = num;
                first_num = false;
            }
            else {
                if (safe_report) {
                    int diff_num = std::abs(num - last_num);
                    // If last num is > num then we expect them all to decrease from now on
                    if (!increasing && !decreasing){
                        if (last_num > num) {
                                decreasing = true;
                                increasing = false;
                        }
                        else {
                            decreasing = false;
                            increasing = true;
                        }
                    } 
                    // If we already determined this is increasing, make sure 
                    // the condition is not violated
                    else if (increasing) {
                        if (last_num > num) {
                            safe_report = false;
                            unsafe_reports++;
                            break;
                        }
                    }
                    // otherwise, make sure that if decreasing, we don't find an entry
                    // that says otherwise
                    else {
                        if (last_num < num) {
                            safe_report = false;
                            unsafe_reports++;
                            break;
                        }
                    }

                    // Check for the difference condition
                    // number can't be less than or equal to 0 or greater than 3 from each other
                    if (diff_num <= 3 && diff_num > 0) {
                        last_num = num;
                        continue;
                    }
                    else {
                        safe_report = false;
                        unsafe_reports++;
                        break;
                    }
                }
                
            }
        }

        // If by this point we didn't exit as unsafe, then check to make sure we are still safe and 
        // increment count if so
        if (safe_report) {
            safe_reports++;
            printf("Report on line (%d) is safe (total = %d)\n", line_number, safe_reports);
        }
        // increment line number just to keep track of lines outputted
        line_number++;
    }

    printf("Analysis complete, safe reports: %d, unsafe: %d\n", safe_reports, unsafe_reports);
}