#include "VirtualTouchGrid.h"

void VirtualTouchGrid::add(set_VTG_touch touchIn)
{
    listTouch.push_back(touchIn);
}

VTG_touch VirtualTouchGrid::get()
{
    VTG_touch in = get_();
    if (in.isTouch == notTouch.isTouch)
    {
        return notTouch;
    }
    
    VTG_touch out = notTouch;
    if(in.form == form_float)
    {
        in.formatLong.x = tranferLong(in.formatFloat.x);
        in.formatLong.y = tranferLong(in.formatFloat.y);
        in.formatLong.z = tranferLong(in.formatFloat.z);
    }
    else if(in.form == form_long)
    {
        in.formatFloat.x = tranferFloat(in.formatLong.x);
        in.formatFloat.y = tranferFloat(in.formatLong.y);
        in.formatFloat.z = tranferFloat(in.formatLong.z);
    }
    mapLong(out.formatLong.x,in.formatLong.x);
    mapLong(out.formatLong.y,in.formatLong.y);
    mapLong(out.formatLong.z,in.formatLong.z);
    mapFloat(out.formatFloat.x,in.formatFloat.x);
    mapFloat(out.formatFloat.y,in.formatFloat.y);
    mapFloat(out.formatFloat.z,in.formatFloat.z);

    out.isTouch = true;
    out.index = in.index;
    

}

VTG_axis_long VirtualTouchGrid::tranferLong(VTG_axis_float in)
{
    VTG_axis_long out;
     out.max = in.max;
   out.min = in.min;
    out.value = in.value;
    return out;
}

VTG_axis_float VirtualTouchGrid::tranferFloat(VTG_axis_long in)
{
    VTG_axis_float out;
    out.max = in.max;
    out.min = in.min;
    out.value = in.value;
    return out;
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

void VirtualTouchGrid::mapLong(VTG_axis_long & out, VTG_axis_long & in)
{
    out.value = (in.value - in.min)*((out.max-out.min)/(in.max-in.min))+out.min;
}

void VirtualTouchGrid::mapFloat(VTG_axis_float & out, VTG_axis_float & in)
{
    out.value = (in.value - in.min)*((out.max-out.min)/(in.max-in.min))+out.min;
}
