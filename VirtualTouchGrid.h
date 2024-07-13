#ifndef VIRTUALTOUCHGRID_H
#define VIRTUALTOUCHGRID_H

#include <vector>

struct VTG_axis_long
{
    long value;
    long min;
    long max;
};

struct VTG_touch_long
{
    VTG_axis_long x;
    VTG_axis_long y;
    VTG_axis_long z;
};

struct VTG_axis_float
{
    float value;
    float min;
    float max;
};

struct VTG_touch_float
{
    VTG_axis_float x;
    VTG_axis_float y;
    VTG_axis_float z;

};

enum typeForm
{
    form_long,
    form_float,
    form_all
};


struct VTG_touch
{
    VTG_touch_float formatFloat;
    VTG_touch_long formatLong;
    typeForm form;
    int index;
    bool isTouch;
};

typedef VTG_touch (*set_VTG_touch)();


class VirtualTouchGrid {
public:
    VirtualTouchGrid(VTG_touch notTouch);

    void add(set_VTG_touch touchIn);

    VTG_touch get();

    VTG_touch notTouch;

    std::vector<set_VTG_touch> listTouch;

    ~VirtualTouchGrid();

private:
    VTG_axis_long tranferLong(VTG_axis_float);
    VTG_axis_float tranferFloat(VTG_axis_long);
    
    VTG_touch get_();
    
    void mapLong(VTG_axis_long&,VTG_axis_long&);
    void mapFloat(VTG_axis_float&,VTG_axis_float&);

    void _mapLongLong(VTG_touch&, VTG_touch&);
    void _mapFloatFloat(VTG_touch&, VTG_touch&);
    void _mapLongFloat(VTG_touch&, VTG_touch&);
    void _mapFloatLong(VTG_touch&, VTG_touch&);

};

#endif // VIRTUALTOUCHGRID_H
