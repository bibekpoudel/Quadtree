#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

//#include "Point.h"


class GameObject
{
public:
GameObject(int x, int y, int r,  int  vspeed, int  hspeed, int R, int G, int B, Surface & surface)
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

    void change_speed()
    {
        vspeed_ = -vspeed_;
        hspeed_ = -hspeed_;
    }

    void change_color()
    {
        R_ = 0;
        G_ = 0;
        B_ = 255;
    }
    
    double get_x()
    {
        return x_;
    }

    

    double get_y()
    {
        return y_;
    }
    void draw()
    {
        surface_.put_circle(x_, y_, r_, R_, G_, B_);
    }
    
public:
    int x_,y_,r_, vspeed_, hspeed_;
    int R_,G_,B_;
    Surface & surface_;
    bool alive;
    
};


std::ostream & operator<<(std::ostream & cout, const GameObject & object)
{
    cout << "x: " << object.x_ << " y:" << object.y_ << '\n';
    return cout;
}


#endif
