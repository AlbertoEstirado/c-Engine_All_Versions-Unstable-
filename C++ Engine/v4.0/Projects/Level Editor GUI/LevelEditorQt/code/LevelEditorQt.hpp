#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_LevelEditorQt.h"
#include <LevelEditor/editor_controller.hpp>
#include <LevelEditor/scene.hpp>
#include <QDebug>


class LevelEditorQt : public QMainWindow
{
    Q_OBJECT

public:
    LevelEditorQt(QWidget *parent = Q_NULLPTR);

    level_editor::Editor_Controller* editor = nullptr;
    level_editor::Scene* scene = nullptr;

private slots:

    void Add_Entity()
    {
        editor->add_entity(ui.Add_EntityName_field->text().toStdString());
        Update_SceneEntities();
    }

    void Update_SceneEntities()
    {        
        ui.current_entities_text->setText(QString::fromUtf8(editor->get_entities().c_str()));
    }

    void Create_New_Scene()
    {
        std::string scene_name = ui.SceneName_Field->text().toStdString();
        scene = new level_editor::Scene(scene_name.c_str(), "");
        editor = new level_editor::Editor_Controller(*scene);
        ui.Current_Scene_Label->setText(QString::fromUtf8(editor->scene.name.c_str()));
    }

    void Save_Scene()
    {
        editor->scene.name = ui.SceneName_Field->text().toStdString();
        editor->parse_scene();
    }

    void Load_Entity()
    {
        std::string entity = ui.EntityName_Field->text().toStdString();
        ui.current_components_text->setText(QString::fromUtf8(editor->get_components(entity).c_str()));
    }

    void Set_Transform_Values()
    {
        std::string entity = ui.EntityName_Field->text().toStdString();
        float pos[3];
        float rot[3];
        float sca[3];
        pos[0] = ui.x_pox_Field->text().toFloat();
        pos[1] = ui.y_pos_Field->text().toFloat();
        pos[2] = ui.z_pos_Field->text().toFloat();

        rot[0] = ui.x_rot_Field->text().toFloat();
        rot[1] = ui.y_rot_Field->text().toFloat();
        rot[2] = ui.z_rot_Field->text().toFloat();

        sca[0] = ui.x_sca_Field->text().toFloat();
        sca[1] = ui.y_sca_Field->text().toFloat();
        sca[2] = ui.z_sca_Field->text().toFloat();

        editor->set_pos_transform_values(entity, pos[0], pos[1], pos[2]);
        editor->set_rot_transform_values(entity, rot[0], rot[1], rot[2]);
        editor->set_sca_transform_values(entity, sca[0], sca[1], sca[2]);
        Load_Entity();
    }

    void Add_Camera_Component()
    {
        std::string entity = ui.EntityName_Field->text().toStdString();
        editor->get_entity_add_component(entity, new level_editor::Camera_Component(20.f, 1.f, 50.f, 1.f));
        Load_Entity();
    }

    void Add_Mesh_Component()
    {
        std::string entity = ui.EntityName_Field->text().toStdString();
        editor->get_entity_add_component(entity, new level_editor::Mesh_Component(ui.mesh_paht_Field->text().toStdString()));
        Load_Entity();
    }

    void Add_Light_Component()
    {
        std::string entity = ui.EntityName_Field->text().toStdString();
        editor->get_entity_add_component(entity, new level_editor::Light_Component(ui.light_intensity_Field->text().toFloat()));
        Load_Entity();
    }

private:
    Ui::LevelEditorQtClass ui;
};
