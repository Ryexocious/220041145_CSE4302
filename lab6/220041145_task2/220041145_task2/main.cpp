#include"coordinate.h"
bool operator>(coordinate x, coordinate y) {
	return x.getdistance() > y.getdistance();
}
bool operator<(coordinate x, coordinate y) {
	return x.getdistance() < y.getdistance();
}
bool operator>=(coordinate x, coordinate y) {
	return x.getdistance() >= y.getdistance();
}
bool operator<=(coordinate x, coordinate y) {
	return x.getdistance() <= y.getdistance();
}
bool operator==(coordinate x, coordinate y) {
	return x.getdistance()== y.getdistance();
}
bool operator!=(coordinate x, coordinate y) {
	return x.getdistance() != y.getdistance();
}
void randomAssignment(coordinate c[], int size) {
	for (int i = 0; i < size; i++) {
		float x = static_cast<float>((rand() %500)/1.00);
		float y = static_cast<float>((rand() % 500) / 1.00);
		c[i] = coordinate(x, y);
	}
}
bool comparator(coordinate x, coordinate y) {
	return x.getdistance() <= y.getdistance();
}
void sort(coordinate c[], int size) {
	sort(c, c + size,comparator);
}

void highest(coordinate c[],int size) {
	sort(c, size);
	c[size - 1].display();
}
void lowest(coordinate c[], int size) {
	sort(c, size);
	c[0].display();
}
int main() {
	coordinate c[10];
	randomAssignment(c, 10);
	highest(c, 10);
	lowest(c, 10);

}