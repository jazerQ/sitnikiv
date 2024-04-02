#pragma once
#include "stdafx.h"
#include <vector>

class IfaceKurs
{
public:
virtual ~IfaceKurs();
virtual int GetVecPt(std::vector<CPoint> &vec) const = 0;
};

