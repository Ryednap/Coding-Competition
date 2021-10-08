#ifndef BOX_H
#define BOX_H

class Box {
private:
     int length;
     int width;
     int height;

public:
    Box () = default;
    Box (int l, int w, int h);
    double Volume ( ) ;

};
