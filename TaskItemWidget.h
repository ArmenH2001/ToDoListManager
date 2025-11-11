#pragma once

#include <QWidget>
class QCheckBox;
class QLabel;

class TaskItemWidget : public QWidget
{
    Q_OBJECT
public:
    explicit TaskItemWidget(const std::string& name, const bool complated, QWidget* parent = nullptr);
private:
    QCheckBox* m_complatedCheckbox;
    QLabel* m_nameLabel;
};

