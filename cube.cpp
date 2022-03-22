#include<Windows.h>
#include <GLFW/glfw3.h>
#include <gl/GLU.h>

void redimensiona(int w, int h)
{
	glviewport(0, 0, w, h);

		float aspect = (float)w / (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45.0, aspect, 0.1, 500.0); //funcao openGL

     glMatrixMode(GL_MODELVIEW);
}
void rect(float p1[3], float p2[3], float p3[3], float p4[3]);
{
     glColor3fv(cor);
    glBegin(GL_QUADS);
    glVertex3fv(p1);
    glVertex3fv(p2);
    glVertex3fv(p3);
    glVertex3fv(p4);
    glEnd();
}

void desenhaCubo(float s)
{
	float d = s / 2.0;
	
	float v1[3] = { -d,  d, d};
	float v2[3] = { -d, -d, d};
	float v3[3] = {  d, -d, d};
	float v4[3] = {  d,  d, d};

	float v5[3] = {  d,  d, -d };
	float v6[3] = {  d, -d, -d };
	float v7[3] = { -d, -d, -d };
	float v8[3] = { -d,  d, -d };
	
	//frente
	rect(v1, v2, v3, v4, vermelho);

	//direita
	rect(v4, v3, v5, v6, azul);
	
    //back
	rect(v5, v8, v7, v6, amarelo);
   //esquerda
	rect(v1, v4, v5, v8, verde);
	//topo
	rect(v1, v4, v5, v8, laranja);
    //bottom
	rect(v2, v7, v6, v3, violeta);
	}
		

	void desenha()
	{
		glLoadIdentity();
		glTranslated(0.0, 0.0, -50.0);
		glRotated(30.0, 0.0, 1.0, 0.0);
		desenhaCubo(10);
	}
	
	//funcao para desenhar o terreno sob o qual estara o cubo
    void desenhaTerreno(unsigned int id){
    float L = 500.0;
    float incr = 1.0;
    float y = -0.5;
    glNewList(id, GL_COMPILE);
    glColor3fv(branco_gelo);
    glBegin(GL_LINES);
    for (float i = -L; i <= L; i += incr)
    {
    //verticais
    flVertex3f(i, y, -L);
    glVertex3f(i, y, L);
    //horizontais
    glVertex3f(-L, y, i);
    glVertex3f(L, y, i);
    } 
    glEnd();
    }

    
    //CATEI NA INTERNET
    
    void PosicUser()
{
    // Define os parâmetros da projeção Perspectiva
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    // Define o volume de visualização sempre a partir da posicao do
    // observador
    if (ModoDeProjecao == 0)
        glOrtho(-10, 10, -10, 10, 0, 20); // Projecao paralela Orthografica
    else gluPerspective(90,AspectRatio,0.01,200); // Projecao perspectiva

    // Define a posição do observador
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    gluLookAt(0, 0, 10,   // Posição do Observador
              0,0,0,      // Posição do Alvo
              0.0f,1.0f,0.0f); // Lado de cima da câmera
    }
    
    
    
int main(void)
{
    const int LARGURA = 800;
    const int ALTURA = 600;
    
    //inicia a biblioteca
    glfwInit();
    
    //cria a janela e o contexto opengl
    GLFWwindow* window = glfwCreateWindow(LARGURA, ALTURA, "Desenha Quadrado", NULL, NULL);
    
    //Faz o contexto da janela atual
    glfwMakeContextCurrent(window);
    
     //inicio
     glClearColor(0.0, 0.15, 0.25, 1.0); //cor de fundo
     glEnable(GL_DEPTH_TEST);
     
     glfwPollEvents();
     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
     {
          glfwSertWindowShouldClose(window, GLFW_TRUE);                                   
     }
     
     //loop até o usuario fechar a janela
          
     while(!glfwWindowShouldClose(window))
     {
         glfwPollEvents();
         if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
         {
            glfwSetWindowShouldClose(window, GLFW_TRUE);
         }
      //Renderizacao
      glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
      int largura, altura;
      glfwGetFramebufferSize(window, &largura, &altura);
      redimensiona(largura, altura);                            
     }
}

