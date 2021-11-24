#pragma once
#include "Items.h"
#include <string>
#include "Utils.h"
#include "GraphicsController.h"

using namespace std;

class GameObject : public Items {
protected:
	int oldX, oldY;
	int x, y; // coordinate of top-left corner
	int w, h; // box size
public:
	GameObject() : oldX(0), oldY(0), x(0), y(0), w(0), h(0), Items() {}
	GameObject(int x, int y, int w, int h, string bufferKey) : Items(bufferKey), oldX(x), oldY(y), x(x), y(y), w(w), h(h) {}

	coord getPos();
	coord getOldPos();
	BOUNDINGBOX getBoundingBox();

	virtual void move(int x, int y) = 0;

	void render(GraphicsController*& graphic, int bgColor, int fgColor);

	void clearOldPos(GraphicsController*& graphic, int bgColor, int fgColor);

	virtual void resetPos(int lane, GraphicsController*& graphic, bool left = true);
};