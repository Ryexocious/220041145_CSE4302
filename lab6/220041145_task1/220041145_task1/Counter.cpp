#include "Counter.h"
void Counter::setincrementstep(int x) {
    if (count == 0) {
        if (x > 0) {
            increamentstep = x;
        }
        else {
            cout << "invalid"<<"\n";
            increamentstep = 1;
            
        }
    }
    else {
        cout << "invalid" << "\n";
        increamentstep = 1;
    }
}
int Counter::getcount() const {
    return count;
}

void Counter::increment() {
    add(increamentstep);
}

void Counter::reset(int step = 1) {
    count = 0;
    increamentstep =  step> 0 ? step : 1;
}
Counter Counter::operator+(const Counter& other) const {
    Counter result;
    if (this->increamentstep == other.increamentstep) {
        result.add(this->count + other.count);
        result.increamentstep = this->increamentstep;
    }
    else {
        cout << "not same" << endl;
    }
    return result;
}
Counter Counter::operator+=(const Counter& other) {
    this->add(other.count);
    this->increamentstep = max(this->increamentstep, other.increamentstep);
    return *this;
}

Counter Counter::operator++(int) {
    Counter temp = *this; 
    this->increment();    
    return temp;          
}


Counter Counter::operator++() {
    this->increment();
    return *this;
}

bool Counter::operator>(const Counter & other) const {
    return this->count > other.count;
}

bool Counter::operator<(const Counter& other) const {
    return this->count < other.count;
}

bool Counter::operator>=(const Counter& other) const {
    return this->count >= other.count;
}

bool Counter::operator<=(const Counter& other) const {
    return this->count <= other.count;
}

bool Counter::operator==(const Counter& other) const {
    return this->count == other.count;
}

bool Counter::operator!=(const Counter& other) const {
    return this->count != other.count;
}