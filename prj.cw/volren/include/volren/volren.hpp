
#ifndef VOLUME_RENDER_HPP
#define VOLUME_RENDER_HPP

#include <string>
#include <GL/freeglut.h>



void render();
void resize(int width, int height);
void keyboard(unsigned char key, int x, int y);
void mouseDrag(int x, int y);
void mouseClick(int button, int state, int x, int y);

bool initTexturesRaw(std::string filename);

void map3DTexture(float textureIndex, int option = 0);

class TransformationManager
{
public:
	TransformationManager(void);
	virtual ~TransformationManager(void);
	const double* GetMatrix()
	{
		return mdRotation;
	}

	// Call these only after the OpenGL is initialized.
	void Rotate(float fx_i, float fy_i, float fz_i);
	void ResetRotation();

private:

	float mfRot[3];
	double mdRotation[16];
};

#endif