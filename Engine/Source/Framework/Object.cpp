#include "Object.h"

void Read(const json_t& value)
{ 
	READ_DATA(value, name); 
	READ_DATA(value, active);
}

void Write(json_t& value)
{
}
