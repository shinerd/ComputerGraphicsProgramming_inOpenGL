#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
using namespace glm;

class Transform
{
public:
    Transform();
    static mat4 buildTranslate(float x, float y, float z);
    static mat4 buildRotateX(float rad);
    static mat4 buildRotateY(float rad);
    static mat4 buildRotateZ(float rad);
    static mat4 buildScale(float x, float y, float z);
    
};
