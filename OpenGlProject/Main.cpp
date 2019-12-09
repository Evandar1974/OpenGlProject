//import standard IO library
#include <stdio.h>
//import open gl libraries
#include<GL/glew.h>
#include<GLFW/glfw3.h>

//define constant windows size params using GLint
const GLint WIDTH = 800, HEIGHT = 600;

int main()
{
	//initialise GLFW

	if (!glfwInit())
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

	if (glewInit() != GLEW_OK)
	{
		printf("GLEW Initialisation failed!");
		glfwDestroyWindow(mainWindow);
		glfwTerminate();
	}
	//set viewport size
	glViewport(0,0,bufferWidth,bufferHeight);

	//loop till window closed

	while (!glfwWindowShouldClose(mainWindow))
	{
		//get user actions
		glfwPollEvents();

		//clear window
		glClearColor(1.0f,0.0f,0.0f,1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		//swap buffers
		glfwSwapBuffers(mainWindow);

	}

	return 0;
}
