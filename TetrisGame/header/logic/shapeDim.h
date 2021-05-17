#ifndef SHAPEDIM_H
#define SHAPEDIM_H



struct Point_C
{
    Point_C(int x);
    Point_C(){};
    float x;
    float y;
private:
    float z;
};

struct SquareCorners_C
{
    Point_C corner1;
    Point_C corner2;
    Point_C corner3;
    Point_C corner4;

};

struct Square_C
{
    Square_C(){};
    Square_C(float length, float width)
        :length(length), width(width) {};

    float length;
    float width;
};

struct RGBColor_C
{
    RGBColor_C(){};
    RGBColor_C(float red, float green, float blue)
        :red(red), green(green), blue(blue) {};

    float red;
    float green;
    float blue;
};


#endif // SHAPEDIM_H
