#ifndef SHAPEDIM_H
#define SHAPEDIM_H



struct point
{
    point(int x);
    point(){};
    float x;
    float y;
private:
    float z;
};

struct squareCorners
{
    point corner1;
    point corner2;
    point corner3;
    point corner4;

};

struct square
{
    square(){};
    square(float length, float width)
        :length(length), width(width) {};

    float length;
    float width;
};

struct RGBColor
{
    RGBColor(){};
    RGBColor(float red, float green, float blue)
        :red(red), green(green), blue(blue) {};

    float red;
    float green;
    float blue;
};

class test;

#endif // SHAPEDIM_H
