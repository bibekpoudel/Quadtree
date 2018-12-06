#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//#include "Point.h"


class GameObject
{
public:
GameObject(double x, double y, double r,  double vspeed, double hspeed, int R, int G, int B, Surface & surface)
    : x_(x), y_(y),r_(r),vspeed_(vspeed), hspeed_(hspeed), R_(R), G_(G), B_(B), surface_(surface)
    {
        alive = 1;
    }

    void move()
    {
        y_ += vspeed_;
        x_ += hspeed_;

        if (y_ >= H || y_ <= 0)
        {
            vspeed_ = -vspeed_;
        }
        if (x_ >= W || x_<= 0)
        {
            hspeed_ = -hspeed_;
        }
    }

    void change_color()
    {
        R_ = 0;
        G_ = 0;
        B_ = 255;
    }
    
    int get_x()
    {
        return x_;
    }

    int get_y()
    {
        return y_;
    }
    void draw()
    {
        surface_.put_circle(x_, y_, r_,R_, G_, B_);
    }
    
public:
    double x_,y_,r_, vspeed_, hspeed_;
    int R_,G_,B_;
    Surface & surface_;
    bool alive;
    
};



/* class GameObject */
/* { */
/* public: */
/* GameObject(Point Coordinates, Surface & surface) */
/*     :Coordinates_(Coordinates), surface_(surface) */
/*     { */
/*         body_rect.x=Coordinates_.x_; */
/*         body_rect.y=Coordinates_.y_; */
        
/*     } */
/*     void draw() */
/*     { */
/*         surface_.put_rect(Coordinaes_.x_, Coordinates_.y_, w_, h_, R_, G_, B_); */
/*     } */
    
/* private: */
/*     Point Coordinates_; */
/*     Rect body_rect; */
/*     Surface surface_; */
    
/* }; */


#endif
