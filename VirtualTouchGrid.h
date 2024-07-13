#ifndef VIRTUALTOUCHGRID_H
#define VIRTUALTOUCHGRID_H

#include <vector>


struct VTG_axis_float
{
    float value;
    float min;
    float max;
};

struct VTG_touch
{
    VTG_axis_float x;
    VTG_axis_float y;
    VTG_axis_float z;
    int index;
    bool isTouch;
};

typedef VTG_touch (*set_VTG_touch)();


class VirtualTouchGrid {
public:
    VirtualTouchGrid(VTG_touch notTouch);

    void add(set_VTG_touch touchIn);

    VTG_touch get(VTG_touch out);

    VTG_touch get();

    VTG_touch notTouch;

    std::vector<set_VTG_touch> listTouch;

    ~VirtualTouchGrid();

private:
    
    VTG_touch get_();
    
    void mapFloat(VTG_axis_float&,VTG_axis_float&);

};

#endif // VIRTUALTOUCHGRID_H
