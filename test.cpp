#include <iostream>

class Point
{
    // use default constructor
public:
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }
    int getX() const { return x; }
    int getY() const { return y; }
private:
    int x;
    int y;
};

class Line 
{
public:
    Line(Point start, Point end);
    ~Line();
    void printLine() const;
private:
    Point start;
    Point end;
};

Line::Line(Point p1, Point p2){
    start.setX( p1.getX());
    start.setY( p1.getY());
    end.setX( p2.getX());
    end.setY( p2.getY());
}

Line::~Line(){

}

void Line::printLine() const{
    std::cout << start.getX() << start.getY() << end.getX() << end.getY() << "\n";
}

int main()
{
    Point p1, p2;

    p1.setX(1);
    p1.setY(2);
    p2.setX(3);
    p2.setY(4);
    Line l(p1, p2);
    l.printLine();

    Line &rL = l;
    rL.printLine();
    return 0;
}
