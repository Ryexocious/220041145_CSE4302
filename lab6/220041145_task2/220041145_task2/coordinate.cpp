#include "coordinate.h"
void coordinate::display() {
	cout << "(abscissa,ordinate) (" << abscissa << "," << ordinate << ")\n";
}
float coordinate::operator-(coordinate c) {
	return sqrt(pow((c.abscissa - this->abscissa) + (c.ordinate - this->ordinate), 2));
}
float coordinate::getdistance() {
	return sqrt(pow(abscissa, 2) + pow(ordinate, 2));
}
void coordinate::move_x(float val) {
	abscissa += val;
}
void coordinate::move_y(float val) {
	ordinate += val;
}
void coordinate::move(float x_val, float y_val) {
	abscissa += x_val;
	ordinate += y_val;
}