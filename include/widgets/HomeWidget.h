#pragma once

#include <vector>
#include <memory>

#include <QtWidgets/QWidget>
#include <QtWidgets/QtWidgets>

namespace NEG
{

typedef std::function<void()> StartBtnCallback_t;

class HomeWidget : public QWidget
{
    Q_OBJECT

public:
    explicit HomeWidget(QWidget *parent = 0);
    virtual ~HomeWidget();

    void AddStartBtnCallback(StartBtnCallback_t cb);

private slots:
    void HandleStartBtnPress();

private:
    std::unique_ptr<QLabel> title_;
    std::unique_ptr<QPushButton> start_btn_;
    
    std::unique_ptr<QGridLayout> layout_;

    std::vector<StartBtnCallback_t> start_btn_callbacks_;
};
}