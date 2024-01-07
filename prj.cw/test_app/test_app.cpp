#include <GL/glew.h>
#include <GL/freeglut.h>
#include <volren/volren.hpp>

std::string path = "../prj.cw/data/engine256x256x128.raw";
std::string title = "volren";


int main(int argc, char* argv[])
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(512, 512);

	glutCreateWindow(title.c_str());
	glutPositionWindow(256, 256);

	glutDisplayFunc(&render);
	glutReshapeFunc(&resize);
	glutKeyboardFunc(&keyboard);
	glutMotionFunc(&mouseDrag);
	glutMouseFunc(&mouseClick);

	glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
	glewInit();

	bool loadSuccess = false;
	loadSuccess = initTexturesRaw(path);

	if (!loadSuccess)
	{
		fprintf(stderr, "Failed to initialise textures\nCheck DATAFILE path");
	}

	glutMainLoop();
	fprintf(stdout, "Window closed\n");
	return 0;
}
