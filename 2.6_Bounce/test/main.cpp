


#include <GLTools.h>
#include <GLShaderManager.h>
#ifdef __APPLE__
#include <glut/glut.h>
#else
#define FREEGLUT_STATIC
#include <GL/glut.h>
#endif

GLBatch squareBatch;
GLShaderManager shaderManager;

GLfloat blockSize = 0.2f;
GLfloat vVerts[] = {-blockSize, -blockSize, 0.0f,
    blockSize, -blockSize, 0.0f,
    blockSize, blockSize, 0.0f,
    -blockSize, blockSize, 0.0f};

void ChangeSize(int w, int h)
{
    glViewport(0, 0, w, h);
}

void SetupRC()
{
    glClearColor(0.25f, 0.25f, 0.25f, 1.0f);
    shaderManager.InitializeStockShaders();
    squareBatch.Begin(GL_TRIANGLE_FAN, 4);
    squareBatch.CopyVertexData3f(vVerts);
    squareBatch.End();
}
//键盘移动
void SpecialKeys(int key, int x, int y)
{
    GLfloat stepSize = 0.025f;

    GLfloat blockX = vVerts[0];
    GLfloat blockY = vVerts[7];

    if (key == GLUT_KEY_UP)
    {
        blockY += stepSize;
    }
    if (key == GLUT_KEY_DOWN)
    {
        blockY -= stepSize;
    }
    if (key == GLUT_KEY_RIGHT)
    {
        blockX += stepSize;
    }
    if (key == GLUT_KEY_LEFT)
    {
        blockX -= stepSize;
    }
    //collision detection
    if (blockX < -1.0f)
    {
        blockX = -1.0f;
    }
    if (blockX > (1.0f - blockSize * 2))
    {
        blockX = 1.0f - blockSize * 2;
    }
    if (blockY < -1.0f + blockSize * 2)
    {
        blockY = -1.0f + blockSize * 2;
    }
    if (blockY > 1.0f)
    {
        blockY = 1.0f;
    }

    vVerts[0] = blockX;
    vVerts[1] = blockY - 2 * blockSize;

    vVerts[3] = blockX + 2 * blockSize;
    vVerts[4] = blockY - 2 * blockSize;

    vVerts[6] = blockX + 2 * blockSize;
    vVerts[7] = blockY;

    vVerts[9] = blockX;
    vVerts[10] = blockY;

    squareBatch.CopyVertexData3f(vVerts);
    //请求重绘
    glutPostRedisplay();
}

//对角线移动绘制
void BounceFunction(void)
{
    static GLfloat xDir = 1.0f;
    static GLfloat yDir = 1.0f;

    GLfloat stepSize = 0.0005f;

    GLfloat blockX = vVerts[0];   // Upper left X
    GLfloat blockY = vVerts[7];  // Upper left Y

    //所以一直对角线移动
    blockY += stepSize * yDir;
    blockX += stepSize * xDir;

    // Collision detection
    if(blockX < -1.0f) { blockX = -1.0f; xDir *= -1.0f; }
    if(blockX > (1.0f - blockSize * 2)) { blockX = 1.0f - blockSize * 2; xDir *= -1.0f; }
    if(blockY < -1.0f + blockSize * 2)  { blockY = -1.0f + blockSize * 2; yDir *= -1.0f; }
    if(blockY > 1.0f) { blockY = 1.0f; yDir *= -1.0f; }

    // Recalculate vertex positions
    vVerts[0] = blockX;
    vVerts[1] = blockY - blockSize*2;

    vVerts[3] = blockX + blockSize*2;
    vVerts[4] = blockY - blockSize*2;

    vVerts[6] = blockX + blockSize*2;
    vVerts[7] = blockY;

    vVerts[9] = blockX;
    vVerts[10] = blockY;

    squareBatch.CopyVertexData3f(vVerts);
}



void RenderScene()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT | GL_STENCIL_BUFFER_BIT);
    GLfloat vRed[] = {0.98f, 0.04f, 0.7f, 1.0f};
    shaderManager.UseStockShader(GLT_SHADER_IDENTITY, vRed);
    squareBatch.Draw();
    glutSwapBuffers();
    BounceFunction();
    glutPostRedisplay();

}

int main(int argc, char* argv[])
{
    gltSetWorkingDirectory(argv[0]);
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH | GLUT_STENCIL);
    glutInitWindowSize(800, 600);

    glutCreateWindow("Move");

    GLenum err = glewInit();
    if (GLEW_OK != err)
    {
        fprintf(stderr, "GLEW Error: %s\n", glewGetErrorString(err));
        return 1;
    }
    
    glutReshapeFunc(ChangeSize);
    glutDisplayFunc(RenderScene);
    glutSpecialFunc(SpecialKeys);
    SetupRC();
    glutMainLoop();
    return 0;
}
