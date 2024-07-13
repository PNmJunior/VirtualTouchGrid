#include "VirtualTouchGrid.h"

VirtualTouchGrid::VirtualTouchGrid(VTG_touch notTouch)
{
    this->notTouch = notTouch;
    this->notTouch.isTouch = false;
}

void VirtualTouchGrid::add(set_VTG_touch touchIn)
{
    listTouch.push_back(touchIn);
}

VTG_touch VirtualTouchGrid::get(VTG_touch out)
{
    VTG_touch in = get_();
    if (in.isTouch == false)
    {
        return notTouch;
    }
 
    mapFloat(out.x,in.x);
    mapFloat(out.y,in.y);
    mapFloat(out.z,in.z);

    out.isTouch = true;
    out.index = in.index;

    return out;
}

VTG_touch VirtualTouchGrid::get()
{
    return get(notTouch);
}

VirtualTouchGrid::~VirtualTouchGrid()
{
    listTouch.clear();
}

VTG_touch VirtualTouchGrid::get_()
{
    VTG_touch a;
    for(auto &touchOne: listTouch)
    {
        a = touchOne();
        if(a.isTouch)
        {
            return a;
        }
    }
    return notTouch;
}

void VirtualTouchGrid::mapFloat(VTG_axis_float & out, VTG_axis_float & in)
{
    out.value = (in.value - in.min)*((out.max-out.min)/(in.max-in.min))+out.min;
}
