#pragma once

#include <vector>
#include <memory>

#include <QtWidgets/QWidget>
#include <QtWidgets/QStackedWidget>

#include "widgets/TextGuessWidget.h"
#include "widgets/HomeWidget.h"

namespace NEG
{

class MainWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MainWidget(size_t width, size_t height, QWidget *parent = 0);
    virtual ~MainWidget();

    void GoToQuestion(const QString& question);

    int AddWidget(std::shared_ptr<QWidget> widget);

private:
    std::unique_ptr<QStackedWidget> stacked_widget_;

    std::unique_ptr<TextGuessWidget> text_guess_widget_;
    std::unique_ptr<HomeWidget> home_widget_;

};
}