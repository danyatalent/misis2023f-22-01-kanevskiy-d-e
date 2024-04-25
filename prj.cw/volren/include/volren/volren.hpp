/**
* @file volren.hpp
* 
* Интерфейс библиотеки для Volume Rendering
* 
*/

#ifndef VOLUME_RENDER_HPP
#define VOLUME_RENDER_HPP

#include <string>
#include <GL/freeglut.h>
/**
* @brief Пространство имен, содержащее функции библиотеки
*/
namespace volRen {
	/**
	* @brief Callback функция рендера для glutDisplayFunc
	*/
	void render();

	/**
	* @brief Callback функция изменения размера для glutReshapeFunc
	* @param width - ширина слоя
	* @param height - высота слоя
	*/
	void resize(int width, int height);

	/**
	* @brief Callback функция обработки ввода с клавиатуры для glutKeyboardFunc
	*
	* Позволяет управлять камерой с помощью клавиш W-A-S-D,
	* а также возвращать камеру в изначальное положение с помощью backspace
	*
	* @param key - нажатая клавиша
	* @param x - координата x положения мыши во время нажатия на клавишу
	* @param y - координата y положения мыши во время нажатия на клавишу
	*/
	void keyboard(unsigned char key, int x, int y);

	/**
	* @brief Callback функция для обработки мыши для glutMouseFunc
	* @param button - нажатая клавиша мыши
	* @param state - статус клавиши мыши(GLUT_UP или GLUT_DOWN)
	* @param x - координата x положения мыши во время нажатия
	* @param y - координата y положения мыши во время нажатия
	*/
	void mouseClick(int button, int state, int x, int y);

	/**
	* @brief Callback функция для изменения камеры с помощью мыши для glutMotionFunc
	* @param x - координата x положения мыши во время нажатия
	* @param y - координата y положения мыши во время нажатия
	*/
	void mouseDrag(int x, int y);

	/**
	* @brief Считывание и создание 3d текстуры из raw файла
	* @param filename - относительный путь к файлу
	* @return status - статус считывания файла
	*/
	bool initTexturesRaw(std::string filename);

	/**
	* @brief отображение 3d текстуры для рендеринга, используется в функции render()
	* @param textureIndex - индекс текущей текстуры
	*/
	void map3DTexture(float textureIndex);
	
	/**
	* @brief Установка пользовательских размеров
	* @param width - ширина
	* @param height - высота
	* @param count - кол-во слоев
	*/
	void setSize(int width, int height, int count);

}
/**
* @brief Вспомогательный класс для корректного отображения объекта во время вращения
*/
class TransformationManager
{
public:
	/**
	* @brief Конструктор класса
	*/
	TransformationManager();

	/**
	* @brief Деструктор класса
	*/
	virtual ~TransformationManager() = default;

	/**
	* @brief Метод-геттер
	* @return mdRotation - текущее состояние матрицы
	*/
	const double* GetMatrix()
	{
		return mdRotation;
	}

	/**
	* @brief Метод, реализующий вращение изображения
	* @param fx_i - i-ая координата по x
	* @param fy_i - i-ая координата по y
	* @param fz_i - i-ая координата по z
	*/
	void Rotate(float fx_i, float fy_i, float fz_i);

	/**
	* @brief Метод, восстанавливающий изначальный вид матрицы
	*/
	void ResetRotation();

private:
	float mfRot[3]; /*mfRot - массив для осей*/
	double mdRotation[16] /*mdRotation - массив для ротации*/;
};

#endif