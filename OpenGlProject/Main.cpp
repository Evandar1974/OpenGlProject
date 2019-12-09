//import standard IO library
#include <stdio.h>
//import open gl libraries
#include<GL/glew.h>
#include<GLFW/glfw3.h>

//define constant windows size params using GLint
const GLint WIDTH = 800, HEIGHT = 600;

int Main()
{
	//initialise GLFW

	if (glfwInit())
	{
		printf("GLFW initialisation has failed!");
		glfwTerminate();
		return 1;
	}

	//set glfw windows properties
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	//core profile no back compatability
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	//Allow forward compatability
	glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
	//create open gl window
	GLFWwindow* mainWindow = glfwCreateWindow(WIDTH, HEIGHT, "Test Window", NULL, NULL);
	if (!mainWindow)
	{
		printf("GLFW window creation failed!");
		glfwTerminate();
		return 1;
	}

	// get buffer size window
	int bufferWidth, bufferHeight;
	glfwGetFramebufferSize(mainWindow, &bufferWidth, &bufferHeight);

	//set context for GLEW to use
	glfwMakeContextCurrent(mainWindow);

	//allow modern extension features
	glewExperimental = GL_TRUE;

	if (!glewInit())
	{
		printf("GLEW Initialisation failed!");
	}
	return 0;
}
