#include <iostream>
#include "DateTime.hpp"

using namespace std;

int main() {
    DateTime dt1(2024, 5, 12, 15, 30, 45);
    DateTime dt2(2023, 12, 1, 10, 20, 30);
    
    dt1.print(); // print initial DateTime
    cout<<dt1.format("Today is YYYY-MM-DD, and the time is HH:MM")<<endl;

    cout<<"Difference in days: "<<dt1.differenceInDays(dt2)<<endl;
    cout<<"Difference in hours: "<<dt1.differenceInHours(dt2)<<endl;

    dt1.addDays(10);
    dt1.print();
    
    return 0;
}
