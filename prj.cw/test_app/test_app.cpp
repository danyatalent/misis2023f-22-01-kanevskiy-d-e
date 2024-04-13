#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <volren/volren.hpp>


int main(int argc, char* argv[])
{
	std::string path;
	if (argc < 2) {
		fprintf(stdout, "Failed to initialise textures\nCheck DATAFILE path");
		return 1;
	}
	else {
		path = argv[1];
	}

	
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(512, 512);

	glutCreateWindow("volren");
	glutPositionWindow(256, 256);

	volRen::setSize(atoi(argv[2]), atoi(argv[3]), atoi(argv[3]));
	

	glutDisplayFunc(&volRen::render);
	glutReshapeFunc(&volRen::resize);
	glutKeyboardFunc(&volRen::keyboard);
	glutMotionFunc(&volRen::mouseDrag);
	glutMouseFunc(&volRen::mouseClick);

	//glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glewInit();

	bool loadSuccess = false;
	loadSuccess = volRen::initTexturesRaw(path);

	if (!loadSuccess)
	{
		fprintf(stderr, "Failed to initialise textures\nCheck DATAFILE path");
		return 1;
	}

	glutMainLoop();
	fprintf(stdout, "Window closed\n");
	return 0;
}
