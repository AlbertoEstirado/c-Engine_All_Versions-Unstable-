/**
*
* @author Alberto Estirado López
*
* Distributed under the Boost Software License, version  1.0
* See documents/LICENSE.TXT or www.boost.org/LICENSE_1_0.txt
*
* @date 26/01/2022
*
* estiradoalberto@gmail.com
*/


#include "LevelEditorQt.hpp"

LevelEditorQt::LevelEditorQt(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);

    connect(ui.AddEntity_Button,        SIGNAL(clicked()),   this, SLOT(Add_Entity()));
    connect(ui.actionCreate_new_scene,  SIGNAL(triggered()), this, SLOT(Create_New_Scene()));
    connect(ui.actionSave_scene,        SIGNAL(triggered()), this, SLOT(Save_Scene()));

    connect(ui.Load_Entity_Button,      SIGNAL(clicked()),      this, SLOT(Load_Entity()));
    connect(ui.set_transform_Button,    SIGNAL(clicked()),      this, SLOT(Set_Transform_Values()));
    connect(ui.Camera_Button,           SIGNAL(clicked()),      this, SLOT(Add_Camera_Component()));
    connect(ui.Mesh_Button,             SIGNAL(clicked()),      this, SLOT(Add_Mesh_Component()));
    connect(ui.Ligt_Button,             SIGNAL(clicked()),      this, SLOT(Add_Light_Component()));
}