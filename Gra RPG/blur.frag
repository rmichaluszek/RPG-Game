uniform sampler2D texture;
uniform vec2 blur_radius;

void main()
{
vec2 offx = blur_radius;
vec2 offy = blur_radius;

vec4 pixel = texture2D(texture, gl_TexCoord[0].xy)  * 100 +
texture2D(texture, gl_TexCoord[0].xy - offx)        * 90.0 +
texture2D(texture, gl_TexCoord[0].xy + offx)        * 90.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*2)        * 80.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*2)        * 80.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*3)        * 70.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*3)        * 70.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*4)        * 60.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*4)        * 60.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*5)        * 50.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*5)        * 50.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*6)        * 40.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*6)        * 40.0 +
texture2D(texture, gl_TexCoord[0].xy - offx)        * 30.0 +
texture2D(texture, gl_TexCoord[0].xy + offx)        * 30.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*2)        * 20.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*2)        * 20.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*3)        * 10.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*3)        * 10.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*4)        * 6.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*4)        * 6.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*5)        * 4.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*5)        * 4.0 +
texture2D(texture, gl_TexCoord[0].xy - offx*6)        * 2.0 +
texture2D(texture, gl_TexCoord[0].xy + offx*6)        * 2.0;

gl_FragColor =  gl_Color * (pixel / 1024.0);
}