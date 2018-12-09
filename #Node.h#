#ifndef NODE_H
#define NODE_H

#include <vector>
#include "gameobject.h"
//#include <iostream>
//------------------------QUAD NODE CLASS---------------//
class Node
{
public:
Node(Point TopLeftPoint, Point BottomRightPoint, Node * parent, int level)
    :TopLeftPoint_(TopLeftPoint), BottomRightPoint_(BottomRightPoint), parent_(parent), level_(level)
    {
        
    TopLeftNode = NULL;
    TopRightNode = NULL;
    BottomLeftNode = NULL;
    BottomRightNode = NULL;
    parent_ = NULL;
    }
    
    bool HasChildren()
    {
        return (TopLeftNode != NULL);
    }

    bool InBound(GameObject *object)
    {

      
        return((object->get_x())+object->r_ <= BottomRightPoint_.x_
               && object->get_x()-object->r_ >= TopLeftPoint_.x_
               && object->get_y()-object->r_ >= TopLeftPoint_.y_
               && object->get_y()+object->r_ <= BottomRightPoint_.y_
            );
    }
    
    bool is_root() const
    {
        return (parent_ == NULL);
    }

    int NumOfObjects() const
    {
        return this->Objects.size();
    }
    
    
    const Node * const parent() const
    {
        return parent_;
    }
    
    int get_depth() const //depth
    {
        if(this->is_root())
        {
            return 0;
        }
        else
        {
            return (this->parent()->get_depth()+1);
        }
        
    }

    ~Node()
    {
        delete TopLeftNode;
        delete TopRightNode;
        delete BottomLeftNode;
        delete BottomRightNode;
    }
 
    
public:
    Point TopLeftPoint_;
    Point BottomRightPoint_;
    Node * parent_;
    Node * TopLeftNode;
    Node * TopRightNode;
    Node * BottomLeftNode;
    Node * BottomRightNode;
    int level_;
    std::vector<GameObject *> Objects;
    std::vector<GameObject *> RemainingObjects;
};



std::ostream & operator<<(std::ostream & cout, const Node &node)
{
    cout << "Node: " << &node /* << " " << "TopLeftPoint: " << node->TopLeftPoint_.x_ */
    /*      << " , " << node->TopLeftPoint_.y_ << '\n' */
    /*      << " BottomRightPoint:"  << node->BottomRightPoint_.x_ */
    /*      << " , " << node->BottomRightPoint_.y_ << '\n'; */
    /* for(int i = 0; i < node->Objects.size(); ++i) */
    /* { */
    /*     cout << *node->Objects[i] << ", "; */
    /* } */
    /* cout << */<< '\n';
    return cout;
}


//-----------------------------------------------------//
#endif
//num of children
//parent
//children
//objects
/* Node::~Node() */
/* { */
/*     delete this->TopLeftNode; */
/*     delete this->TopRightNode; */
/*     delete this->BottomLeftNode; */
/*     delete this->BottomRightNode; */
/* } */
   

