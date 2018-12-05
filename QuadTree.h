#ifndef QUADTREE_H
#define QUADTREE_H
//---------------------QUADTREE CLASS------------------//


class QuadTree
{

public:
QuadTree(Node * root, int Threshold, int MaxDepth)
        :root_(root), Threshold_(Threshold), MaxDepth_(MaxDepth)
    {}
    ~QuadTree()
    {
        delete root_;
    }
    
    void insert(GameObject);
public:
    Node * root_;
    int Threshold_;
    int MaxDepth_;
    
};


#endif
