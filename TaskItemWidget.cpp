#include "TaskItemWidget.h"
#include <QHBoxLayout>
#include <QLabel>
#include <QCheckBox>

TaskItemWidget::TaskItemWidget(const std::string& name, const bool complated, QWidget* parent)
    : QWidget(parent),
    m_complatedCheckbox(new QCheckBox()),
    m_nameLabel(new QLabel(QString::fromStdString(name)))
{
    m_complatedCheckbox->setAttribute(Qt::WA_TransparentForMouseEvents);
    m_complatedCheckbox->setChecked(complated);


    QHBoxLayout* mainLayout = new QHBoxLayout;
    setLayout(mainLayout);
    mainLayout->addWidget(m_complatedCheckbox);
    mainLayout->addWidget(m_nameLabel);
    mainLayout->setAlignment(Qt::AlignLeft);
}
