#ifndef API_GAMEPLAY_WOODS_MAN_H
#define API_GAMEPLAY_WOODS_MAN_H

#include "Walker.h"

class Woodsman : public Walker
{

public:
	Woodsman(float x, float y, float linear_speed);
	void DefineTexture() override;
	
};

#endif // WOODS_MAN_H
