attribute vec3 a_vertex;
attribute vec3 a_normal;
attribute vec2 a_uv;

//this will store the color for the pixel shader
varying vec3 v_position;
varying vec3 v_world_position;
varying vec3 v_normal;
varying vec2 v_uv;
varying vec4 v_color;

void main()
{
    v_uv = a_uv;

    //el vertice lo pasamos tal cual
    gl_Position = vec4(a_vertex,1.0);
}