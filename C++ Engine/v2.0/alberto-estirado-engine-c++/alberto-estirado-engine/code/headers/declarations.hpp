// This is free code released into the public domain.
// Drafted by Ángel in January 2019.
// angel.rodriguez@esne.edu

#pragma once

// Se crean declaraciones adelantadas de algunos identificadores de librerías externas
// que se usan en las cabeceras del engine para que en los proyectos en los que se
// incluyan éstas no sea necesario añadir las cabeceras de las librerías externas.

///////////////////////////////////////// SDL /////////////////////////////////////////

typedef struct SDL_Window   SDL_Window;
typedef void* SDL_GLContext;

/////////////////////////////////// OPENGL TOOLKIT ////////////////////////////////////

namespace glt
{

    class Render_Node;

}