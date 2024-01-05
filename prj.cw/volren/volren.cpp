#include <stdlib.h>
#include <GL/glew.h>
#include <GL/freeglut.h>

#include <stdio.h>


#include <iostream>
#include <fstream>
#include <sstream>

#include <volren/volren.hpp>
int IMAGEWIDTH = 256;
int IMAGEHEIGHT = 256;
int IMAGECOUNT = 128;

float EYE_X = 0;
float EYE_Y = -0.9;
float EYE_Z = -1.5;

int RESET_KEY = 8;

GLfloat dOrthoSize = 1.0f;
GLfloat dViewPortSize = 1.0f;
int mouseX;
int mouseY;
int textureID3D;

TransformationManager::TransformationManager(void)
{
	mdRotation[0] = mdRotation[5] = mdRotation[10] = mdRotation[15] = 1.0f;
	mdRotation[1] = mdRotation[2] = mdRotation[3] = mdRotation[4] = 0.0f;
	mdRotation[6] = mdRotation[7] = mdRotation[8] = mdRotation[9] = 0.0f;
	mdRotation[11] = mdRotation[12] = mdRotation[13] = mdRotation[14] = 0.0f;

	mfRot[0] = mfRot[1] = mfRot[2] = 0.0f;
}


TransformationManager::~TransformationManager(void)
{
}

// Only call after initialising OpenGL
void TransformationManager::Rotate(float fx_i, float fy_i, float fz_i)
{
	mfRot[0] = fx_i;
	mfRot[1] = fy_i;
	mfRot[2] = fz_i;

	glMatrixMode(GL_MODELVIEW);
	glLoadMatrixd(mdRotation);
	glRotated(mfRot[0], 1.0f, 0, 0);
	glRotated(mfRot[1], 0, 1.0f, 0);
	glRotated(mfRot[2], 0, 0, 1.0f);

	glGetDoublev(GL_MODELVIEW_MATRIX, mdRotation);
	glLoadIdentity();
}

// Only call after initialising OpenGL
void TransformationManager::ResetRotation()
{
	mdRotation[0] = mdRotation[5] = mdRotation[10] = mdRotation[15] = 1.0f;
	mdRotation[1] = mdRotation[2] = mdRotation[3] = mdRotation[4] = 0.0f;
	mdRotation[6] = mdRotation[7] = mdRotation[8] = mdRotation[9] = 0.0f;
	mdRotation[11] = mdRotation[12] = mdRotation[13] = mdRotation[14] = 0.0f;
}


TransformationManager transManager;
/*
Render image for display
*/
void render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA,
		GL_ONE_MINUS_SRC_ALPHA
	);

	glEnable(GL_ALPHA_TEST);
	glAlphaFunc(GL_GREATER, 0.2f);


	glMatrixMode(GL_TEXTURE);
	glLoadIdentity();

	// Translate and make 0.5f as the center 
	// (texture co ordinate is from 0 to 1.
	// so center of rotation has to be 0.5f)
	glTranslatef(0.5f, 0.5f, 0.5f);

	// A scaling applied to normalize the axis 
	// (Usually the number of slices will be less so if this is not - 
	// normalized then the z axis will look bulky)
	// Flipping of the y axis is done by giving a negative value in y axis.
	// This can be achieved either by changing the y co ordinates in -
	// texture mapping or by negative scaling of y axis

	glScaled((float)IMAGEWIDTH / (float)IMAGEWIDTH,
		1.0f * (float)IMAGEWIDTH / (float)(float)IMAGEHEIGHT,
		(float)IMAGEWIDTH / (float)IMAGECOUNT);

	// Apply the user provided transformations
	glMultMatrixd(transManager.GetMatrix());

	glTranslatef(-0.5f, -0.5f, -0.5f);

	glEnable(GL_TEXTURE_3D);
	glBindTexture(GL_TEXTURE_3D, textureID3D);


	for (float fIndx = -1.0f; fIndx <= 1.0f; fIndx += 0.006f)
	{
		glBegin(GL_QUADS);
		map3DTexture(fIndx);
		glEnd();
	}


	glutSwapBuffers();

}

/*
Resizes the viewer window whilst maintaining the aspect ratio
*/
void resize(int width, int height)
{
	GLdouble aspectRatio = (GLdouble)(width) / (GLdouble)(height);
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width <= height)
	{
		glOrtho(-dOrthoSize, dOrthoSize, -(dOrthoSize / aspectRatio),
			dOrthoSize / aspectRatio, 2.0f * -dOrthoSize, 2.0f * dOrthoSize);
	}
	else
	{
		glOrtho(-dOrthoSize * aspectRatio, dOrthoSize * aspectRatio,
			-dOrthoSize, dOrthoSize, 2.0f * -dOrthoSize, 2.0f * dOrthoSize);
	}

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

/*
Create 3D textures from images. All images are in one raw data file
*/
bool initTexturesRaw(std::string filename)
{

	float factor = 1.0f;
	float gradient = (1.0f - 0.5f) / (IMAGECOUNT - 1);

	FILE* file;
	file = fopen(filename.c_str(), "rb");

	if (file == NULL)
	{
		fprintf(stderr, "Could not open texture file\n");
		return false;
	}

	// Holds the luminance buffer
	char* chRGBABuffer = new char[IMAGEWIDTH * IMAGEHEIGHT * IMAGECOUNT * 4];
	char* chBuffer = new char[IMAGEHEIGHT * IMAGEWIDTH * IMAGECOUNT];

	//Only create 1 3D texture now
	glGenTextures(1, (GLuint*)&textureID3D);

	// Read each frames and construct the texture
	fread(chBuffer, sizeof(unsigned char), IMAGEHEIGHT * IMAGEWIDTH * IMAGECOUNT, file);

	// Set the properties of the texture.
	glBindTexture(GL_TEXTURE_3D, textureID3D);
	glTexEnvi(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_REPLACE);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_WRAP_R, GL_CLAMP_TO_BORDER);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_3D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	int count = 0;

	// Convert the data to RGBA data.
	// Here we are simply putting the same value to R, G, B and A channels.
	// This can be changed depending on the source data
	// Usually for raw data, the alpha value will
	// be constructed by a threshold value given by the user 
	for (int nIndx = 0; nIndx < IMAGEWIDTH * IMAGEHEIGHT * IMAGECOUNT; ++nIndx)
	{
		chRGBABuffer[nIndx * 4] = chBuffer[nIndx];
		chRGBABuffer[nIndx * 4 + 1] = chBuffer[nIndx];
		chRGBABuffer[nIndx * 4 + 2] = chBuffer[nIndx];
		chRGBABuffer[nIndx * 4 + 3] = (char)(chBuffer[nIndx] * factor);

		if ((nIndx % (IMAGEWIDTH * IMAGEHEIGHT) == 0) && nIndx != 0)
		{
			factor = factor - gradient;
		}
	}

	glTexImage3D(GL_TEXTURE_3D, 0, GL_RGBA, IMAGEWIDTH, IMAGEHEIGHT, IMAGECOUNT, 0,
		GL_RGBA, GL_UNSIGNED_BYTE, (GLvoid*)chRGBABuffer);
	glBindTexture(GL_TEXTURE_3D, 0);

	int err = glGetError();
	if (err > 0)
	{
		printf("Error %d\n", err);
	}
	fclose(file);

	delete[] chRGBABuffer;
	delete[] chBuffer;
	return true;
}


/*
Keyboard callback. Rotates image with W-A-S-D and resets with "backspace" (This can be changed)
*/
void keyboard(unsigned char key, int x, int y)
{
	if (key == 'w' || key == 'W') {
		transManager.Rotate(1.0f, 0, 0);
		glutPostRedisplay();
	}
	else if (key == 's' || key == 'S') {
		transManager.Rotate(-1.0f, 0, 0);
		glutPostRedisplay();
	}
	else if (key == 'a' || key == 'A') {
		transManager.Rotate(0, 1.0f, 0);
		glutPostRedisplay();
	}
	else if (key == 'd' || key == 'D') {
		transManager.Rotate(0, -1.0f, 0);
		glutPostRedisplay();
	}
	else if (key == RESET_KEY)
	{
		transManager.ResetRotation();
		glutPostRedisplay();
	}
}

/*
Mouse callback. Used to rotate via mouse
*/
void mouseDrag(int x, int y)
{
	if (((x - mouseX) != 0) || ((y - mouseY) != 0))
	{
		transManager.Rotate((float)(mouseY - y), (float)(mouseX - x), 0.0f);
		mouseX = x;
		mouseY = y;
		glutPostRedisplay();
	}
}

/*
Mouse callback occurs when mouse is clicked
*/
void mouseClick(int button, int state, int x, int y)
{
	mouseX = x;
	mouseY = y;
}

/*
Map 3D texture for display during rendering
*/
void map3DTexture(float textureIndex, int option)
{
	if (option == 0)
	{
		glTexCoord3f(0.0f, 0.0f, ((float)textureIndex + 1.0f) / 2.0f);
		glVertex3f(-dViewPortSize, -dViewPortSize, textureIndex);  // bottom left corner + z index
		glTexCoord3f(1.0f, 0.0f, ((float)textureIndex + 1.0f) / 2.0f);
		glVertex3f(dViewPortSize, -dViewPortSize, textureIndex); // top left corner + z index
		glTexCoord3f(1.0f, 1.0f, ((float)textureIndex + 1.0f) / 2.0f);
		glVertex3f(dViewPortSize, dViewPortSize, textureIndex);  // top right corner + z index
		glTexCoord3f(0.0f, 1.0f, ((float)textureIndex + 1.0f) / 2.0f);
		glVertex3f(-dViewPortSize, dViewPortSize, textureIndex); // bottom right corner + z index
	}
	else if (option == 2)
	{
		glTexCoord3f(0.0f, 0.0f, ((float)textureIndex + 1.0f) / 2.0f);
		glVertex3f(textureIndex, -dViewPortSize, -dViewPortSize);  // bottom left corner + z index
		glTexCoord3f(1.0f, 0.0f, ((float)textureIndex + 1.0f) / 2.0f);
		glVertex3f(textureIndex, -dViewPortSize, dViewPortSize); // top left corner + z index
		glTexCoord3f(1.0f, 1.0f, ((float)textureIndex + 1.0f) / 2.0f);
		glVertex3f(textureIndex, dViewPortSize, dViewPortSize);  // top right corner + z index
		glTexCoord3f(0.0f, 1.0f, ((float)textureIndex + 1.0f) / 2.0f);
		glVertex3f(textureIndex, dViewPortSize, -dViewPortSize); // bottom right corner + z index
	}
}

//VolumeRender::VolumeRender(int img_w, int img_h, int img_c)
//{
//	IMAGEWIDTH = img_w;
//	IMAGEHEIGHT = img_h;
//	IMAGECOUNT = img_c;
//}
//
//int VolumeRender::getWidth()
//{
//	return this->IMAGEWIDTH;
//}
//
//int VolumeRender::getHeight()
//{
//	return this->IMAGEHEIGHT;
//}
//
//int VolumeRender::getCount()
//{
//	return this->IMAGECOUNT;
//}